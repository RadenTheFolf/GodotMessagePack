//
// Created by raden on 7/12/2024.
//

#ifndef GDMSGPK_GD_VEC3I_HPP
#define GDMSGPK_GD_VEC3I_HPP



#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::Vector3i> {
        msgpack::object const& operator()(msgpack::object const& o, godot::Vector3i& v) const {
            if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
            if (o.via.array.size != 3) throw msgpack::type_error();
            v = godot::Vector3i(
                    o.via.array.ptr[0].as<int32_t>(),
                    o.via.array.ptr[1].as<int32_t>(),
                    o.via.array.ptr[2].as<int32_t>());
            return o;
        }
    };
    template <>
    struct pack<godot::Vector3i> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::Vector3i const& v) const {
            o.pack_array(3);
            o.pack(v.x);
            o.pack(v.y);
            o.pack(v.z);
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::Vector3i> {
        void operator()(msgpack::object::with_zone& o, godot::Vector3i const& v) const {
            o.type = type::ARRAY;
            o.via.array.size = 3;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            o.via.array.ptr[0] = msgpack::object(v.x, o.zone);
            o.via.array.ptr[1] = msgpack::object(v.y, o.zone);
            o.via.array.ptr[2] = msgpack::object(v.z, o.zone);
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_VEC3I_HPP
