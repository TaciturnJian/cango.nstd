#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_IS_REF
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_IS_REF

#include "is_lv_ref.hpp"
#include "is_rv_ref.hpp"

#include "logic_or.hpp"

namespace cango::nstd::type_trans {
template<typename T>
using is_reference = logic_or<is_lv_ref_v<T>, is_rv_ref_v<T> >;

template<typename T>
using is_ref = is_reference<T>;

/// @brief 判断给定类型是否为引用类型
/// @tparam T 待检查的类型
template<typename T>
inline constexpr bool is_reference_v = is_ref<T>::value;

template<typename T>
inline constexpr bool is_ref_v = is_reference_v<T>;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_IS_REF
