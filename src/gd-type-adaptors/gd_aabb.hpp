//
// Created by raden on 7/14/2024.
//

#ifndef GDMSGPK_GD_AABB_HPP
#define GDMSGPK_GD_AABB_HPP



#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "gd_vec3.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::AABB> {
        msgpack::object const& operator()(msgpack::object const& o, godot::AABB& v) const {
            if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
            if (o.via.array.size != 2) throw msgpack::type_error();
            v = godot::AABB(
                    o.via.array.ptr[0].as<godot::Vector3>(),
                    o.via.array.ptr[1].as<godot::Vector3>());
            return o;
        }
    };
    template <>
    struct pack<godot::AABB> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::AABB const& v) const {
            o.pack_array(2);
            o.pack(v.position);
            o.pack(v.size);
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::AABB> {
        void operator()(msgpack::object::with_zone& o, godot::AABB const& v) const {
            o.type = type::ARRAY;
            o.via.array.size = 2;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            o.via.array.ptr[0] = msgpack::object(v.position, o.zone);
            o.via.array.ptr[1] = msgpack::object(v.size, o.zone);
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_AABB_HPP
