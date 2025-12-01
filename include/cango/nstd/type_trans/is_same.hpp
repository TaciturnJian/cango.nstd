#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_IS_SAME
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_IS_SAME

#include "false_tv.hpp"
#include "true_tv.hpp"

namespace cango::nstd::type_trans {
template<typename, typename>
struct is_same : false_tv {};

template<typename T>
struct is_same<T, T> : true_tv {};

template<typename TL, typename TR>
inline constexpr bool is_same_v = is_same<TL, TR>::value;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_IS_SAME
