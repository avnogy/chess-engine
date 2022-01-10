#pragma once
#include "Utility.h"
#include "Piece.h"

class Empty: public Piece
{
public:
    Empty();
    ~Empty();
    virtual int pieceLegality(const string route, Piece*** board) override;
};
