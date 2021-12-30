#include "Utility.h"

class Rook
{
public:
    Rook();
    ~Rook();
    virtual bool pieceLegality(string position) const override;
};
