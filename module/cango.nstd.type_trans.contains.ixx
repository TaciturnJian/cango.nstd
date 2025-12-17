export module cango.nstd.type_trans.contains;

import cango.nstd.type_trans.any_of;
import cango.nstd.type_trans.target_at;

export namespace cango {
template<typename TTarget, typename... TList>
using contains = any_of<target_at<TTarget>::template is_target, false, TList...>;

/// @brief 判断目标类型在给定的类型列表中是否存在
/// @tparam TTarget 目标类型
/// @tparam TList 待检查的类型列表
template<typename TTarget, typename... TList>
inline constexpr bool contains_v = contains<TTarget, TList...>::value;
}
