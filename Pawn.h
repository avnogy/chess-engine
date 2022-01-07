#pragma once
#include "Utility.h"
#include "Piece.h"
#include "Engine.h" // for method isOutOfBounds

#define WHITE_INITIAL_ROW '2'
#define BLACK_INITIAL_ROW '7'

class Pawn : public Piece
{
private:
    bool _enPassantFlag; // google en passant
public:
    Pawn(bool isWhite);
    ~Pawn();
    virtual bool pieceLegality(const string route, Piece*** board) const override;
    
    bool canTakeEnPassant() const; // holy hell
    void setEnPassantFlag(bool newState);
};
