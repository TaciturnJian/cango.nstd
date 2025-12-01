#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_JUST_TYPE
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_JUST_TYPE

namespace cango::nstd::type_trans {
/// @brief 内部只有给定类型作为类型成员 type
/// @tparam T 成员 type 的类型
template<typename T>
struct just_type {
    using type = T;
};
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_JUST_TYPE
