#include <iostream>
#include "unit_testing.h"
#include <assert.h>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define LOG_TAG "[UNIT_TESTING]"

#ifdef DEBUG
#define DBG_LOG(fmt, ...) printf(LOG_TAG " [D] <%s:%d> " fmt "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define DBG_LOG(fmt)
#endif

// If parameter is not true, test fails
// This check function would be provided by the test framework
#define IS_TRUE(x)               \
    {                            \
        if (!(x))                \
        {                        \
            DBG_LOG(" failed "); \
        }                        \
    }

// Test for function1()
// You would need to write these even when using a framework

// int main(void)
// {
//     // Call all tests. Using a test framework would simplify this.
//     test_function1();
//     std::cout << "finished \n";
// }

// Function to test
bool function1(int a)
{
    return a > 5;
}

// Input cases should enter here
void test_function1()
{
    IS_TRUE(function1(0));
    IS_TRUE(function1(5));
    IS_TRUE(function1(10));

    // Assert Library could using for unit tests.
    // Program will stop running and throw aborted error.
    // assert(function1(0));
}

int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("testing the factorial function")
{
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}

TEST_CASE("testing the function1 function")
{
    CHECK(function1(10) == true);
    CHECK(function1(5) == true);
    CHECK(function1(1) == true);
}
