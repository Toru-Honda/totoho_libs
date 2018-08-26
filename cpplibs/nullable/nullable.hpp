/**
 * @file     nullable.hpp
 * @brief    Nullable template class
 * @author   totoho
 * @version  2018-06-12
 */

#ifndef __NULLABLE_HPP
#define __NULLABLE_HPP

#include <stdexcept>

namespace totoho{
/**
 * nullopt
 * unique null value for nullable
 */
struct nullopt_t{};
constexpr nullopt_t nullopt{};

/**
 * nullable template class.
 * default is null.
 */
template <typename T>
class nullable
{
private:
  bool has_value_;
  T value_;

public:
  /**
   * @return null -> false, not null -> true
   */
  inline bool has_value(void) const
  {
    return has_value_;
  }
  /**
   * @fn
   *   set has_value false.
   */
  inline void set_null(void)
  {
    has_value_ = false;
  }
  /**
   * @fn
   *  get value. if value is null, throw runtime error.
   */
  inline T get_value(void) const
  {
    if (!has_value_)
    {
      throw std::runtime_error("value is null!");
    }
    return value_;
  }
  /**
   * @fn
   *  set value. if value is type T, set has_value_ true.
   */
  inline void set_value(const nullable<T> &rhs)
  {
    value_ = rhs.value_;
    has_value_ = rhs.has_value_;
  }
  inline void set_value(const T &rhs)
  {
    value_ = rhs;
    has_value_ = true;
  }
  /**
   * @fn
   * set_value for has_value flag false
   */
  inline void set_value(const nullopt_t &rhs)
  {
    set_null();
  }
  //====================================================
  // operator overloads.
  //====================================================
  inline nullable<T> &operator=(const nullable<T> &rhs)
  {
    set_value(rhs);
    return *this;
  }
  // for set value using '='.
  inline nullable<T> &operator=(const T &rhs)
  {
    set_value(rhs);
    return *this;
  }
  // for set has_value flag false using '='.
  inline nullable<T> &operator=(const void* rhs)
  {
    has_value_ = false;
    return *this;
  }
  // for set has_value flag false using '='.
  inline nullable<T> &operator=(const nullopt_t& rhs)
  {
    set_value(rhs);
    return *this;
  }
  // for boolean expression
  inline explicit operator bool(void) const
  {
    return (*this).has_value();
  }
  // for set value to type T.
  inline explicit operator T(void) const
  {
    return (*this).get_value();
  }

public:
  //=====================================================
  // constructors
  //=====================================================
  nullable<T>(void)
  : has_value_(false)
  {}

  explicit nullable<T>(T val)
  : has_value_(true)
    ,value_(val)
  {}

  nullable<T>(const nullable<T> &rhs)
  : has_value_(rhs.has_value_)
    ,value_(rhs.value_)
  {}

};
} // namespace totoho

#endif // __NULLABLE_HPP
