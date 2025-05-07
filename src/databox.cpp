#include "databox.hpp"

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

bool IntDataBox::operator<(const IntDataBox& rhs) const {
    return this->value < rhs.value;
}

// auto IntDataBox::operator<=>(const IntDataBox& rhs) const {
//     return this->value<=>rhs.value;
// }
}
