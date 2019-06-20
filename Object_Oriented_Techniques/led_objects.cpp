#include <cstdint>
#include <mcal/mcal.h>

namespace {
  // Two LEDs on port2.0 and port2.1
  led_port led0 {
    mcal::reg::port2,
    mcal::reg::bval0
  };

  led_port led1 {
    mcal::reg::port2,
    mcal::reg::bval1
  };

  // Two PWMs on channels timer0 and timer1.
  pwm pwm0 { 0 };
  pwm pwm1 { 1 };

  // Two LEDs connected to pwm0 and pwm1.
  led_pwm led2 { &pwm0 };
  led_pwm led3 { &pwm1 };
}

void do_something() {
  // Toggle L0-L3.
  led0.toggle();
  led1.toggle();
  led2.toggle();
  led3.toggle();
}