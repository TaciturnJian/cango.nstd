#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_OR
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_OR

#include "false_tv.hpp"
#include "true_tv.hpp"

namespace cango::nstd::type_trans {
template<bool...>
struct logic_or : false_tv {};

template<bool... Rest>
struct logic_or<true, Rest...> : true_tv {};

template<bool... Rest>
struct logic_or<false, Rest...> : logic_or<Rest...> {};

/// @brief 获取给定参数的逻辑非的结果
/// @tparam List 布尔值列表
template<bool... List>
inline constexpr bool logic_or_v = logic_or<List...>::value;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_OR
