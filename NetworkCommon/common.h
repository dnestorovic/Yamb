#ifndef COMMON_H
#define COMMON_H

#include <asio.hpp>
#include <chrono>
#include <deque>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

typedef uint64_t owner_t;
typedef uint64_t game_t;

const int ROLLS_PER_MOVE = 3;
const int NUM_OF_DICE = 6;

const owner_t NONAME_PLAYER_ID = 0;
const game_t WAITING_ROOM_ID = 0;

#endif  // COMMON_H
