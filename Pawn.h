#pragma once
#include "Utility.h"
#include "Piece.h"

#define WHITE_INITIAL_ROW '2'
#define BLACK_INITIAL_ROW '7'

class Pawn : public Piece
{
public:
    Pawn(bool isWhite);
    ~Pawn();
    virtual bool pieceLegality(const string route, Piece*** board) const override;
};
