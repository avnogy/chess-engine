#include "Utility.h"
#include "Piece.h"
class King : public Piece
{
public:
    King(bool isWhite, string position);
    ~King();
    virtual bool pieceLegality(string position) const override;
};
