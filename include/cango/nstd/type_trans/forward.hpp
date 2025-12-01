#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_FORWARD
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_FORWARD

#include "remove_ref.hpp"

namespace cango::nstd::type_trans {
template<typename T>
constexpr T &&forward(remove_ref_t<T> &t) noexcept { return static_cast<T &&>(t); }
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_FORWARD
