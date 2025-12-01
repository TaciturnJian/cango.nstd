#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_TYPE_VALUE
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_TYPE_VALUE

#include "just_type.hpp"
#include "just_value.hpp"

namespace cango::nstd::type_trans {
/// @brief 内部 type 和 value 为目标类型和目标值
/// @tparam T 目标类型
/// @tparam V 目标值
template<typename T, T V>
struct type_value : just_type<T>, just_value<T, V> {};
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_TYPE_VALUE
