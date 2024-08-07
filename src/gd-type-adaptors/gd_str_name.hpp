//
// Created by raden on 7/14/2024.
//

#ifndef GDMSGPK_GD_STR_NAME_HPP
#define GDMSGPK_GD_STR_NAME_HPP



#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "gd_string.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::StringName> {
        msgpack::object const& operator()(msgpack::object const& o, godot::StringName& v) const {
            if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
            if (o.via.array.size != 1) throw msgpack::type_error();
            v  = godot::StringName(o.via.array.ptr[0].as<godot::String>());
            return o;
        }
    };
    template <>
    struct pack<godot::StringName> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::StringName const& v) const {
            o.pack_array(1);
            o.pack(godot::String(v));
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::StringName> {
        void operator()(msgpack::object::with_zone& o, godot::StringName const& v) const {
            o.type = type::ARRAY;
            o.via.array.size = 1;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            o.via.array.ptr[0] = msgpack::object(godot::String(v), o.zone);
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_STR_NAME_HPP
