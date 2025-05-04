#include "basic.hpp"
#include "type.hpp"
#include <compare>
#include <concepts>
#include <stdexcept>

namespace rash {

template <typename T>
concept HasThreeWayComparison = requires(T a, T b) {
    { a <=> b } -> std::same_as<std::strong_ordering>;
};

template <typename T>
class ComparableBase {
    static_assert(HasThreeWayComparison<T>,
        "Derived class must implement operator<=> returning std::strong_ordering");
};

class DataBox {
public:
    virtual Type   type() = 0;
    virtual TypeId typeId() = 0;

    virtual u32 intValue()
    {
        throw new std::logic_error("unimplemented");
    }

    // question: should I return string or its reference?
    virtual std::string stringValue()
    {
        throw new std::logic_error("unimplemented");
    };
};

class IntDataBox : DataBox, public ComparableBase<DataBox> {
private:
    i32 value;

public:
    std::strong_ordering operator<=>(DataBox);
};
class StringDataBox : DataBox {
private:
};
}
