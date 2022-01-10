#pragma once
#include "Utility.h"
#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(bool isWhite);
    ~Queen();
    virtual int pieceLegality(const string route, Piece*** board) override;
};
