#include "Utility.h"
#include "Piece.h"
class Queen : public Piece
{
public:
    Queen(bool isWhite, string position);
    ~Queen();
    virtual bool pieceLegality(string position) const override;
};
