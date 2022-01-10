#pragma once
#include "Utility.h"
#include "Piece.h"

class Knight : public Piece
{
public:
    //constructor & destructor
    Knight(bool isWhite);
    ~Knight();

    //methods
    virtual int pieceLegality(const string route, Piece*** board) override;
};
