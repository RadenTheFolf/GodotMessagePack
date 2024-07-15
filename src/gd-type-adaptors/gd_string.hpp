#ifndef GDMSGPK_GD_STRING_HPP
#define GDMSGPK_GD_STRING_HPP

#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "adaptor_utils.hpp"

namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::String> {
        msgpack::object const& operator()(msgpack::object const& obj, godot::String& gdstr) const {
            if (obj.type != msgpack::type::ARRAY) throw msgpack::type_error();
            if (obj.via.array.size != 1) throw msgpack::type_error();

            std::vector<unsigned char> bytes = obj.via.array.ptr->as<std::vector<unsigned char>>();
            std::vector<char32_t> str = adaptor_utils::byteArrayToChar32(bytes.data(), bytes.size());
            for (auto &c : str) {
                gdstr += godot::String::chr(c);
            }
            return obj;
        }
    };

    template <>
    struct pack<godot::String> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::String const& v) const {
            o.pack_array(1);
            std::vector<unsigned char> bytes = adaptor_utils::char32ToByteArray(v.ptr(), v.length());
            o.pack(bytes);
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::String> {
        void operator()(msgpack::object::with_zone& o, godot::String const& v) const {
            o.type = msgpack::type::ARRAY;
            o.via.array.size = 1;
            o.via.array.ptr = static_cast<msgpack::object*>(
                    o.zone.allocate_align(sizeof(msgpack::object) * o.via.array.size));
            std::vector<unsigned char> bytes = adaptor_utils::char32ToByteArray(v.ptr(), v.length());
            o.via.array.ptr[0] = msgpack::object(bytes, o.zone);
        }
    };

} // namespace adaptor
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif // GDMSGPK_GD_STRING_HPP