export module cango.nstd.type_trans.remove_ref_cv;

import cango.nstd.type_trans.remove_cv;
import cango.nstd.type_trans.remove_ref;

export namespace cango {
template<typename T>
using remove_ref_cv = remove_cv<remove_ref_t<T> >;

/// @brief 移除目标类型的 const volatile 和引用修饰
/// @tparam T 目标类型
template<typename T>
using remove_ref_cv_t = remove_ref_cv<T>::type;
};
