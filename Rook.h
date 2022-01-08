#pragma once
#include "Utility.h"
#include "Piece.h"

class Rook : public Piece
{
private:
    bool _canCastle;
public:
    Rook(bool isWhite);
    ~Rook();
    virtual bool pieceLegality(const string route, Piece*** board) override;

    // getters & setters
    bool canCastle() const;
    void setCastleFlag(const bool newState);
};
