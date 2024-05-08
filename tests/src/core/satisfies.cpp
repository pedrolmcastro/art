#include <concepts>
#include <type_traits>

#include "art/core/satisfies.hpp"


using namespace std;
using namespace art;


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


static_assert(    satisfied_by_all_of<[]<signed_integral>{}>);
static_assert(    satisfied_by_all_of<[]<signed_integral>{}, int>);
static_assert(not satisfied_by_all_of<[]<signed_integral>{}, unsigned>);
static_assert(not satisfied_by_all_of<[]<signed_integral>{}, int, unsigned>);

static_assert(not satisfied_by_any_of<[]<signed_integral>{}>);
static_assert(    satisfied_by_any_of<[]<signed_integral>{}, int>);
static_assert(not satisfied_by_any_of<[]<signed_integral>{}, unsigned>);
static_assert(    satisfied_by_any_of<[]<signed_integral>{}, int, unsigned>);

static_assert(    satisfied_by_none_of<[]<signed_integral>{}>);
static_assert(not satisfied_by_none_of<[]<signed_integral>{}, int>);
static_assert(    satisfied_by_none_of<[]<signed_integral>{}, unsigned>);
static_assert(not satisfied_by_none_of<[]<signed_integral>{}, int, unsigned>);


int main() {}
