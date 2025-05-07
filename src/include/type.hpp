#include "basic.hpp"
#include <expected>
#include <string>

namespace rash {

enum class TypeId {
    INT,
    STRING
};

class Type {

private:
    TypeId typeId;
    u32    sizeInBytes;

public:
    Type(TypeId typeId, u32 sizeInBytes);
    const TypeId& getTypeId() const;
    u32           getSizeInBytes() const;

    static Type                             intType();
    static std::expected<Type, std::string> stringType(u32);
};

}
