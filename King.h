#include "Utility.h"
#include "Piece.h"
class King : public Piece
{
public:
    King();
    ~King();
    virtual bool pieceLegality(string position) const override;
};
