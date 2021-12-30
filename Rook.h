#include "Utility.h"
#include "Piece.h"
class Rook : public Piece
{
public:
    Rook(bool isWhite, string position);
    ~Rook();
    virtual bool pieceLegality(string position) const override;
};
