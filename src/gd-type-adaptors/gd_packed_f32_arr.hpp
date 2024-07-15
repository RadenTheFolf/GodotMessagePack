//
// Created by raden on 7/14/2024.
//

#ifndef GDMSGPK_GD_PACKED_F32_ARR_HPP
#define GDMSGPK_GD_PACKED_F32_ARR_HPP



#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "gd_packed_byte_arr.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::PackedFloat32Array> {
        msgpack::object const& operator()(msgpack::object const& o, godot::PackedFloat32Array& v) const {
            if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
            if (o.via.array.size != 1) throw msgpack::type_error();
            v  = o.via.array.ptr[0].as<godot::PackedByteArray>().to_float32_array();
            return o;
        }
    };
    template <>
    struct pack<godot::PackedFloat32Array> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::PackedFloat32Array const& v) const {
            o.pack_array(1);
            o.pack(v.to_byte_array());
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::PackedFloat32Array> {
        void operator()(msgpack::object::with_zone& o, godot::PackedFloat32Array const& v) const {
            o.type = type::ARRAY;
            o.via.array.size = 1;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            o.via.array.ptr[0] = msgpack::object(v.to_byte_array(), o.zone);
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_PACKED_F32_ARR_HPP
