#pragma once
#include "Utility.h"
#include "Piece.h"

class King : public Piece
{
private:
    //fields
    bool _canCastle;
public:
    //constructor & destructor
    King(bool isWhite);
    ~King();

    //methods
    virtual int pieceLegality(const string route, Piece*** board) override;

    // getters & setters
    bool canCastle() const;
    void setCastleFlag(const bool newState);
};
