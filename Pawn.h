#include "Utility.h"
#include "Piece.h"
class Pawn : public Piece
{
public:
    Pawn();
    ~Pawn();
    virtual bool pieceLegality(string position) const override;
};
