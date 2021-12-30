#include "Utility.h"
#include "Piece.h"
class Knight : public Piece
{
public:
    Knight();
    ~Knight();
    virtual bool pieceLegality(string position) const override;
};
