//------------------------------------------------------------------------------
/*
    This file is part of casinocoind: https://github.com/casinocoin/casinocoind

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

//==============================================================================
/*
    2018-01-07  jrojek        Created
*/
//==============================================================================

#ifndef CASINOCOIN_PROTOCOL_STVECTOR128_H_INCLUDED
#define CASINOCOIN_PROTOCOL_STVECTOR128_H_INCLUDED

#include <casinocoin/protocol/STBitString.h>
#include <casinocoin/protocol/STInteger.h>
#include <casinocoin/protocol/STBase.h>

namespace casinocoin {

class STVector128
    : public STBase
{
public:
    using value_type = std::vector<uint128> const&;

    STVector128 () = default;

    explicit STVector128 (SField const& n)
        : STBase (n)
    { }

    explicit STVector128 (std::vector<uint128> const& vector)
        : mValue (vector)
    { }

    STVector128 (SField const& n, std::vector<uint128> const& vector)
        : STBase (n), mValue (vector)
    { }

    STVector128 (SerialIter& sit, SField const& name);

    STBase*
    copy (std::size_t n, void* buf) const override
    {
        return emplace(n, buf, *this);
    }

    STBase*
    move (std::size_t n, void* buf) override
    {
        return emplace(n, buf, std::move(*this));
    }

    SerializedTypeID
    getSType () const override
    {
        return STI_VECTOR128;
    }

    void
    add (Serializer& s) const override;

    Json::Value
    getJson (int) const override;

    bool
    isEquivalent (const STBase& t) const override;

    bool
    isDefault () const override
    {
        return mValue.empty ();
    }

    STVector128&
    operator= (std::vector<uint128> const& v)
    {
        mValue = v;
        return *this;
    }

    STVector128&
    operator= (std::vector<uint128>&& v)
    {
        mValue = std::move(v);
        return *this;
    }

    void
    setValue (const STVector128& v)
    {
        mValue = v.mValue;
    }

    /** Retrieve a copy of the vector we contain */
    explicit
    operator std::vector<uint128> () const
    {
        return mValue;
    }

    std::size_t
    size () const
    {
        return mValue.size ();
    }

    void
    resize (std::size_t n)
    {
        return mValue.resize (n);
    }

    bool
    empty () const
    {
        return mValue.empty ();
    }

    std::vector<uint128>::reference
    operator[] (std::vector<uint128>::size_type n)
    {
        return mValue[n];
    }

    std::vector<uint128>::const_reference
    operator[] (std::vector<uint128>::size_type n) const
    {
        return mValue[n];
    }

    std::vector<uint128> const&
    value() const
    {
        return mValue;
    }

    void
    push_back (uint128 const& v)
    {
        mValue.push_back (v);
    }

    std::vector<uint128>::iterator
    begin()
    {
        return mValue.begin ();
    }

    std::vector<uint128>::const_iterator
    begin() const
    {
        return mValue.begin ();
    }

    std::vector<uint128>::iterator
    end()
    {
        return mValue.end ();
    }

    std::vector<uint128>::const_iterator
    end() const
    {
        return mValue.end ();
    }

    std::vector<uint128>::iterator
    erase (std::vector<uint128>::iterator position)
    {
        return mValue.erase (position);
    }

    void
    clear () noexcept
    {
        return mValue.clear ();
    }

private:
    std::vector<uint128> mValue;
};

} // casinocoin

#endif
