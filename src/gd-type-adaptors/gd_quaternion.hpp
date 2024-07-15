//
// Created by raden on 7/14/2024.
//

#ifndef GDMSGPK_GD_QUATERNION_HPP
#define GDMSGPK_GD_QUATERNION_HPP



#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::Quaternion> {
        msgpack::object const& operator()(msgpack::object const& o, godot::Quaternion& v) const {
            if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
            if (o.via.array.size != 4) throw msgpack::type_error();
            v = godot::Quaternion(
                    o.via.array.ptr[0].as<real_t>(),
                    o.via.array.ptr[1].as<real_t>(),
                    o.via.array.ptr[2].as<real_t>(),
                    o.via.array.ptr[3].as<real_t>());
            return o;
        }
    };
    template <>
    struct pack<godot::Quaternion> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::Quaternion const& v) const {
            o.pack_array(4);
            o.pack(v.x);
            o.pack(v.y);
            o.pack(v.z);
            o.pack(v.w);
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::Quaternion> {
        void operator()(msgpack::object::with_zone& o, godot::Quaternion const& v) const {
            o.type = type::ARRAY;
            o.via.array.size = 4;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            o.via.array.ptr[0] = msgpack::object(v.x, o.zone);
            o.via.array.ptr[1] = msgpack::object(v.y, o.zone);
            o.via.array.ptr[2] = msgpack::object(v.z, o.zone);
            o.via.array.ptr[3] = msgpack::object(v.w, o.zone);
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_QUATERNION_HPP
