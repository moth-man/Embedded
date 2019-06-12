class led_pwm : public led_base {

  public:
    explicit led_pwm(pwm* p) : my_pwm(p) {  }
    virtual ~led_pwm() {  }

    virtual void toggle() {
      // Toggle the LED with the PWM signal.
      is_on = (my_pwm->get_duty() > 0U);

      my_pwm->set_duty(is_on ? 0U : 100U);

      is_on = !is_on;
    }

    // This LED class also supports dimming.
    void dimming(const std::uint8_t duty) {
      my_pwm->set_duty(duty);
      is_on = (duty != 0U);
    }

    private:
      pwm* my_pwm;
};