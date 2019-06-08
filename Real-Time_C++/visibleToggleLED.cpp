#include <cstdint>
#include <util/utility/util_time.h>
#include <mcal/mcal.h>

class led {

  public:
    // Use convenient class-specific typedefs.
    typedef std::uint8_t port_type;
    typedef std::uint8_t bval_type;

    // The led class constructor.
    led(const port_type p,
        const bval_type b) : port(p),
                            bval(b)
    {
      // Set the port pin value to low.
      *reinterpret_cast<volatile bval_type*>(port) 
      &= static_cast<bval_type>(~bval);
      
      // Set the port pin direction to output.
      *reinterpret_cast<volatile bval_type*>(port - 1U) |= bval;
    }

    void toggle() const {
      //Toggle the LED via direct memory access.
      *reinterpret_cast<volatile bval_type*>(port) ^= bval;
    }
  
  private:
    // Private member variables of the class.
    const port_type port;
    const bval_type bval;

};

namespace {

  // Define a convenient local 16-bit timer type.
  typedef util::timer<std::uint16_t> timer_type;

  // Create led_b5 at port B, bit-position 5.
  const led led_b5 {

    mcal::reg::portb,
    mcal::reg::bcal5

  };
}

int main() {

  //Enable all global interrupts.
  mcal::irq::enable_all();

  // Initialize the mcal.
  mcal::init();

  // Toggle led_b5 forever with a 1s delay (0.5Hx).
  for(;;) {
    led_b5.toggle();

    // Wait 1s in a blocking delay.
    timer_type::blocking_delay(timer_type::seconds(1));
  }
}