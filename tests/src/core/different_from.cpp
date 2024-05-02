#include "art/core/different_from.hpp"


using art::different_from, art::different_from_all_of;


static_assert(not different_from<char, char>);
static_assert(    different_from<char, double>);
static_assert(    different_from<char, char volatile>);

static_assert(    different_from_all_of<char>);
static_assert(not different_from_all_of<char, char>);
static_assert(    different_from_all_of<char, double>);
static_assert(    different_from_all_of<char, char&, char&&>);
static_assert(not different_from_all_of<char, signed char, unsigned char, char>);


int main() {}
