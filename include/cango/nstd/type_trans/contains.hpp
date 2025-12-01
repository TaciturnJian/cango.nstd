#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_CONTAINS
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_CONTAINS

#include "target_at.hpp"

namespace cango::nstd::type_trans {
template<typename TTarget, typename... TList>
using contains = any_of<target_at<TTarget>::template is_target, false, TList...>;

/// @brief 判断目标类型在给定的类型列表中是否存在
/// @tparam TTarget 目标类型
/// @tparam TList 待检查的类型列表
template<typename TTarget, typename... TList>
inline constexpr bool contains_v = contains<TTarget, TList...>::value;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_CONTAINS
