#ifndef MINING_HASH_H
#define MINING_HASH_H

#include <stdint.h>

#include <util/ByteString.h>

template <class hash_t> class Hash
{
    public:
        const hash_t raw;

        inline ConstByteStringRef bytes(void) const     { return ConstByteStringRef(this->raw, sizeof(this->raw)); }
        inline operator ConstByteStringRef(void) const  { return this->bytes(); }

    protected:
        Hash(size_t s = sizeof(hash_t));
        Hash(const uint8_t *src, size_t s = sizeof(hash_t));
        Hash(const ByteString &src, size_t s = sizeof(hash_t));
        Hash(const ConstByteStringRef &src, size_t s = sizeof(hash_t));

        bool isLower(const Hash &them, size_t s = sizeof(hash_t)) const;
        bool isLower(const Hash &them, bool orEqual, size_t s = sizeof(hash_t)) const;
};

#endif
