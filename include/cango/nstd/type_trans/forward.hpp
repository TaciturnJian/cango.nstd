#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_FORWARD
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_FORWARD

#include "remove_ref.hpp"

namespace cango::nstd::type_trans {
/// @brief 利用应用折叠，保持参数的引用类型到结果
/// @tparam T 目标的类型
template<typename T>
constexpr T &&forward(remove_ref_t<T> &t) noexcept { return static_cast<T &&>(t); }
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_FORWARD
