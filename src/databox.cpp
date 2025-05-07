#include "databox.hpp"

namespace CookieDB {

IntDataBox::IntDataBox(i32 _value)
    : value(_value)
{
}

const Type IntDataBox::type() const
{
    return Type::intType();
}

TypeId IntDataBox::typeId() const
{
    return TypeId::INT;
}

i32 IntDataBox::intValue() const
{
    return value;
}

std::strong_ordering IntDataBox::operator<=>(const IntDataBox& rhs) const
{
    return value <=> rhs.value;
}

bool IntDataBox::operator==(const IntDataBox& rhs) const
{
    return value == rhs.value;
}
}
