#include "type.hpp"
#include <expected>
#include <string>

namespace rash {
Type::Type(TypeId typeId, u32 sizeInBytes)
    : typeId(typeId)
    , sizeInBytes(sizeInBytes)
{
}

u32 Type::getSizeInBytes() const
{
    return sizeInBytes;
}

const TypeId& Type::getTypeId() const
{
    return typeId;
}

Type Type::intType()
{
    return Type(TypeId::INT, sizeof(i32));
}

std::expected<Type, std::string> Type::stringType(u32 size)
{
    if (size <= 0) {
        return std::unexpected("size of string must be > 0");
    }
    return std::expected<Type, std::string>(Type(TypeId::STRING, size));
}

} // namespace rash
