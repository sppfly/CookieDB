#include <stdexcept>
#include <string>
#include <vector>

#include "basic.hpp"
#include "type.hpp"

namespace CookieDB {


class Tuple {
public:
    std::vector<DataBox>& values();
    DataBox               value(int);
    Tuple                 concat(const Tuple&);

private:
    std::vector<DataBox> data;
};
} // namespace CookieDB
