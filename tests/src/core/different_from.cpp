#include "art/core/different_from.hpp"


using art::different_from;


static_assert(not different_from<char, char>);
static_assert(    different_from<char, double>);
static_assert(    different_from<char, char volatile>);


int main() {}
