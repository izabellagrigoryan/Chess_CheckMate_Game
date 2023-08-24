#include "Figures.h"

std::vector<Pair> Bishop::AllLegalMoves(ChessBoard& my_board, Pair xy, Pair kingsxy)
{
    std::vector<Pair> allLegalMoves;

    int x_curr = xy.getX();
    int y_curr = xy.getY();

    int x = x_curr;
    int y = y_curr;

    while ((x - 1) >= 0 && (y - 1) >= 0 && (my_board.isOccupied(x - 1, y - 1) || Pair(x - 1, y - 1) == kingsxy))
    {
        allLegalMoves.push_back(Pair(x - 1, y - 1));
        x--; y--;
    }
    x = x_curr;
    y = y_curr;

    while ((x - 1) >= 0 && (y + 1) < 8 && (my_board.isOccupied(x - 1, y + 1) || Pair(x - 1, y + 1) == kingsxy))
    {
        allLegalMoves.push_back(Pair(x - 1, y + 1));
        x--; y++;
    }
    x = x_curr;
    y = y_curr;

    while ((x + 1) < 8 && (y + 1) < 8 && (my_board.isOccupied(x + 1, y + 1) || Pair(x + 1, y + 1) == kingsxy))
    {
        allLegalMoves.push_back(Pair(x + 1, y + 1));
        x++; y++;
    }
    x = x_curr;
    y = y_curr;

    while ((x + 1) < 8 && (y - 1) >= 0 && (my_board.isOccupied(x + 1, y - 1) || Pair(x + 1, y - 1) == kingsxy))
    {
        allLegalMoves.push_back(Pair(x + 1, y - 1));
        x++; y--;
    }

    return allLegalMoves;
};

std::vector<Pair> Knight::AllLegalMoves(ChessBoard& my_board, Pair xy, Pair kingsxy)
{
    std::vector<Pair> allLegalMoves;

    int x = xy.getX();
    int y = xy.getY();

    if ((x - 1) >= 0)
    {
        if ((y - 2) >= 0 && (my_board.isOccupied(x - 1, y - 2) || Pair(x - 1, y - 2) == kingsxy))
            allLegalMoves.push_back(Pair(x - 1, y - 2));
        if ((y + 2) < 8 && (my_board.isOccupied(x - 1, y + 2) || Pair(x - 1, y + 2) == kingsxy))
            allLegalMoves.push_back(Pair(x - 1, y + 2));
    }
    if ((x + 2) < 8)
    {
        if ((y - 1) >= 0 && (my_board.isOccupied(x + 2, y - 1) || Pair(x + 2, y - 1) == kingsxy))
            allLegalMoves.push_back(Pair(x + 2, y - 1));
        if ((y + 1) < 8 && (my_board.isOccupied(x + 2, y + 1) || Pair(x + 2, y + 1) == kingsxy))
            allLegalMoves.push_back(Pair(x + 2, y + 1));
    }
    if ((x + 1) < 8)
    {
        if ((y + 2) < 8 && (my_board.isOccupied(x + 1, y + 2) || Pair(x + 1, y + 2) == kingsxy))
            allLegalMoves.push_back(Pair(x + 1, y + 2));
        if ((y - 2) >= 0 && (my_board.isOccupied(x + 1, y - 2) || Pair(x + 1, y - 2) == kingsxy))
            allLegalMoves.push_back(Pair(x + 1, y - 2));
    }
    if ((x - 2) >= 0)
    {
        if ((y + 1) < 8 && (my_board.isOccupied(x - 2, y + 1) || Pair(x - 2, y + 1) == kingsxy))
            allLegalMoves.push_back(Pair(x - 2, y + 1));
        if ((y - 1) >= 0 && (my_board.isOccupied(x - 2, y - 1) || Pair(x - 2, y - 1) == kingsxy))
            allLegalMoves.push_back(Pair(x - 2, y - 1));
    }

    return allLegalMoves;
};

std::vector<Pair> Queen::AllLegalMoves(ChessBoard& my_board, Pair xy, Pair kingsxy)
{
    std::vector<Pair> allLegalMoves;

    int x_curr = xy.getX();
    int y_curr = xy.getY();


    int x = x_curr;
    int y = y_curr;

    while ((x - 1) >= 0 && (y - 1) >= 0 && (my_board.isOccupied(x - 1, y - 1) || Pair(x - 1, y - 1) == kingsxy))
    {
        allLegalMoves.push_back(Pair(x - 1, y - 1));
        x--; y--;
    }

    x = x_curr;
    y = y_curr;
    while ((x - 1) >= 0 && (y + 1) < 8 && (my_board.isOccupied(x - 1, y + 1) || Pair(x - 1, y + 1) == kingsxy))
    {
        allLegalMoves.push_back(Pair(x - 1, y + 1));
        x--; y++;
    }

    x = x_curr;
    y = y_curr;
    while ((x + 1) < 8 && (y + 1) < 8 && (my_board.isOccupied(x + 1, y + 1) || Pair(x + 1, y + 1) == kingsxy))
    {
        allLegalMoves.push_back(Pair(x + 1, y + 1));
        x++; y++;
    }
    x = x_curr;
    y = y_curr;

    while ((x + 1) < 8 && (y - 1) >= 0 && (my_board.isOccupied(x + 1, y - 1) || Pair(x + 1, y - 1) == kingsxy))
    {
        allLegalMoves.push_back(Pair(x + 1, y - 1));
        x++; y--;
    }
    x = x_curr;
    y = y_curr;

    while ((x - 1) >= 0 && (my_board.isOccupied(x - 1, y) || Pair(x - 1, y) == kingsxy))
    {
        allLegalMoves.push_back(Pair(x - 1, y));
        x--;
    }
    x = x_curr;
    y = y_curr;

    while ((x + 1) < 8 && (my_board.isOccupied(x + 1, y) || Pair(x + 1, y) == kingsxy))
    {
        allLegalMoves.push_back(Pair(x + 1, y));
        x++;
    }
    x = x_curr;
    y = y_curr;

    while ((y - 1) >= 0 && (my_board.isOccupied(x, y - 1) || Pair(x, y - 1) == kingsxy))
    {
        allLegalMoves.push_back(Pair(x, y - 1));
        y--;
    }
    x = x_curr;
    y = y_curr;

    while ((y + 1) < 8 && (my_board.isOccupied(x, y + 1) || Pair(x, y + 1) == kingsxy))
    {
        allLegalMoves.push_back(Pair(x, y + 1));
        y++;
    }

    return allLegalMoves;
};

std::vector<Pair> King::AllLegalMoves(ChessBoard& my_board, Pair xy, Pair kingsxy)
{
    std::vector<Pair> allLegalMoves;

    int x = xy.getX();
    int y = xy.getY();

    if ((y - 1) >= 0)
    {
        //if (my_board.isOccupied(x, y - 1))
        {
            allLegalMoves.push_back(Pair(x, y - 1));
        }
        if ((x - 1) >= 0)// && my_board.isOccupied(x - 1, y - 1))
        {
            allLegalMoves.push_back(Pair(x - 1, y - 1));
        }
        if ((x + 1) < 8)// && my_board.isOccupied(x + 1, y - 1))
        {
            allLegalMoves.push_back(Pair(x + 1, y - 1));
        }
    }
    if ((x + 1) < 8)// && my_board.isOccupied(x + 1, y))
    {
        allLegalMoves.push_back(Pair(x + 1, y));
    }
    if ((x - 1) >= 0)// && my_board.isOccupied(x - 1, y))
    {
        allLegalMoves.push_back(Pair(x - 1, y));
    }
    if ((y + 1) < 8)
    {
       // if (my_board.isOccupied(x, y + 1))
        {
            allLegalMoves.push_back(Pair(x, y + 1));
        }
        if ((x + 1) < 8)// && my_board.isOccupied(x + 1, y + 1))
        {
            allLegalMoves.push_back(Pair(x + 1, y + 1));
        }
        if ((x - 1) >= 0)// && my_board.isOccupied(x - 1, y + 1))
        {
            allLegalMoves.push_back(Pair(x - 1, y + 1));
        }
    }

    return allLegalMoves;
};