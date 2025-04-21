#include <vector>

#include "type.hpp"
namespace rash {

class DataBox {
public:
    virtual Type   type();

private:
};

class Tuple {
public:
        
    
private:
    std::vector<DataBox> data;
};
} // namespace rash
