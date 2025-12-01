#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_JUST_VALUE
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_JUST_VALUE

namespace cango::nstd::type_trans {
template<typename T, T V>
struct just_value {
    static constexpr T value = V;
};
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_JUST_VALUE

