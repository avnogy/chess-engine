#include "Utility.h"

class Queen
{
public:
    Queen();
    ~Queen();
    virtual bool pieceLegality(string position) const override;
};
