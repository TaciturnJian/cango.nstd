#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_IS_RV_REF
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_IS_RV_REF

#include "false_tv.hpp"
#include "true_tv.hpp"

namespace cango::nstd::type_trans {
template<typename>
struct is_right_value_reference : false_tv {};

template<typename T>
struct is_right_value_reference<T &&> : true_tv {};

template<typename T>
using is_rv_ref = is_right_value_reference<T>;

template<typename T>
inline constexpr bool is_right_value_reference_v = is_rv_ref<T>::value;

template<typename T>
inline constexpr bool is_rv_ref_v = is_right_value_reference_v<T>;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_IS_RV_REF
