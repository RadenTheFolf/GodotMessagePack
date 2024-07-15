extends Node2D


# Called when the node enters the scene tree for the first time.
func _ready():
	var msgpk = GDMessagePack.new()
	var np = PackedInt32Array([1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99,111,222,333,444,555,666,777,888,999])
	var s = msgpk.pack(np)
	var st = msgpk.unpack(s)
	print(s)
	print(st)
	print(np.to_byte_array())
	
	pass
# [145, 220, 0, 24, 0, 0, 0, 63, 0, 0, 204, 128, 63, 0, 0, 204, 192, 63, 0, 0, 0, 64, 0, 0, 32, 64, 0, 0, 64, 64]
# [145, 196, 24, 0, 0, 0, 63, 0, 0, 128, 63, 0, 0, 192, 63, 0, 0, 0, 64, 0, 0, 32, 64, 0, 0, 64, 64]

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
