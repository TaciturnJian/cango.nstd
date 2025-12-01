#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_AND
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_AND

#include "false_tv.hpp"
#include "true_tv.hpp"

namespace cango::nstd::type_trans {
template<typename...>
struct logic_and : true_tv {};

template<typename... TRest>
struct logic_and<false_tv, TRest...> : false_tv {};

template<typename... TRest>
struct logic_and<true_tv, TRest...> : logic_and<TRest...> {};

template<typename... TList>
inline constexpr bool logic_and_v = logic_and<TList...>::value;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_AND
