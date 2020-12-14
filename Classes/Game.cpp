#include "Game.h"

void Game::switch_turn(){

    if(player_turn == 1)
        player_turn = 2;
    else
        player_turn = 1;

}