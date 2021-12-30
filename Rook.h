#include "Utility.h"
#include "Piece.h"
class Rook : public Piece
{
public:
    Rook();
    ~Rook();
    virtual bool pieceLegality(string position) const override;
};
