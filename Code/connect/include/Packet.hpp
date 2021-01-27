#pragma once

#include <TiltedCore/Meta.hpp>
#include <TiltedCore/Allocator.hpp>

namespace TiltedPhoques
{
    struct Packet
    {
        TP_ALLOCATOR;

        Packet() noexcept;
        Packet(size_t aSize) noexcept;
        virtual ~Packet() noexcept;

        TP_NOCOPYMOVE(Packet);

        // Get the start of the write buffer
        [[nodiscard]] char* GetData() const noexcept;

        // Get the writable data size, note that the actual packet size may differ from that
        [[nodiscard]] size_t GetSize() const noexcept;

        // Get the writable data size + protocol data size
        [[nodiscard]] size_t GetTotalSize() const noexcept;

        // Returns true if the packet has an associated buffer, usually used to check if the underlying allocator had enough space
        [[nodiscard]] bool IsValid() const noexcept;

    protected:

        friend struct Server;
        friend struct Client;

        char* m_pData;
        size_t m_size;
    };

    struct PacketView : Packet
    {
        PacketView(char* aPointer, size_t aSize);
        virtual ~PacketView();
    };
}
