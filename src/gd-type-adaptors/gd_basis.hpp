//
// Created by raden on 7/13/2024.
//

#ifndef GDMSGPK_GD_BASIS_HPP
#define GDMSGPK_GD_BASIS_HPP



#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "gd_vec3.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::Basis> {
        msgpack::object const& operator()(msgpack::object const& o, godot::Basis& v) const {
            v = godot::Basis(
                    o.via.array.ptr[0].as<godot::Vector3>(),
                    o.via.array.ptr[1].as<godot::Vector3>(),
                    o.via.array.ptr[2].as<godot::Vector3>());
            return o;
        }
    };
    template <>
    struct pack<godot::Basis> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::Basis const& v) const {
            o.pack_array(3);
            o.pack(v.rows[0]);
            o.pack(v.rows[1]);
            o.pack(v.rows[2]);
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::Basis> {
        void operator()(msgpack::object::with_zone& o, godot::Basis const& v) const {
            o.type = type::ARRAY;
            o.via.array.size = 3;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            o.via.array.ptr[0] = msgpack::object(v.rows[0], o.zone);
            o.via.array.ptr[1] = msgpack::object(v.rows[1], o.zone);
            o.via.array.ptr[2] = msgpack::object(v.rows[2], o.zone);
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_BASIS_HPP
