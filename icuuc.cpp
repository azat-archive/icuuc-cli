#include <unicode/utypes.h>
#include <unicode/unistr.h>
#include <unicode/normalizer2.h>

#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>

class Ops
{
public:
    Ops()
        : m_status(U_ZERO_ERROR)
        , m_normalizer(*Normalizer2::getNFCInstance(m_status))
    {
        assert(&m_normalizer);
        assert(U_SUCCESS(m_status));
    }

    std::string &normalize(std::string &input)
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

private:
    std::string m_output;

    UErrorCode m_status;
    const Normalizer2 &m_normalizer;
};

int main(int argc, char **argv)
{
    std::string buffer;
    Ops ops;

    while (std::getline(std::cin, buffer)) {
        std::cout << ops.normalize(buffer) << std::endl;
    }

    return EXIT_SUCCESS;
}
