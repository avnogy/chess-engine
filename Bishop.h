#include "Utility.h"
#include "Piece.h"
class Bishop : public Piece
{
public:
    Bishop();
    ~Bishop();
    virtual bool pieceLegality(string position) const override;
};
