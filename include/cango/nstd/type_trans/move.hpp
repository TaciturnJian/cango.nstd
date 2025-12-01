#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_MOVE
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_MOVE

#include "remove_ref.hpp"

namespace cango::nstd::type_trans {
template<typename T>
constexpr remove_ref_t<T> &&move(T &&t) noexcept { return static_cast<remove_ref_t<T> &&>(t); }
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_MOVE
