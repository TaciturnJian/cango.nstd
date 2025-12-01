#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_CONTAINS
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_CONTAINS

#include "target_at.hpp"

namespace cango::nstd::type_trans {
template<typename TTarget, typename... TList>
using contains = any_of<target_at<TTarget>::template is_target, false, TList...>;

template<typename TTarget, typename... TList>
inline constexpr bool contains_v = contains<TTarget, TList...>::value;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_CONTAINS
