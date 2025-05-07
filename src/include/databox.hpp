#include "basic.hpp"
#include "type.hpp"
#include <compare>
#include <concepts>
#include <stdexcept>

namespace CookieDB {

// template <typename T>
// concept HasThreeWayComparison = requires(T a, T b) {
//     { a <=> b } -> std::same_as<std::strong_ordering>;
// };

// template <typename T>
// class ComparableBase {
//     static_assert(HasThreeWayComparison<T>,
//         "Derived class must implement operator<=> returning std::strong_ordering");
// };

class DataBox {
public:
    virtual const Type type() const = 0;
    virtual TypeId     typeId() const = 0;

    i32 intValue()
    {
        throw std::logic_error("unimplemented");
    }

    // question: should I return string or its reference?
    std::string stringValue()
    {
        throw std::logic_error("unimplemented");
    }
};

class IntDataBox : DataBox {
private:
    i32 value;

public:
    explicit IntDataBox(i32);

    const Type type() const override;
    TypeId     typeId() const override;

    i32 intValue() const;

    bool operator<(const IntDataBox&) const;
    // auto operator<=>(const IntDataBox&) const;
};
}
