#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_C
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_C

#include "just_type.hpp"

namespace cango::nstd::type_trans {
template<typename T>
struct remove_const : just_type<T> {};

template<typename T>
struct remove_const<const T> : remove_const<T> {};

template<typename T>
using remove_c = remove_const<T>;

/// @brief 移除目标类型的 const 修饰
/// @tparam T 目标类型
template<typename T>
using remove_const_t = remove_c<T>::type;

template<typename T>
using remove_c_t = remove_const_t<T>;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_C
