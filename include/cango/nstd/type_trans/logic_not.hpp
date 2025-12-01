#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_NOT
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_NOT

#include "false_tv.hpp"
#include "true_tv.hpp"

namespace cango::nstd::type_trans {
template<typename T>
struct logic_not;

template<>
struct logic_not<true_tv> : false_tv {};

template<>
struct logic_not<false_tv> : true_tv {};

template<typename T>
inline constexpr bool logic_not_v = logic_not<T>::value;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_LOGIC_NOT
