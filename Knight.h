#pragma once
#include "Utility.h"
#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(bool isWhite);
    ~Knight();
    virtual bool pieceLegality(const string route, Piece*** board) const override;
};
