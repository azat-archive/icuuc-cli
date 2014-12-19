#include <unicode/unistr.h>

#include <string>
#include <cassert>

#include "ops.h"


Ops::Ops()
    : m_status(U_ZERO_ERROR)
    , m_normalizer(*Normalizer2::getNFKCInstance(m_status))
{
    assert(&m_normalizer);
    assert(U_SUCCESS(m_status));
}

std::string &Ops::normalize(std::string &input)
{
    m_status = U_ZERO_ERROR;
    m_output.clear();

    UnicodeString source = UnicodeString::fromUTF8(StringPiece(input));
    UnicodeString result;
    m_normalizer.normalize(source, result, m_status);
    if (U_SUCCESS(m_status)) {
        result.toUTF8String(m_output);
    }
    return m_output;
}