Collision = {
	x = 2,
	y = 0,
}

function Collision:new(obj)
	obj = obj or {}
	setmetatable(obj, self)
	self.__index = self
	return obj
end

function Collision:onCollision(x)
	print("My x: " .. self.x)
	print("Other x: " .. x)
end
