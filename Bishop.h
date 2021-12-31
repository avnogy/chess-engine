#include "Utility.h"
#include "Piece.h"
class Bishop : public Piece
{
public:
    Bishop(bool isWhite);
    ~Bishop();
    virtual bool pieceLegality(const string route) const override;
};
