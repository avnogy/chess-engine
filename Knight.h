#pragma once
#include "Utility.h"
#include "Piece.h"

class Piece;

class Knight : public Piece
{
public:
    Knight(bool isWhite);
    ~Knight();
    virtual bool pieceLegality(const string route) const override;
};
