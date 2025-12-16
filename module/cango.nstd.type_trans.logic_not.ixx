export module cango.nstd.type_trans.logic_not;

import cango.nstd.type_trans.true_tv;
import cango.nstd.type_trans.false_tv;

export namespace cango {
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
};
