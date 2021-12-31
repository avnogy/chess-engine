#include "Utility.h"
#include "Piece.h"
class King : public Piece
{
public:
    King(bool isWhite);
    ~King();
    virtual bool pieceLegality(const string route) const override;
};
