#pragma once
#include "Utility.h"
#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(bool isWhite);
    ~Knight();
    virtual int pieceLegality(const string route, Piece*** board) override;
};
