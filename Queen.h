#pragma once
#include "Utility.h"
#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(bool isWhite);
    ~Queen();
    virtual bool pieceLegality(const string route) const override;
};
