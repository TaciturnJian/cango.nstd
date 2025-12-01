#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_NOT
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_NOT

#include "false_tv.hpp"
#include "true_tv.hpp"

namespace cango::nstd::type_trans {
template<bool V>
struct logic_not;

template<>
struct logic_not<true> : false_tv {};

template<>
struct logic_not<false> : true_tv {};

/// @brief 获取给定参数的逻辑非的结果
/// @tparam V 布尔值
template<bool V> 
inline constexpr bool logic_not_v = logic_not<V>::value;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_NOT
