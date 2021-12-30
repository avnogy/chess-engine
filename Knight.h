#include "Utility.h"
#include "Piece.h"
class Knight : public Piece
{
public:
    Knight(bool isWhite, string position);
    ~Knight();
    virtual bool pieceLegality(string position) const override;
};
