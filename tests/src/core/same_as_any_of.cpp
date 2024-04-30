#include <type_traits>

#include "art/core/same_as_any_of.hpp"


using art::same_as_any_of, art::transform_same_as_any_of, std::make_signed_t;


static_assert(not same_as_any_of<int>);
static_assert(    same_as_any_of<int, int>);
static_assert(not same_as_any_of<int, unsigned>);
static_assert(not same_as_any_of<int, int const>);
static_assert(    same_as_any_of<int, short, int, long, long long>);

static_assert(not transform_same_as_any_of<unsigned, make_signed_t>);
static_assert(    transform_same_as_any_of<unsigned, make_signed_t, int>);
static_assert(not transform_same_as_any_of<unsigned, make_signed_t, unsigned>);
static_assert(not transform_same_as_any_of<unsigned, make_signed_t, int const>);
static_assert(    transform_same_as_any_of<unsigned, make_signed_t, short, int, long, long long>);


int main() {}
