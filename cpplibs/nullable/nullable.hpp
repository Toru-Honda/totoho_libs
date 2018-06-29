/**
 * @file     nullable.hpp
 * @brief    Nullable template class
 * @author   totoho
 * @version  2018-06-12
 */

#include <stdexcept>

namespace Protocol
{
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
  //====================================================
  // operator overloads.
  //====================================================
  inline nullable<T> &operator=(const nullable<T> &rhs)
  {
    value_ = rhs.value_;
    has_value_ = rhs.has_value_;
    return *this;
  }
  // for set value using '='.
  inline nullable<T> &operator=(const T &rhs)
  {
    value_ = rhs;
    has_value_ = true;
    return *this;
  }
  // for set has_value flag false using '='.
  inline nullable<T> &operator=(const void* rhs)
  {
    has_value_ = false;
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

  nullable<T>(nullable<T> &rhs)
  : has_value_(rhs.has_value_)
    ,value_(rhs.value_)
  {}
};
}