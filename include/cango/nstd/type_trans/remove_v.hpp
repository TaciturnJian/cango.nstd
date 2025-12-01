#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_V
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_V

#include "just_type.hpp"

namespace cango::nstd::type_trans {
template<typename T>
struct remove_volatile : just_type<T> {};

template<typename T>
struct remove_volatile<volatile T> : remove_volatile<T> {};

template<typename T>
using remove_v = remove_volatile<T>;

/// @brief 移除目标类型的 volatile 修饰
/// @tparam T 目标类型
template<typename T>
using remove_volatile_t = remove_v<T>::type;

template<typename T>
using remove_v_t = remove_volatile_t<T>;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_V
