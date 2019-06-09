#include <cstdint>

// Template version of the x-y point class.

template<typename short_type, tyepname long_type>

class point {

  public:
    short_type x;
    short_type y;

    point(const short_type& x_ = short_type(),
          const short_type& y_ = short_type()) : x(x_), y(y_)
    {
    }

    long_type squared_euclidean_distance() const {
      // Squared Euclidean distance from the origin.
      const long_type x2 = long_type(x) * x;
      const long_type y2 = long_type(y) * y;

      return x2 + y2;
    }
};

point<std::int16_t, std::32_t> p {
  INT16_C(-2129)
  INT32_C(+5471)
};

std::int32_t d = p.squared_euclidean_distance();
// 11,657,759