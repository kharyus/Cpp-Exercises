#include <Horde3D.h>
#include <Horde3DUtils.h>

H3DNode model = 0, cam = 0;

void initGame(int winWidth, int winHeight)
{
	// Initialize engine
	h3dInit();

	// Add pipeline resource
	H3DRes pipeRes = h3dAddResource(H3DResTypes::Pipeline, "standard.pipeline.xml", 0);
	// Add model resource
	H3DRes modelRes = h3dAddResource(H3DResTypes::SceneGraph, "character.scene.xml", 0);
	// Add animation resource
	H3DRes animRes = h3dAddResource(H3DResTypes::Animation, "walk.anim.xml", 0);
	// Load added resources
	h3dutLoadResourcesFromDisk("");

	// Add model to scene
	model = h3dAddNodes(H3DRootNode, modelRes);
	// Apply animation
	h3dSetupModelAnimStage(model, 0, animRes, 0, "", false);

	// Add light source
	H3DNode light = h3dAddLightNode(H3DRootNode, "Light1", 0, "LIGHTING", "SHADOWMAP");
	// Set light position and radius
	h3dSetNodeTransform(light, 0, 20, 0, 0, 0, 0, 1, 1, 1);
	h3dSetNodeParamF(light, H3DLight::RadiusF, 0, 50.0f);

	// Add camera
	H3DNode cam = h3dAddCameraNode(H3DRootNode, "Camera", pipeRes);

	// Setup viewport and render target sizes
	h3dSetNodeParamI(cam, H3DCamera::ViewportXI, 0);
	h3dSetNodeParamI(cam, H3DCamera::ViewportYI, 0);
	h3dSetNodeParamI(cam, H3DCamera::ViewportWidthI, winWidth);
	h3dSetNodeParamI(cam, H3DCamera::ViewportHeightI, winHeight);
	h3dSetupCameraView(cam, 45.0f, (float)winWidth / winHeight, 0.5f, 2048.0f);
	h3dResizePipelineBuffers(pipeRes, winWidth, winHeight);
}

void main()
{
	initGame(800, 600);
}