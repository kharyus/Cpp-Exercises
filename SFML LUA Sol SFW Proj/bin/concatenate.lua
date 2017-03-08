function concatenate(str)
	return str .. " world"
end

function add(x, y)
	return x + y
end

function metsu()
	print("messatsu")
end

function test()
	print("test")
end

function shinkuu()
    print("Hadouken")
end

function qwe()
	print("qwe")
end

function banana()
	print("Apple is better tho")
end

player = {
	x = 0,
	y = 0,
	hp = 50,
	
	setHp = function(_hp)
		player.hp = _hp
	end
}
