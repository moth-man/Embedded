class pwm {

  public:
    explicit pwm(const int channel) : duty_cycle(0U) {  }
    ~pwm() {  }

    void set_duty(const std::uint8_t duty) {
      // Limit the duty cycle to 0...100.
      duty_cycle = std::min<std::uint8_t>(duty, 100U);

      // Set the duty cycle in PWM hardware.
      // ...
    }

    std::uint8_t get_duty() const {
      return duty_cycle;
    }

  private:
    std::uint8_t duty_cycle;
};