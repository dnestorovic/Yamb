#include "Game.h"

Game::Game()
    : player_on_turn(0),
      number_of_filled_columns(0),
      field_announced(Fields::None),
      announcement(false) {}

void Game::switch_turn() { player_on_turn = 1 - player_on_turn; }

void Game::add_player(Player *player) {
  player->set_pointer_data(&field_announced, &announcement,
                           &number_of_filled_columns);
  players.push_back(player);
}

void Game::play_move() { switch_turn(); }