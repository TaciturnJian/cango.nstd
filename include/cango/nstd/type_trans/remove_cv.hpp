#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_CV
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_CV

#include "remove_c.hpp"
#include "remove_v.hpp"

namespace cango::nstd::type_trans {
template<typename T>
using remove_cv = remove_v<remove_c_t<T> >;

template<typename T>
using remove_cv_t = remove_cv<T>::type;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_CV
