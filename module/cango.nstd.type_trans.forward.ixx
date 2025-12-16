export module cango.nstd.type_trans.forward;

import cango.nstd.type_trans.remove_ref;

export namespace cango {
/// @brief 利用应用折叠，保持参数的引用类型到结果
/// @tparam T 目标的类型
template<typename T>
constexpr T &&forward(remove_ref_t<T> &t) noexcept { return static_cast<T &&>(t); }
}