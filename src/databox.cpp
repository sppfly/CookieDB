#include "databox.hpp"
#include <compare>

namespace CookieDB {
const Type IntDataBox::type() const
{
    return Type::intType();
}

TypeId IntDataBox::typeId() const
{
    return TypeId::INT;
}

i32 IntDataBox::intValue() const {
    return value;
}

std::strong_ordering IntDataBox::operator<=>(const IntDataBox& rhs) {
    return this->value<=>rhs.value;
}
}
