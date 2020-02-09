#ifndef BITCOINRPC_BLOCKTEMPLATE_H
#define BITCOINRPC_BLOCKTEMPLATE_H

#include <stdint.h>
#include <vector>

#include <util/ByteString.h>
#include <mining/Hash256.h>

class BlockTemplate
{
    public:
        class TransactionInfo
        {
            public:
                const Hash256 id;
                const ByteString raw;

                inline TransactionInfo(const Hash256 &id, const ByteString &raw) : id(id), raw(raw) {}
        };

        typedef std::vector<TransactionInfo> Transactions;

        const uint32_t version;
        const uint32_t height;

        const Hash256 previousBlockHash;
        const Transactions transactions;
        const ByteString witnessCommitment;

        const uint64_t coinbaseCoins;
        const Hash256 miningTarget;
        const uint32_t miningTargetBits;
        const time_t notBefore;

        inline BlockTemplate(uint32_t version, uint32_t height,
                             const Hash256 &previousBlockHash, Transactions &&transactions, const ByteString &witnessCommitment,
                             uint64_t coinbaseCoins, const Hash256 &miningTarget, uint32_t miningTargetBits, time_t notBefore) :
            version(version),
            height(height),
            previousBlockHash(previousBlockHash),
            transactions(transactions),
            witnessCommitment(witnessCommitment),
            coinbaseCoins(coinbaseCoins),
            miningTarget(miningTarget),
            miningTargetBits(miningTargetBits),
            notBefore(notBefore)
        {}
};

#endif
