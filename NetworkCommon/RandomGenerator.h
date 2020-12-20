#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <limits>
#include <random>

#include "Message.h"
#include "common.h"

template <typename T>
static T generate_id() {
  // Generate a single random number which is then used as a seed
  std::random_device rand;

  // Initialize the generator with a seed, which generates 64-bit pseudorandom
  // integers
  std::mt19937_64 generator(rand());
  std::uniform_int_distribution<T> dist(1, std::numeric_limits<T>::max());

  return dist(generator);
}

// Simulation of rolling the six dice
static std::vector<uint8_t> roll_the_dice(bool first_roll,
                                          uint8_t num_of_needed_dice) {
  // Generate a single random number which is then used as a seed
  std::random_device rand;

  // Initialize the generator with a seed, which generates 32-bit pseudorandom
  // integers
  std::mt19937 generator(rand());
  std::uniform_int_distribution<int> dist(1, NUM_OF_DICE);

  std::vector<uint8_t> dice(num_of_needed_dice);
  for (size_t i = 0; i < num_of_needed_dice; i++) {
    dice[i] = dist(generator);

    if (first_roll) dice[i] *= (-1);
  }

  return dice;
}

#endif  // RANDOMGENERATOR_H
