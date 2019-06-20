extern "C"
void com_recv_isr() __attribute__((interrupt));

class communication {
  
  public:
    communication() : recv_buf(0U), has_recv(false) { }
    ~communication() {  }

    bool send_byte(const std::uint8_t by) const {
      *reinterpret_cast<volatile std::uint8_t*>(tbuf) = by;
    }

    bool recv_ready() const {
      return has_recv;
    }

    std::uint8_t recv_byte() {
      if(has_recv) {
        has_recv = false;
        return recv_buf;
      }

      return 0U;
    }

  private:
    static constexpr std::uint8_t tbuf = 0xAAU;
    static constexpr std::uint8_t rbuf = 0xAEU;

    std::uint8_t recv_buf;
    bool has_recv;

    communication(const communication&) = delete;
    const communication& operator=(const communication&) = delete;

    friend void com_recv_isr() __attribute__((interrupt));
};