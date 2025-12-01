#include <cango/nstd.hpp>

using namespace cango::nstd::type_trans;

static_assert(modify<int>::add_const::same_as_v<const int>);
static_assert(modify<int>::add_volatile::same_as_v<volatile int>);
static_assert(modify<int>::add_lv_ref::same_as_v<int &>);
static_assert(modify<int>::add_rv_ref::same_as_v<int &&>);
static_assert(modify<int>::add_const::add_lv_ref::same_as_v<const int &>);
static_assert(modify<int>::add_const::add_rv_ref::same_as_v<const int &&>);
static_assert(modify<const int &>::sub_ref::same_as_v<const int>);
static_assert(modify<volatile const int &>::sub_ref_cv::same_as_v<int>);

static_assert(pile<int, float, double>::element_count == 3);
static_assert(pile<int, float, double>::contains_type<int>);
static_assert(is_same_v<pile<int, float, double>::type_at<2>, double>);

int main() {
    constexpr auto nums = make_pile(1, 'c', 3.0);
    return nums.get<2>();
}
