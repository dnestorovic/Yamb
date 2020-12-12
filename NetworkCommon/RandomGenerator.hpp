#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include <random>
#include <limits>
#include "Message.hpp"

const int NUM_OF_DICE = 6;

// Every game will have unique ID that will be used for connecting two players
static owner_t generate_game_id()
{
    // Generate a single random number which is then used as a seed
    std::random_device rand;

    // Initialize the generator with a seed, which generates 64-bit pseudorandom integers
    std::mt19937_64 generator(rand());
    std::uniform_int_distribution<owner_t> dist(1, std::numeric_limits<owner_t>::max());    

    return dist(generator);
}

// Simulation of rolling the six dice
static std::vector<uint8_t> roll_the_dice(bool first_roll, uint8_t num_of_needed_dice)
{
    // Generate a single random number which is then used as a seed
    std::random_device rand;

    // Initialize the generator with a seed, which generates 32-bit pseudorandom integers
    std::mt19937 generator(rand());
    std::uniform_int_distribution<int> dist(1, NUM_OF_DICE);

    std::vector<uint8_t> dice(num_of_needed_dice);
    for (size_t i = 0; i < num_of_needed_dice; i++)
    {
        dice[i] = dist(generator);

        if(first_roll)
            dice[i] *= (-1);
    }

    return dice;
}

#endif