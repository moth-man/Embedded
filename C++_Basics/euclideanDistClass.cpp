#include <cstdint>

// An unsigned xy-coordinate point with some geometry.
class point {

  public:
    std::uint8_t x;
    std::uint8_t y;

    point(const std::uint8 x_ = UINT8_C(0),
          const std::uint8 y_ = UINT8_C(0) : x(x_), y(y_))
    ( )

    std::uint16_t squared_euclidean_distance() const {
      //Squared Euclidean distance from the origin.
      const std::uint16_t x2 = std::uint16_t(x) * x;
      const std::uint16_t y2 = std::uint16_t(y) * y;

      return x2 + y2;
    }
};

point p1;

point p2 {
  UINT8_C(31), UINT8_C(47)
};

// The squared Euclidean distance d1 is 0.
std::uint16_t d1 = p1.squared_euclidean_distance();

// The squared Euclidean distance d2 is 3,170.
std::uint16_t d2 = p2.squared_euclidean_distance();