#include <unicode/utypes.h>
#include <unicode/normalizer2.h>
#include <string>

class Ops
{
public:
    Ops();

    std::string &normalize(std::string &input);

private:
    std::string m_output;

    UErrorCode m_status;
    const Normalizer2 &m_normalizer;
};


