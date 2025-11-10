#pragma once
#include <cstdint>

namespace CGhostbuster
{
#pragma pack(push, 1)
    struct CGhostbuster
    {
        void* vtable;                // 0x0000
        uint32_t unk8;              // 0x0008
        uint32_t unkC;              // 0x000C
        uint32_t flags;             // 0x0010 (hex)
        uint32_t unk14;             // 0x0014
        uint32_t unk18;             // 0x0018
        uint32_t unk1C;             // 0x001C
        uint32_t unk20;             // 0x0020
        uint32_t unk24;             // 0x0024

        char GhostbusterName[13];   // 0x0028 (string)
        uint8_t unk35;              // 0x0035
        uint8_t unk36;              // 0x0036
        uint8_t unk37;              // 0x0037

        uint32_t unk38;             // 0x0038 (hex)
        uint32_t unk3C;             // 0x003C (hex)
        uint32_t unk40;             // 0x0040 (hex)
        uint32_t unk44;             // 0x0044
        uint32_t unk48;             // 0x0048
        uint32_t unk4C;             // 0x004C (hex)

        float posX;                 // 0x0054
        float posY;                 // 0x0058
        float posZ;                 // 0x005C
    };
#pragma pack(pop)

    CGhostbuster* getLocalPlayer();
    CGhostbuster* flinch(CGhostbuster* actor);
}
