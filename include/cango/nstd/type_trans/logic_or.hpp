#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_OR
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_OR

#include "false_tv.hpp"
#include "true_tv.hpp"

namespace cango::nstd::type_trans {
template<bool...>
struct logic_or : false_tv {};

template<bool... TRest>
struct logic_or<true, TRest...> : true_tv {};

template<bool... TRest>
struct logic_or<false, TRest...> : logic_or<TRest...> {};

template<bool... TList>
inline constexpr bool logic_or_v = logic_or<TList...>::value;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_OR
