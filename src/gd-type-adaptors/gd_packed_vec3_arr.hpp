//
// Created by raden on 7/14/2024.
//

#ifndef GDMSGPK_GD_PACKED_VEC3_ARR_HPP
#define GDMSGPK_GD_PACKED_VEC3_ARR_HPP



#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "gd_vec3.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::PackedVector3Array> {
        msgpack::object const& operator()(msgpack::object const& o, godot::PackedVector3Array& v) const {
            if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
            for (int i = 0; i < o.via.array.size; i++) {
                v.push_back(o.via.array.ptr[i].as<godot::Vector3>());
            }
            return o;
        }
    };
    template <>
    struct pack<godot::PackedVector3Array> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::PackedVector3Array const& v) const {
            o.pack_array(v.size());
            for (godot::Vector3 i : v) {
                o.pack(i);
            }
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::PackedVector3Array> {
        void operator()(msgpack::object::with_zone& o, godot::PackedVector3Array const& v) const {
            o.type = type::ARRAY;
            o.via.array.size = v.size();
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            for (int i = 0; i < v.size(); i++) {
                o.via.array.ptr[i] = msgpack::object(v[i], o.zone);
            }
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_PACKED_VEC3_ARR_HPP
