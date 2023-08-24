#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include <iostream>
#include "Figures.h"

class Game {
public:
    virtual void start() = 0;
    virtual void stop() = 0;

    Game() = default;
    virtual ~Game() {};
};

class ChessGame :public Game {
private:
    void init();
    void init_square();
    void draw_board();
public:
    int m_figures_count = 0;
    std::vector<Figure*> m_figures;
    ChessBoard* m_chess_board;

    enum class latin_letters { A = 1, B, C, D, E, F, G, H };
    int convert_to_int(char st);
    char convert_to_char(int i);
    bool isMate = false;
    bool isCheck = false;
    bool isStale = false;
    bool isNearWhiteKing = false;
    Pair bkxy;
    Pair wkxy;

    std::vector<Pair> allLegalMoves;
    std::vector<Pair> allLegalMovesAllFigures;
    std::vector<Pair> allLegalMovesBlackKing;

    void start() override = 0;
    void stop() override = 0;

    ChessGame();
    ~ChessGame() override;
};

class ChessGameCheckMate :public ChessGame {
public:
    void start() override;
    void stop() override {}

    ChessGameCheckMate() = default;
    ~ChessGameCheckMate() override {}
    ChessGameCheckMate(const ChessGameCheckMate&) = delete;
    ChessGameCheckMate(ChessGameCheckMate&&) = delete;
    ChessGameCheckMate& operator=(const ChessGameCheckMate&) = delete;
    ChessGameCheckMate& operator=(ChessGameCheckMate&&) = delete;

    Pair getBlackKingPlace(std::vector<Figure*> &m_figures);
    Pair getWhiteKingPlace(std::vector<Figure*> &m_figures);
    void setBlackKingPlace(std::vector<Figure*> &m_figures, Pair xy);
    void setWhiteKingPlace(std::vector<Figure*> &m_figures, Pair xy);
    
    bool checkAreKingsNear(Pair bkxy, Pair wkxy);
    bool checkings();
    void checkMateForBlackKing();
    void checkMateForBlackKing(std::vector<Figure*> m_figures, ChessBoard& m_board);
    bool checkMateForWhiteKing() { return false; }
};

#endif