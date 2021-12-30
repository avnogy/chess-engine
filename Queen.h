#include "Utility.h"
#include "Piece.h"
class Queen : public Piece
{
public:
    Queen();
    ~Queen();
    virtual bool pieceLegality(string position) const override;
};
