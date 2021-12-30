#include "Utility.h"

class Pawn
{
public:
    Pawn();
    ~Pawn();
    virtual bool pieceLegality(string position) const override;
};
