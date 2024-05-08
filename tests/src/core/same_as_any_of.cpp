#include "art/core/same_as_any_of.hpp"


using namespace art;


static_assert(not same_as_any_of<int>);
static_assert(    same_as_any_of<int, int>);
static_assert(not same_as_any_of<int, unsigned>);
static_assert(not same_as_any_of<int, int const, unsigned const>);
static_assert(    same_as_any_of<int, short, int, long, long long>);


int main() {}
