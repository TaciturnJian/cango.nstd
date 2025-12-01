#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_AND
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_AND

#include "false_tv.hpp"
#include "true_tv.hpp"

namespace cango::nstd::type_trans {
template<bool...>
struct logic_and : true_tv {};

template<bool... Rest>
struct logic_and<false, Rest...> : false_tv {};

template<bool... Rest>
struct logic_and<true, Rest...> : logic_and<Rest...> {};

/// @brief 获取给定参数的逻辑与的结果
/// @tparam List 布尔值列表
template<bool... List>
inline constexpr bool logic_and_v = logic_and<List...>::value;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_AND
