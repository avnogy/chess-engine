#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop(bool isWhite);
    ~Bishop();
    virtual int pieceLegality(const string route, Piece*** board) override;
};
