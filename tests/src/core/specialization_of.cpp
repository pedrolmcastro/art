#include <string>
#include <complex>

#include "art/core/specialization_of.hpp"


using namespace std;
using namespace art;


struct derived_from_complex final : complex<float> {};


static_assert(not specialization_of<float, complex>);
static_assert(    specialization_of<complex<float>, complex>);
static_assert(not specialization_of<basic_string<char>, complex>);
static_assert(not specialization_of<complex<float> const, complex>);
static_assert(not specialization_of<derived_from_complex, complex>);


int main() {}
