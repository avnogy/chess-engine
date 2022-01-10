#pragma once
#include "Utility.h"
#include "Piece.h"

class King : public Piece
{
private:
    bool _canCastle;
public:
    King(bool isWhite);
    ~King();
    virtual int pieceLegality(const string route, Piece*** board) override;

    // getters & setters
    bool canCastle() const;
    void setCastleFlag(const bool newState);
};
