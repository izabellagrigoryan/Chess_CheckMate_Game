
#include "Chess_Game.h"

int main()
{
    Game* game = new ChessGameCheckMate();
    game->start();

    delete game;
    return 0;
}