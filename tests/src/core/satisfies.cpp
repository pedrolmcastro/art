#include <concepts>
#include <type_traits>

#include "art/core/satisfies.hpp"


using std::make_signed_t, std::signed_integral, std::unsigned_integral;

using art::satisfies, art::satisfies_after, art::satisfies_all_of, art::satisfies_any_of, art::satisfies_none_of;


static_assert(not satisfies<int, 0>); // Not the intended usage
static_assert(    satisfies<int, []<signed_integral>{}>);
static_assert(not satisfies<int, []<unsigned_integral>{}>);

static_assert(    satisfies_after<int, make_signed_t, []<signed_integral>{}>);
static_assert(not satisfies_after<int, make_signed_t, []<unsigned_integral>{}>);
static_assert(    satisfies_after<unsigned, make_signed_t, []<signed_integral>{}>);
static_assert(not satisfies_after<unsigned, make_signed_t, []<unsigned_integral>{}>);

static_assert(    satisfies_all_of<int>);
static_assert(    satisfies_all_of<int, []<signed_integral>{}>);
static_assert(not satisfies_all_of<int, []<unsigned_integral>{}>);
static_assert(not satisfies_all_of<int, []<signed_integral>{}, []<unsigned_integral>{}>);

static_assert(not satisfies_any_of<int>);
static_assert(    satisfies_any_of<int, []<signed_integral>{}>);
static_assert(not satisfies_any_of<int, []<unsigned_integral>{}>);
static_assert(    satisfies_any_of<int, []<signed_integral>{}, []<unsigned_integral>{}>);

static_assert(    satisfies_none_of<int>);
static_assert(not satisfies_none_of<int, []<signed_integral>{}>);
static_assert(    satisfies_none_of<int, []<unsigned_integral>{}>);
static_assert(not satisfies_none_of<int, []<signed_integral>{}, []<unsigned_integral>{}>);


int main() {}
