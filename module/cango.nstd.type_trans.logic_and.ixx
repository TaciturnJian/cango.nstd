export module cango.nstd.type_trans.logic_and;

import cango.nstd.type_trans.true_tv;
import cango.nstd.type_trans.false_tv;

export namespace cango {

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