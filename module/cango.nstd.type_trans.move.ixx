export module cango.nstd.type_trans.move;

import cango.nstd.type_trans.remove_ref;

export namespace cango {

/// @brief 移动左值引用，返回目标的右值引用，用于触发移动构造和赋值
/// @tparam T 目标的类型
template<typename T>
constexpr remove_ref_t<T> &&move(T &&t) noexcept { return static_cast<remove_ref_t<T> &&>(t); }
};