//
// Created by raden on 7/14/2024.
//

#ifndef GDMSGPK_GD_VAR_HPP
#define GDMSGPK_GD_VAR_HPP



#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/variant/utility_functions.hpp"
#include "gd_adaptors.h"
#include "adaptor_utils.hpp"

#include "msgpack.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::Variant> {
        msgpack::object const& operator()(msgpack::object const& o, godot::Variant& v) const {
            if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
            if (o.via.array.size != 2) throw msgpack::type_error();
            uint8_t type = o.via.array.ptr[0].as<uint8_t>();
            switch (type) {
                case godot::Variant::Type::BOOL:
                    v = godot::Variant(o.via.array.ptr[1].as<bool>());
                    break;
                case godot::Variant::Type::INT:
                    v = godot::Variant(o.via.array.ptr[1].as<int64_t >());
                    break;
                case godot::Variant::Type::FLOAT:
                    v = godot::Variant(o.via.array.ptr[1].as<double_t >());
                    break;
                case godot::Variant::Type::STRING:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::String>());
                    break;
                case godot::Variant::Type::NODE_PATH:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::NodePath>());
                    break;
                case godot::Variant::Type::STRING_NAME:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::StringName>());
                    break;
                case godot::Variant::Type::VECTOR2:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Vector2>());
                    break;
                case godot::Variant::Type::VECTOR2I:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Vector2i>());
                    break;
                case godot::Variant::Type::VECTOR3:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Vector3>());
                    break;
                case godot::Variant::Type::VECTOR3I:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Vector3i>());
                    break;
                case godot::Variant::Type::VECTOR4:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Vector4>());
                    break;
                case godot::Variant::Type::VECTOR4I:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Vector4i>());
                    break;
                case godot::Variant::Type::QUATERNION:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Quaternion>());
                    break;
                case godot::Variant::Type::RECT2:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Rect2>());
                    break;
                case godot::Variant::Type::RECT2I:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Rect2i>());
                    break;
                case godot::Variant::Type::TRANSFORM2D:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Transform2D>());
                    break;
                case godot::Variant::Type::TRANSFORM3D:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Transform3D>());
                    break;
                case godot::Variant::Type::PLANE:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Plane>());
                    break;
                case godot::Variant::Type::AABB:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::AABB>());
                    break;
                case godot::Variant::Type::BASIS:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Basis>());
                    break;
                case godot::Variant::Type::COLOR:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Color>());
                    break;
                case godot::Variant::Type::PROJECTION:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Projection>());
                    break;
                case godot::Variant::Type::PACKED_BYTE_ARRAY:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::PackedByteArray>());
                    break;
                case godot::Variant::Type::PACKED_INT32_ARRAY:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::PackedInt32Array>());
                    break;
                case godot::Variant::Type::PACKED_INT64_ARRAY:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::PackedInt64Array>());
                    break;
                case godot::Variant::Type::PACKED_FLOAT32_ARRAY:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::PackedFloat32Array>());
                    break;
                case godot::Variant::Type::PACKED_FLOAT64_ARRAY:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::PackedFloat64Array>());
                    break;
                case godot::Variant::Type::PACKED_STRING_ARRAY:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::PackedStringArray>());
                    break;
                case godot::Variant::Type::PACKED_VECTOR2_ARRAY:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::PackedVector2Array>());
                    break;
                case godot::Variant::Type::PACKED_VECTOR3_ARRAY:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::PackedVector3Array>());
                    break;
                case godot::Variant::Type::PACKED_COLOR_ARRAY:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::PackedColorArray>());
                    break;
                case godot::Variant::Type::OBJECT:
                    v = godot::UtilityFunctions::bytes_to_var_with_objects(o.via.array.ptr[1].as<godot::PackedByteArray>());
                    break;
                case godot::Variant::Type::DICTIONARY:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Dictionary>());
                    break;
                    case godot::Variant::Type::ARRAY:
                    v = godot::Variant(o.via.array.ptr[1].as<godot::Array>());

                default:
                    v = godot::Variant();
            }
            return o;
        }
    };
    template <>
    struct pack<godot::Variant> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::Variant const& v) const {
            o.pack_array(2);
            o.pack((int)v.get_type());
            switch (v.get_type()) {
                case godot::Variant::Type::NIL:
                    o.pack_nil();
                    break;
                case godot::Variant::Type::BOOL:
                    o.pack(v.operator bool());
                    break;
                case godot::Variant::Type::INT:
                    o.pack(v.operator int64_t());
                    break;
                case godot::Variant::Type::FLOAT:
                    o.pack(v.operator double());
                    break;
                case godot::Variant::Type::STRING:
                    o.pack(v.operator godot::String());
                    break;
                case godot::Variant::Type::NODE_PATH:
                    o.pack(v.operator godot::NodePath());
                    break;
                case godot::Variant::Type::STRING_NAME:
                    o.pack(v.operator godot::StringName());
                    break;
                case godot::Variant::Type::VECTOR2:
                    o.pack(v.operator godot::Vector2());
                    break;
                case godot::Variant::Type::VECTOR2I:
                    o.pack(v.operator godot::Vector2i());
                    break;
                case godot::Variant::Type::VECTOR3:
                    o.pack(v.operator godot::Vector3());
                    break;
                case godot::Variant::Type::VECTOR3I:
                    o.pack(v.operator godot::Vector3i());
                    break;
                case godot::Variant::Type::VECTOR4:
                    o.pack(v.operator godot::Vector4());
                    break;
                case godot::Variant::Type::VECTOR4I:
                    o.pack(v.operator godot::Vector4i());
                    break;
                case godot::Variant::Type::QUATERNION:
                    o.pack(v.operator godot::Quaternion());
                    break;
                case godot::Variant::Type::RECT2:
                    o.pack(v.operator godot::Rect2());
                    break;
                case godot::Variant::Type::RECT2I:
                    o.pack(v.operator godot::Rect2i());
                    break;
                case godot::Variant::Type::TRANSFORM2D:
                    o.pack(v.operator godot::Transform2D());
                    break;
                case godot::Variant::Type::TRANSFORM3D:
                    o.pack(v.operator godot::Transform3D());
                    break;
                case godot::Variant::Type::PLANE:
                    o.pack(v.operator godot::Plane());
                    break;
                case godot::Variant::Type::AABB:
                    o.pack(v.operator godot::AABB());
                    break;
                case godot::Variant::Type::BASIS:
                    o.pack(v.operator godot::Basis());
                    break;
                case godot::Variant::Type::COLOR:
                    o.pack(v.operator godot::Color());
                    break;
                case godot::Variant::Type::PROJECTION:
                    o.pack(v.operator godot::Projection());
                    break;
                case godot::Variant::Type::PACKED_BYTE_ARRAY:
                    o.pack(v.operator godot::PackedByteArray());
                    break;
                case godot::Variant::Type::PACKED_INT32_ARRAY:
                    o.pack(v.operator godot::PackedInt32Array());
                    break;
                case godot::Variant::Type::PACKED_INT64_ARRAY:
                    o.pack(v.operator godot::PackedInt64Array());
                    break;
                case godot::Variant::Type::PACKED_FLOAT32_ARRAY:
                    o.pack(v.operator godot::PackedFloat32Array());
                    break;
                case godot::Variant::Type::PACKED_FLOAT64_ARRAY:
                    o.pack(v.operator godot::PackedFloat64Array());
                    break;
                case godot::Variant::Type::PACKED_STRING_ARRAY:
                    o.pack(v.operator godot::PackedStringArray());
                    break;
                case godot::Variant::Type::PACKED_VECTOR2_ARRAY:
                    o.pack(v.operator godot::PackedVector2Array());
                    break;
                case godot::Variant::Type::PACKED_VECTOR3_ARRAY:
                    o.pack(v.operator godot::PackedVector3Array());
                    break;
                case godot::Variant::Type::PACKED_COLOR_ARRAY:
                    o.pack(v.operator godot::PackedColorArray());
                    break;
                case godot::Variant::Type::OBJECT:
                    o.pack(godot::UtilityFunctions::var_to_bytes_with_objects(v));
                    break;
                case godot::Variant::Type::DICTIONARY:
                    o.pack(v.operator godot::Dictionary());
                    break;
                case godot::Variant::Type::ARRAY:
                    o.pack(v.operator godot::Array());
                    break;
                default:
                    o.pack_nil();
            }
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::Variant> {
        void operator()(msgpack::object::with_zone& o, godot::Variant const& v) const {
            o.type = type::ARRAY;
            o.via.array.size = 2;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            o.via.array.ptr[0] = msgpack::object((int)v.get_type(), o.zone);
            switch (v.get_type()) {
                case godot::Variant::Type::NIL:
                    o.via.array.ptr[1] = msgpack::object(godot::Variant(), o.zone);
                    break;
                case godot::Variant::Type::BOOL:
                    o.via.array.ptr[1] = msgpack::object(v.operator bool(), o.zone);
                    break;
                case godot::Variant::Type::INT:
                    o.via.array.ptr[1] = msgpack::object(v.operator int64_t(), o.zone);
                    break;
                case godot::Variant::Type::FLOAT:
                    o.via.array.ptr[1] = msgpack::object(v.operator double(), o.zone);
                    break;
                case godot::Variant::Type::STRING:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::String(), o.zone);
                    break;
                case godot::Variant::Type::NODE_PATH:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::NodePath(), o.zone);
                    break;
                case godot::Variant::Type::STRING_NAME:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::StringName(), o.zone);
                    break;
                case godot::Variant::Type::VECTOR2:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Vector2(), o.zone);
                    break;
                case godot::Variant::Type::VECTOR2I:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Vector2i(), o.zone);
                    break;
                case godot::Variant::Type::VECTOR3:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Vector3(), o.zone);
                    break;
                case godot::Variant::Type::VECTOR3I:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Vector3i(), o.zone);
                    break;
                case godot::Variant::Type::VECTOR4:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Vector4(), o.zone);
                    break;
                case godot::Variant::Type::VECTOR4I:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Vector4i(), o.zone);
                    break;
                case godot::Variant::Type::QUATERNION:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Quaternion(), o.zone);
                    break;
                case godot::Variant::Type::RECT2:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Rect2(), o.zone);
                    break;
                case godot::Variant::Type::RECT2I:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Rect2i(), o.zone);
                    break;
                case godot::Variant::Type::TRANSFORM2D:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Transform2D(), o.zone);
                    break;
                case godot::Variant::Type::TRANSFORM3D:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Transform3D(), o.zone);
                    break;
                case godot::Variant::Type::PLANE:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Plane(), o.zone);
                    break;
                case godot::Variant::Type::AABB:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::AABB(), o.zone);
                    break;
                case godot::Variant::Type::BASIS:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Basis(), o.zone);
                    break;
                case godot::Variant::Type::COLOR:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Color(), o.zone);
                    break;
                case godot::Variant::Type::PROJECTION:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Projection(), o.zone);
                    break;
                case godot::Variant::Type::PACKED_BYTE_ARRAY:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::PackedByteArray(), o.zone);
                    break;
                case godot::Variant::Type::PACKED_INT32_ARRAY:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::PackedInt32Array(), o.zone);
                    break;
                case godot::Variant::Type::PACKED_INT64_ARRAY:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::PackedInt64Array(), o.zone);
                    break;
                case godot::Variant::Type::PACKED_FLOAT32_ARRAY:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::PackedFloat32Array(), o.zone);
                    break;
                case godot::Variant::Type::PACKED_FLOAT64_ARRAY:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::PackedFloat64Array(), o.zone);
                    break;
                case godot::Variant::Type::PACKED_STRING_ARRAY:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::PackedStringArray(), o.zone);
                    break;
                case godot::Variant::Type::PACKED_VECTOR2_ARRAY:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::PackedVector2Array(), o.zone);
                    break;
                case godot::Variant::Type::PACKED_VECTOR3_ARRAY:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::PackedVector3Array(), o.zone);
                    break;
                case godot::Variant::Type::PACKED_COLOR_ARRAY:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::PackedColorArray(), o.zone);
                    break;
                case godot::Variant::Type::OBJECT:
                    o.via.array.ptr[1] = msgpack::object(godot::UtilityFunctions::var_to_bytes_with_objects(v), o.zone);
                    break;
                case godot::Variant::Type::DICTIONARY:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Dictionary(), o.zone);
                    break;
                case godot::Variant::Type::ARRAY:
                    o.via.array.ptr[1] = msgpack::object(v.operator godot::Array(), o.zone);
                    break;
                default:
                    o.via.array.ptr[1] = msgpack::object(msgpack::object(), o.zone);
            }
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_VAR_HPP
