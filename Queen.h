#pragma once
#include "Utility.h"
#include "Piece.h"

class Queen : public Piece
{
public:
    //constructor & destructor
    Queen(bool isWhite);
    ~Queen();

    //methods
    virtual int pieceLegality(const string route, Piece*** board) override;
};
