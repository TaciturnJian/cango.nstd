export module cango.nstd.type_trans.just_type;
export namespace cango {
/// @brief 内部只有给定类型作为类型成员 type
/// @tparam T 成员 type 的类型
template<typename T>
struct just_type {
    using type = T;
};
}
