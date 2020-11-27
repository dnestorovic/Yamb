#ifndef GAMEIDGENERATOR_HPP
#define GAMEIDGENERATOR_HPP

#include <random>
#include <limits.h>
#include "Message.hpp"

#define NUM_OF_DICE (6)

// Every game will have unique ID that will be used for connecting two players
static owner_t generate_game_id()
{
    // Generate a single random number which is then used as a seed
    std::random_device rand;

    // Initialize the generator with a seed, which generates 64-bit pseudorandom integers
    std::mt19937_64 generator(rand());
    std::uniform_int_distribution<int> dist(1, INT_MAX);    

    return dist(generator);
}

// Simulation of rolling the six dice
static int* roll_the_dice()
{
    // Generate a single random number which is then used as a seed
    std::random_device rand;

    // Initialize the generator with a seed, which generates 32-bit pseudorandom integers
    std::mt19937 generator(rand());
    std::uniform_int_distribution<int> dist(1, NUM_OF_DICE);

    static int32_t dice[NUM_OF_DICE];
    for (size_t i = 0; i < NUM_OF_DICE; i++)
    {
        dice[i] = dist(generator);
    }

    return dice;
}

#endif