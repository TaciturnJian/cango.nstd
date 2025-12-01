#ifndef INCLUDE_CANGO_NSTD_TYPE_TRANS_PILE
#define INCLUDE_CANGO_NSTD_TYPE_TRANS_PILE

#include "count_of.hpp"
#include "forward.hpp"
#include "type_at.hpp"

namespace cango::nstd::type_trans {
template<typename...>
struct pile;

template<typename T>
struct pile<T> {
    using pile_type = pile;
    using top_type = T;
    top_type top;

    static constexpr unsigned int element_count = 1;

    template<typename T1>
    static constexpr bool contains_type = contains_v<T1, T>;

    template<unsigned int N>
    constexpr auto get() const noexcept {
        static_assert(N < 1, "给定的 N 越界，无法正确获取元素");
        return top;
    }

    template<unsigned int N>
    constexpr const auto &at() const noexcept {
        static_assert(N < 1, "给定的 N 越界，无法正确获取元素");
        return top;
    }

    template<unsigned int N>
    constexpr auto &at() noexcept {
        static_assert(N < 1, "给定的 N 越界，无法正确获取元素");
        return top;
    }
};

template<typename TFirst, typename... TRest>
struct pile<TFirst, TRest...> {
    using pile_type = pile;
    using top_type = TFirst;
    using subpile_type = pile<TRest...>;

    template<unsigned int N>
    using type_at = type_at_t<N, TFirst, TRest...>;

    static constexpr auto element_count = count_of_v<TFirst, TRest...>;

    template<typename T1>
    static constexpr bool contains_type = contains_v<T1, TFirst, TRest...>;

    top_type top;
    subpile_type subpile;

    template<unsigned int N>
    constexpr auto get() const noexcept {
        static_assert(N < element_count, "给定的 N 越界，无法正确获取元素");
        if constexpr (N == 0) return top;
        else return subpile.template get<N - 1>();
    }

    template<unsigned int N>
    constexpr const auto &at() const noexcept {
        static_assert(N < element_count, "给定的 N 越界，无法正确获取元素");
        if constexpr (N == 0) return top;
        else return subpile.template at<N - 1>();
    }

    template<unsigned int N>
    constexpr auto &at() noexcept {
        static_assert(N < element_count, "给定的 N 越界，无法正确获取元素");
        if constexpr (N == 0) return top;
        else return subpile.template at<N - 1>();
    }
};

template<typename... TList>
constexpr auto make_pile(TList &&... list) noexcept { return pile<TList...>{forward<TList>(list)...}; }
}

#endif//INCLUDE_CANGO_NSTD_TYPE_TRANS_PILE
