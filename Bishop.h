#include "Utility.h"

class Bishop
{
public:
    Bishop();
    ~Bishop();
    virtual bool pieceLegality(string position) const override;
};
