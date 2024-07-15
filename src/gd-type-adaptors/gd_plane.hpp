//
// Created by raden on 7/13/2024.
//

#ifndef GDMSGPK_GD_PLANE_HPP
#define GDMSGPK_GD_PLANE_HPP



#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "gd_vec3.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::Plane> {
        msgpack::object const& operator()(msgpack::object const& o, godot::Plane& v) const {
            if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
            if (o.via.array.size != 2) throw msgpack::type_error();
            v = godot::Plane(
                    o.via.array.ptr[0].as<godot::Vector3>(),
                    o.via.array.ptr[1].as<real_t>());
            return o;
        }
    };
    template <>
    struct pack<godot::Plane> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::Plane const& v) const {
            o.pack_array(2);
            o.pack(v.normal);
            o.pack(v.d);
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::Plane> {
        void operator()(msgpack::object::with_zone& o, godot::Plane const& v) const {
            o.type = type::ARRAY;
            o.via.array.size = 2;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            o.via.array.ptr[0] = msgpack::object(v.normal, o.zone);
            o.via.array.ptr[1] = msgpack::object(v.d, o.zone);
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_PLANE_HPP
