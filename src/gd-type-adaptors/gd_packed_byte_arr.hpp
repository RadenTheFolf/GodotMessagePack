//
// Created by raden on 7/14/2024.
//

#ifndef GDMSGPK_GD_PACKED_BYTE_ARR_HPP
#define GDMSGPK_GD_PACKED_BYTE_ARR_HPP



#include "msgpack.hpp"
#include "godot_cpp/variant/variant.hpp"


namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

    template <>
    struct convert<godot::PackedByteArray> {
        msgpack::object const& operator()(msgpack::object const& o, godot::PackedByteArray& v) const {
            if (o.type != msgpack::type::BIN) throw msgpack::type_error();
            std::vector<unsigned char> data;
            data.resize(o.via.bin.size);
            std::memcpy(data.data(), o.via.bin.ptr, o.via.bin.size);
            for (unsigned char i : data) {
                v.push_back(i);
            }

            return o;
        }
    };
    template <>
    struct pack<godot::PackedByteArray> {
        template <typename Stream>
        msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, godot::PackedByteArray const& v) const {
            std::vector<unsigned char> data;
            data.resize(v.size());
            memcpy(data.data(), v.ptr(), v.size());
            o.pack(data);
            return o;
        }
    };

    template <>
    struct object_with_zone<godot::PackedByteArray> {
        void operator()(msgpack::object::with_zone& o, godot::PackedByteArray const& v) const {
            std::vector<unsigned char> data;
            data.resize(v.size());
            memcpy(data.data(), v.ptr(), v.size());
            o.type = type::BIN;
            o.via.bin.size = data.size();
            o.via.bin.ptr = static_cast<const char*>(o.zone.allocate_align(data.size()));
            std::memcpy(const_cast<char*>(o.via.bin.ptr), data.data(), data.size());
        }
    };
}
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif //GDMSGPK_GD_PACKED_BYTE_ARR_HPP
