export module cango.nstd.type_trans.just_value;
export namespace cango {
/// @brief 内部只有给定值的静态常量成员 value
/// @tparam T 给定值的类型
/// @tparam V 成员 value 的值
template<typename T, T V>
struct just_value {
    static constexpr T value = V;
};
}
