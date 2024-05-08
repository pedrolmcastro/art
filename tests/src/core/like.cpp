#include "art/core/like.hpp"


using namespace art;


static_assert(    like<float, float>);
static_assert(not like<float, double>);
static_assert(    like<float, float const volatile&>);

static_assert(not like_any_of<float>);
static_assert(    like_any_of<float, float&>);
static_assert(not like_any_of<float, double>);
static_assert(not like_any_of<float, double volatile, long double volatile>);
static_assert(    like_any_of<float, long double const, double const, float const>);


static_assert(not unlike<float, float>);
static_assert(    unlike<float, double>);
static_assert(not unlike<float, float const volatile&>);

static_assert(    unlike_all_of<float>);
static_assert(not unlike_all_of<float, float&>);
static_assert(    unlike_all_of<float, double>);
static_assert(    unlike_all_of<float, double volatile, long double volatile>);
static_assert(not unlike_all_of<float, long double const, double const, float const>);


int main() {}
