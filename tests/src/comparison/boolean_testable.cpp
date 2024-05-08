#include <memory>
#include <vector>

#include "art/comparison/boolean_testable.hpp"


using namespace std;
using namespace art;


static_assert(    boolean_testable<bool>);
static_assert(    boolean_testable<double>);
static_assert(not boolean_testable<unique_ptr<bool>>);
static_assert(    boolean_testable<bool const volatile&>);
static_assert(    boolean_testable<vector<bool>::reference>);


int main() {}
