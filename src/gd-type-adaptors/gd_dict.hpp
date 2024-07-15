//
// Created by raden on 7/14/2024.
//

#ifndef GDMSGPK_GD_DICT_HPP
#define GDMSGPK_GD_DICT_HPP



#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "gd_adaptors.h"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::Dictionary> {
        msgpack::object const& operator()(msgpack::object const& o, godot::Dictionary& v) const {
            if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
            if (o.via.array.size != 2) throw msgpack::type_error();
            godot::Array keys = o.via.array.ptr[0].as<godot::Array>();
            godot::Array values = o.via.array.ptr[1].as<godot::Array>();
            if (keys.size() != values.size()) throw msgpack::type_error();
            for (int i = 0; i < keys.size(); i++) {
                v[keys[i]] = values[i];
            }
            return o;
        }
    };
    template <>
    struct pack<godot::Dictionary> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::Dictionary const& v) const {
            godot::Array keys = v.keys();
            godot::Array values = v.values();
            o.pack_array(2);
            o.pack(keys);
            o.pack(values);
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::Dictionary> {
        void operator()(msgpack::object::with_zone& o, godot::Dictionary const& v) const {
            godot::Array keys = v.keys();
            godot::Array values = v.values();
            o.type = type::ARRAY;
            o.via.array.size = 2;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            o.via.array.ptr[0] = msgpack::object(keys, o.zone);
            o.via.array.ptr[1] = msgpack::object(values, o.zone);
        }
    };

}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_DICT_HPP
