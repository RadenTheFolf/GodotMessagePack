# GodotMessagePack
Message pack extention for godot without boost libs

This extention supprts serializing all serializable Godot types utilizing the Variant type
|Supported Types| | | |
|---|---|---|---|
| Int | Vector4 |  AABB | PackedStringArray |
| Bool | Vector4i | Color | PackedVector2Array |
| Float | Rect2 |  Object | PackedVector3Array |
| String | Rect2i |  Dictionary | PackedColorArray |
| StringName | Transform2D | Array | |
| NodePath | Transform3D |  PackedByteArray | |
| Vector2 | Plane | PackedInt32Array | |
| Vector2i | Projection | PackedInt64Array | |
| Vector3 | Quaternion | PackedFloat32Array | |
| Vector3i | Basis | PackedFloat64Array | |

The extention exposes on class containing 2 functions
- GDMessagePack
  - PackedByteArray pack( Variant )
  - Variant unpack( PackedByteArray )

## Usage Example
```py
var str = "Hello world!"
var msgpk =  GDMessagePack.new()

var pba = msgpk.pack(str)
print(pba)

var unpacked_str = msgpk.unpack(pba)
print(unpacked_str)
```

