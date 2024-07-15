//
// Created by raden on 7/3/2024.
//

#include "gdmsgpk.h"

#include "msgpack.hpp"
#include "gd-type-adaptors/gd_var.hpp"

using namespace godot;

    GDMessagePack::GDMessagePack() {
    }

    GDMessagePack::~GDMessagePack() {
    }

    PackedByteArray GDMessagePack::pack(const godot::Variant &v) {
        msgpack::sbuffer sbuf;
        godot::Variant o = v;
        msgpack::pack(sbuf, o);
        PackedByteArray pba;
        pba.resize(sbuf.size());
        memcpy(pba.ptrw(), sbuf.data(), sbuf.size());
        return pba;
    }

    void GDMessagePack::_bind_methods() {
        ClassDB::bind_method(D_METHOD("pack", "v"), &GDMessagePack::pack);
        ClassDB::bind_method(D_METHOD("unpack", "pba"), &GDMessagePack::unpack);
    }

Variant GDMessagePack::unpack(const PackedByteArray &pba) {
    msgpack::object_handle oh = msgpack::unpack((char*)pba.ptr(), pba.size());
    msgpack::object obj = oh.get();
    godot::Variant v;
    obj.convert(v);
    return v;
}

