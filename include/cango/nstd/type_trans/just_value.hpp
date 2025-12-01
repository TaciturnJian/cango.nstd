#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_JUST_VALUE
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_JUST_VALUE

namespace cango::nstd::type_trans {
/// @brief 内部只有给定值的静态常量成员 value
/// @tparam T 给定值的类型
/// @tparam V 成员 value 的值
template<typename T, T V>
struct just_value {
    static constexpr T value = V;
};
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_JUST_VALUE
