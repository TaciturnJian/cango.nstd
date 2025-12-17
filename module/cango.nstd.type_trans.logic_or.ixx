export module cango.nstd.type_trans.logic_or;

import cango.nstd.type_trans.true_tv;
import cango.nstd.type_trans.false_tv;

export namespace cango {
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
