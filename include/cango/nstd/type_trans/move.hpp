#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_MOVE
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_MOVE

#include "remove_ref.hpp"

namespace cango::nstd::type_trans {
/// @brief 移动左值引用，返回目标的右值引用，用于触发移动构造和赋值
/// @tparam T 目标的类型
template<typename T>
constexpr remove_ref_t<T> &&move(T &&t) noexcept { return static_cast<remove_ref_t<T> &&>(t); }
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_MOVE
