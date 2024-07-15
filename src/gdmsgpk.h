//
// Created by raden on 7/3/2024.
//

#ifndef GDMSGPK_GDMSGPK_H
#define GDMSGPK_GDMSGPK_H

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/packed_byte_array.hpp"

namespace godot {

    class GDMessagePack : public RefCounted {
        GDCLASS(GDMessagePack, RefCounted)

    protected:
        static void _bind_methods();

        public:
        GDMessagePack();
        ~GDMessagePack();

        //PackedByteArray pack(const Variant &v);
        //Variant unpack(const PackedByteArray &pba);

        PackedByteArray pack(const Variant &v);
        Variant unpack(const PackedByteArray &pba);
    };

} // godot

#endif //GDMSGPK_GDMSGPK_H
