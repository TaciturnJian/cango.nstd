#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_JUST_TYPE
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_JUST_TYPE

namespace cango::nstd::type_trans {
template<typename T>
struct just_type {
    using type = T;
};
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_JUST_TYPE
