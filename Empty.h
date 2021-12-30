#include "Utility.h"
#include "Piece.h"
class Empty: public Piece
{
public:
    Empty(string position);
    ~Empty();
    virtual bool pieceLegality(string position) const override;
};
