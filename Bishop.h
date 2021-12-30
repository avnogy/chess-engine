#include "Utility.h"
#include "Piece.h"
class Bishop : public Piece
{
public:
    Bishop(bool isWhite, string position);
    ~Bishop();
    virtual bool pieceLegality(string position) const override;
};
