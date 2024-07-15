//
// Created by raden on 7/12/2024.
//

#ifndef GDMSGPK_GD_VEC2_HPP
#define GDMSGPK_GD_VEC2_HPP

#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::Vector2> {
        msgpack::object const& operator()(msgpack::object const& o, godot::Vector2& v) const {
            if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
            if (o.via.array.size != 2) throw msgpack::type_error();
            v = godot::Vector2(
                    o.via.array.ptr[0].as<real_t>(),
                    o.via.array.ptr[1].as<real_t>());
            return o;
        }
    };

    template <>
    struct pack<godot::Vector2> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::Vector2 const& v) const {
            o.pack_array(2);
            o.pack(v.x);
            o.pack(v.y);
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::Vector2> {
        void operator()(msgpack::object::with_zone& o, godot::Vector2 const& v) const {
            o.type = type::ARRAY;
            o.via.array.size = 2;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            o.via.array.ptr[0] = msgpack::object(v.x, o.zone);
            o.via.array.ptr[1] = msgpack::object(v.y, o.zone);
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_VEC2_HPP
