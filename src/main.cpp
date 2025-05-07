#include "databox.hpp"
#include <cassert>
#include <print>

int main()
{
    std::println("hello");

    CookieDB::IntDataBox ib1(1);
    CookieDB::IntDataBox ib2(2);
    assert(ib1 < ib2);
    assert(ib1 == ib2);
}
