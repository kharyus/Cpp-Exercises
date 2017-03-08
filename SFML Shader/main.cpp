#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    /////////////////////
    // Initialize SFML //
    /////////////////////

    // Create window
    sf::RenderWindow window(sf::VideoMode(800,600), "Sandbox");
    // Sets 60 fps
    window.setFramerateLimit(60);
    // V-sync
    window.setVerticalSyncEnabled(false);

    sf::Font font;
    font.loadFromFile("CardboardCat-Regular.otf");
    sf::Text text("Hello World", font);

    sf::Texture texture;
    texture.loadFromFile("sheet.png");
    sf::Sprite sprite(texture);

    sf::Shader shader;
    shader.loadFromMemory(R"(uniform sampler2D texture;
uniform float edge_threshold;

void main()
{
    const float offset = 1.0 / 512.0;
    vec2 offx = vec2(offset, 0.0);
    vec2 offy = vec2(0.0, offset);

    vec4 hEdge = texture2D(texture, gl_TexCoord[0].xy - offy)        * -2.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offy)        *  2.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx - offy) * -1.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx + offy) *  1.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx - offy) * -1.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx + offy) *  1.0;

    vec4 vEdge = texture2D(texture, gl_TexCoord[0].xy - offx)        *  2.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx)        * -2.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx - offy) *  1.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx + offy) * -1.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx - offy) *  1.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx + offy) * -1.0;

    vec3 result = sqrt(hEdge.rgb * hEdge.rgb + vEdge.rgb * vEdge.rgb);
    float edge = length(result);
    vec4 pixel = gl_Color * texture2D(texture, gl_TexCoord[0].xy);
    if (edge > (edge_threshold * 8.0))
        pixel.rgb = vec3(0.0, 0.0, 0.0);
    else
        pixel.a = edge_threshold;
    gl_FragColor = pixel;
})", sf::Shader::Fragment);
    shader.setUniform("texture", sf::Shader::CurrentTexture);
    //sf::Shader::bind(&shader);

    float f = 0;
    float direction = 0.01;

    // Window main loop
    while (window.isOpen())
    {
        // Iterate through all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear frame
        window.clear();

        // Draw entities
        //window.draw(text, &shader);
        f += direction;
        if (f >= 1.00 || f <= 0.00)
            direction *= -1;

        shader.setUniform("edge_threshold", f);
        window.draw(sprite, &shader);
        //window.draw(sprite);

        // Display Frame
        window.display();
    }

    // Exit program succesfully
    return 0;
}
