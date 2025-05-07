#include <cassert>
#include <print>
#include "databox.hpp"
int main() {
    std::println("hello");
    
    rash::IntDataBox ib1(1);
    rash::IntDataBox ib2(2);
    assert((ib1 <=> ib2) < 0);
}