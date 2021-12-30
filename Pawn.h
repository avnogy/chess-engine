#include "Utility.h"
#include "Piece.h"
class Pawn : public Piece
{
public:
    Pawn(bool isWhite, string position);
    ~Pawn();
    virtual bool pieceLegality(string position) const override;
};
