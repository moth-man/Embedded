class led_port : public led_base {

  public:
    typedef std::uint8_t port_type;
    typedef std::uint8_t bval_type;

    led_port(const port_type p, const bval_type b)
      : port(p), bval(b)
    {

    }

    virtual ~led_port() { }
    
    virtual void toggle() {
      // Toggle the LED.
      *reinterpret_cast<volatile bval_type*>(port) ^= bval;

      // Toggle the is_on indication flag.
      is_on = !is_on;
    }

    private:
      const port_type port;
      const bval_type bval;
};