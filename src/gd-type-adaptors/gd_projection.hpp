//
// Created by raden on 7/14/2024.
//

#ifndef GDMSGPK_GD_PROJECTION_HPP
#define GDMSGPK_GD_PROJECTION_HPP



#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "gd_vec4.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::Projection> {
        msgpack::object const& operator()(msgpack::object const& o, godot::Projection& v) const {
            if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
            if (o.via.array.size != 4) throw msgpack::type_error();
            v = godot::Projection(
                    o.via.array.ptr[0].as<godot::Vector4>(),
                    o.via.array.ptr[1].as<godot::Vector4>(),
                    o.via.array.ptr[2].as<godot::Vector4>(),
                    o.via.array.ptr[3].as<godot::Vector4>());
            return o;
        }
    };
    template <>
    struct pack<godot::Projection> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::Projection const& v) const {
            o.pack_array(4);
            o.pack(v.columns[0]);
            o.pack(v.columns[1]);
            o.pack(v.columns[2]);
            o.pack(v.columns[3]);
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::Projection> {
        void operator()(msgpack::object::with_zone& o, godot::Projection const& v) const {
            o.type = type::ARRAY;
            o.via.array.size = 4;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            o.via.array.ptr[0] = msgpack::object(v.columns[0], o.zone);
            o.via.array.ptr[1] = msgpack::object(v.columns[1], o.zone);
            o.via.array.ptr[2] = msgpack::object(v.columns[2], o.zone);
            o.via.array.ptr[3] = msgpack::object(v.columns[3], o.zone);
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_PROJECTION_HPP
