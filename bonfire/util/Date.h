#ifndef BONFIRE_DATE_H__
#define BONFIRE_DATE_H__

#include <stdint.h>
#include <string>

#include "Copyable.h"

#define MICRO_SECONDS_PRE_SEC 1000000LL

namespace bonfire
{
  class Date : Copyable {
   public:
    Date() : micro_sec_since_epoch_(0) {}

    explicit Date(uint64_t mico_sec) : micro_sec_since_epoch_(mico_sec) {}

    Date(unsigned int year,
         unsigned int month,
         unsigned int day,
         unsigned int hour = 0,
         unsigned int minute = 0,
         unsigned int second = 0,
         unsigned int micro_second = 0);

    static const Date date();

    static const Date now() {
      return Date::date();
    }

    static int64_t timezone_offset() {
      static int64_t offset;
      return offset;
    }

    const Date after(double second) const;

    const Date round_second() const;

    const Date round_day() const;

    ~Date() {}

    constexpr bool operator == (const Date& date) const noexcept {
      return micro_sec_since_epoch_ == date.micro_sec_since_epoch_;
    }

    constexpr bool operator != (const Date& date) const noexcept {
      return !(*this == date);
    }

    constexpr bool operator < (const Date& date) const noexcept {
      return micro_sec_since_epoch_ < date.micro_sec_since_epoch_;
    }

    constexpr bool operator > (const Date& date) const noexcept {
      return micro_sec_since_epoch_ > date.micro_sec_since_epoch_;
    }

    constexpr bool operator <= (const Date& date) const noexcept {
      return micro_sec_since_epoch_ <= date.micro_sec_since_epoch_;
    }

    constexpr bool operator >= (const Date& date) const noexcept {
      return micro_sec_since_epoch_ >= date.micro_sec_since_epoch_;
    }

    constexpr int64_t micro_seconds_since_epoch() const noexcept {
      return micro_sec_since_epoch_;
    }

    constexpr int64_t seconds_since_epoch() const noexcept {
      return micro_sec_since_epoch_ / MICRO_SECONDS_PRE_SEC;
    }

    struct tm tm_struct() const;

    std::string to_formatted_string(bool show_micro_sec) const;

    std::string to_customed_formatted_string(const std::string& fmt_str,
                                             bool show_micro_sec = false) const;

    std::string to_formatted_string_local(bool show_micro_sec) const;

    std::string to_customed_formatted_string_local(const std::string& fmt_str,
                                                   bool show_micro_sec = false) const;

    std::string to_db_string() const;

    std::string to_db_string_local() const;

    static Date from_db_string_local(const std::string& datetime);

    static Date from_db_string(const std::string& datetime);

    void to_customed_formatted_string(const std::string& fmt_str,
                                      char* str,
                                      size_t len) const;

    bool is_same_second(const Date& date) const {
      return micro_sec_since_epoch_ / MICRO_SECONDS_PRE_SEC ==
            date.micro_sec_since_epoch_ / MICRO_SECONDS_PRE_SEC;
    }

    void swap(Date& that) {
      std::swap(micro_sec_since_epoch_, that.micro_sec_since_epoch_);
    }

   private:
    uint64_t micro_sec_since_epoch_{0};
  };
} // namespace bonfire


#endif // BONFIRE_COPYABLE_H__
