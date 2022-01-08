#pragma once
#include "Utility.h"
#include "Piece.h"
#include "Engine.h" // for method isOutOfBounds

#define WHITE_INITIAL_ROW '2'
#define BLACK_INITIAL_ROW '7'

class Pawn : public Piece
{
private:
    bool _canTakeEnPassant; // google en passant
    bool _canBeTakenEnPassant; // holy hell
public:
    Pawn(bool isWhite);
    ~Pawn();
    virtual bool pieceLegality(const string route, Piece*** board) const override;
    
    bool canTakeEnPassant() const;
    void setCanTakeEnPassant(bool newState);
    bool canBeTakenEnPassant() const;
    void setCanBeTakenEnPassant(bool newState);
};
