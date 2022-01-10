#pragma once
#include "Utility.h"
#include "Piece.h"

#define WHITE_INITIAL_ROW '2'
#define BLACK_INITIAL_ROW '7'

class Pawn : public Piece
{
private:
    bool _enPassantFlag; // google en passant
public:
    Pawn(bool isWhite);
    ~Pawn();
    virtual int pieceLegality(const string route, Piece*** board) override;

    // getters & setters
    bool canBeTakenEnPassant() const;
    void setEnPassantFlag(const bool newState);
};
