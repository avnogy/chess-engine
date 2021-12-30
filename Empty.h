#include "Utility.h"

class Empty
{
public:
    Empty();
    ~Empty();
    virtual bool pieceLegality(string position) const override;
};
