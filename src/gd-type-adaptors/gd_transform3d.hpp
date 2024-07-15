//
// Created by raden on 7/13/2024.
//

#ifndef GDMSGPK_GD_TRANSFORM3D_HPP
#define GDMSGPK_GD_TRANSFORM3D_HPP



#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "gd_vec3.hpp"
#include "gd_basis.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::Transform3D> {
        msgpack::object const& operator()(msgpack::object const& o, godot::Transform3D& v) const {
            if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
            if (o.via.array.size != 2) throw msgpack::type_error();
            v = godot::Transform3D(
                    o.via.array.ptr[0].as<godot::Basis>(),
                    o.via.array.ptr[1].as<godot::Vector3>());
            return o;
        }
    };
    template <>
    struct pack<godot::Transform3D> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::Transform3D const& v) const {
            o.pack_array(2);
            o.pack(v.basis);
            o.pack(v.origin);
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::Transform3D> {
        void operator()(msgpack::object::with_zone& o, godot::Transform3D const& v) const {
            o.type = type::ARRAY;
            o.via.array.size = 2;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            o.via.array.ptr[0] = msgpack::object(v.basis, o.zone);
            o.via.array.ptr[1] = msgpack::object(v.origin, o.zone);
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_TRANSFORM3D_HPP
