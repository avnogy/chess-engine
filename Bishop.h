#pragma once
#include "Piece.h"

class Piece;

class Bishop : public Piece
{
public:
    Bishop(bool isWhite);
    ~Bishop();
    virtual bool pieceLegality(const string route) const override;
};
