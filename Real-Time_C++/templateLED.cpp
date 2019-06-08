template<typename port_type,
         typename bval_type,
         const port_type port,
         const bval_type bval>

class led_template {

  public:
    led_template() {
      // Set the port pin value to low.
      *reinterpret_cast<volatile bval_type*>(port)
       &= static_cast<bval_type>(~bval);

      // Set the port pin direction to output.
      *reinterpret_cast<volatile bval_type*>(pdir)
       |= bval;
    }

    static void toggle() {
      // Toggle the LED.
      *reinterpret_cast<volatile bval_type*>(port)
       ^= bval;
    }
  
  private:
   static constexpr port_type pdir = port - 1U;
};

namespace {
  // Create led_b5 at port B, bit-position 5.
  const led_template<std::uint8_t,
                     std::uint8_t,
                     mcal::reg::portb,
                     mcal::reg::bval5> led_b5;
}

int main() {
  // Toggle led_b5 forever.
  for(;;) {
    led_b5.toggle();
  }
}