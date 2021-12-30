#include "Utility.h"

class Knight
{
public:
    Knight();
    ~Knight();
    virtual bool pieceLegality(string position) const override;
};
