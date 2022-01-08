#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop(bool isWhite);
    ~Bishop();
    virtual bool pieceLegality(const string route, Piece*** board) override;
};
