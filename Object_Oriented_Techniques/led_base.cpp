class led_base {

  public:
    virtual void toggle() = 0; // Pure abstract.
    virtual ~led_base() { }    // Virtual destructor.

    // Interface for querying the LED state.
    bool state_is_on() const { return is_on; }

  protected:
    bool is_on;

    // A protected default constructor.
    led_base() : is_on(false) { }
  
  private:
    // Private non-implemented copy constructor.
    led_base(const led_base&) = delete;

    // Private non-implemented copy assignment operator.
    const led_base& operator=(const led_base&) = delete;
};