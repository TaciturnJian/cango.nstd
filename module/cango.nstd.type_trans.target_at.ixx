export module cango.nstd.type_trans.target_at;

import cango.nstd.type_trans.is_same;

export namespace cango {
template<typename T>
struct target_at {
    using type = T;

    template<typename T1>
    using is_target = is_same<T1, T>;
};
}
