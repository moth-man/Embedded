// Inner product example using numeric library.
// u * v = uv
#include <array>
#include <numeric>

const std::array<int, 3U> u {

  { 1, 2, 3 }

};

const std::array<int, 3U> v {

  { 4, 5, 6 }

};

const int uv = std::inner_product(u.begin(),
                                  u.end(),
                                  v.begin(),
                                  0);
// Result is 32.