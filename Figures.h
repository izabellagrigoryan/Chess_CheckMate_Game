#ifndef FIGURES_H
#define FIGURES_H

#include "Board.h"
#include <vector>

class Figure
{
public:
    Pair m_place;
    char m_color;
    char m_name;

    char getName() { return m_name; }
    void setName(char name) { m_name = name; }
    char getColor() { return m_color; }
    void setColor(char color) { m_color = color; }
    Pair getPlace() { return m_place; }
    void setPlace(Pair xy) { m_place = xy; }

    virtual std::vector<Pair> AllLegalMoves(ChessBoard& my_board, Pair xy, Pair kingsxy) = 0 ;

    Figure(char color, char name, Pair place) {
        m_color = color;
        m_name = name;
        m_place = place;
    }
    virtual ~Figure() {}
};

class Pawn : public Figure
{
public:
    std::vector<Pair> AllLegalMoves(ChessBoard& my_board, Pair xy, Pair kingsxy) override { std::vector<Pair> allLegalMoves; return allLegalMoves; }

    Pawn(char color, char name, Pair place) :Figure(color, name, place) {}
    ~Pawn() override {}
};

class Rook : public Figure
{
public:
    std::vector<Pair> AllLegalMoves(ChessBoard& my_board, Pair xy, Pair kingsxy) override { std::vector<Pair> allLegalMoves; return allLegalMoves; }

    Rook(char color, char name, Pair place) :Figure(color, name, place){}
    ~Rook() override {}
};

class Bishop : public Figure
{
public:
    std::vector<Pair> AllLegalMoves(ChessBoard& my_board, Pair xy, Pair kingsxy) override;

    Bishop(char color, char name, Pair place) :Figure(color, name, place) {}
    ~Bishop() override {}
};

class Knight : public Figure
{
public:
    std::vector<Pair> AllLegalMoves(ChessBoard& my_board, Pair xy, Pair kingsxy) override;

    Knight(char color, char name, Pair place) :Figure(color, name, place) {}
    ~Knight() override {}
};

class Queen : public Figure
{
public:
    std::vector<Pair> AllLegalMoves(ChessBoard& my_board, Pair xy, Pair kingsxy) override;

    Queen(char color, char name, Pair place) :Figure(color, name, place) {}
    ~Queen() override {}
};

class King : public Figure
{
public:
    std::vector<Pair> AllLegalMoves(ChessBoard& my_board, Pair xy, Pair kingsxy) override;

    King(char color, char name, Pair place) :Figure(color, name, place) {}
    ~King() override {}
};

#endif