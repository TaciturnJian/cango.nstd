#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_REF_CV
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_REF_CV

#include "remove_cv.hpp"
#include "remove_ref.hpp"

namespace cango::nstd::type_trans {
template<typename T>
using remove_ref_cv = remove_cv<remove_ref_t<T> >;

template<typename T>
using remove_ref_cv_t = remove_ref_cv<T>::type;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_REF_CV
