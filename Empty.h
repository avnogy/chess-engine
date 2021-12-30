#include "Utility.h"
#include "Piece.h"
class Empty: public Piece
{
public:
    Empty(bool isWhite, string position);
    ~Empty();
    virtual bool pieceLegality(string position) const override;
};
