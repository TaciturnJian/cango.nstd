#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_REF
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_REF

#include "just_type.hpp"

namespace cango::nstd::type_trans {
template<typename T>
struct remove_reference : just_type<T> {};

template<typename T>
struct remove_reference<T &> : remove_reference<T> {};

template<typename T>
struct remove_reference<T &&> : remove_reference<T> {};

template<typename T>
using remove_ref = remove_reference<T>;

template<typename T>
using remove_reference_t = remove_ref<T>::type;

template<typename T>
using remove_ref_t = remove_reference_t<T>;
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_REMOVE_REF
