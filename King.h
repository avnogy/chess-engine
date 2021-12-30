#include "Utility.h"

class King
{
public:
    King();
    ~King();
    virtual bool pieceLegality(string position) const override;
};
