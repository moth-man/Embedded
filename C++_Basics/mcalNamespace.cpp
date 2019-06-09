// Namespace for the microcontroller abstraction layer
namespace mcal {
  // The mcal initialization.
  void init();

  // The general purpose timer stuff in mcal.
  namespace gpt {

    void init();
    std::uint32_t get_time_elapsed();
  }

  // The ADC stuff in mcal.
  namespace adc {

    void init();
    std::uint16_t read_value(const unsigned);
  }
}

// Initialize the mcal.
// Note the clean organization with namespaces.
void mcal::init() {
  mcal::gpt::init();
  mcal::adc::init();
}