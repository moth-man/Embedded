#include <cstdint>

// This has *exactly* 16-bits signed.
constexpr std::int16_t value16 = INT16_C(0x7FFF);

// This has *at least* 32-bits unsigned.
constexpr std::uint_least32_t value32 = UINT32_C(4'294'967'295);
////////////////////////////////////////////////////////////////

#include <cstdint>

// The suffix U means unsigned int.
constexpr std::uint32_t prime_number = 10'006'721U;
///////////////////////////////////////////////////////////////

#include <cstdint>

// Here, the macro UINT32_C() is clearly formulated.
constexpr std::uint32_t prime_number = UINT32_C(10'006'721);
