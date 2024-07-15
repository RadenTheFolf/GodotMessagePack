//
// Created by raden on 7/13/2024.
//

#ifndef GDMSGPK_GD_TRANSFORM2D_HPP
#define GDMSGPK_GD_TRANSFORM2D_HPP



#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "gd_vec2.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::Transform2D> {
        msgpack::object const& operator()(msgpack::object const& o, godot::Transform2D& v) const {
            if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
            if (o.via.array.size != 3) throw msgpack::type_error();
            v = godot::Transform2D(
                    o.via.array.ptr[0].as<godot::Vector2>(),
                    o.via.array.ptr[1].as<godot::Vector2>(),
                    o.via.array.ptr[2].as<godot::Vector2>());
            return o;
        }
    };
    template <>
    struct pack<godot::Transform2D> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::Transform2D const& v) const {
            o.pack_array(3);
            o.pack(v.columns[0]);
            o.pack(v.columns[1]);
            o.pack(v.columns[2]);
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::Transform2D> {
        void operator()(msgpack::object::with_zone& o, godot::Transform2D const& v) const {
            o.type = type::ARRAY;
            o.via.array.size = 3;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            o.via.array.ptr[0] = msgpack::object(v.columns[0], o.zone);
            o.via.array.ptr[1] = msgpack::object(v.columns[1], o.zone);
            o.via.array.ptr[2] = msgpack::object(v.columns[2], o.zone);
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_TRANSFORM2D_HPP
