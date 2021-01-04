#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <limits>
#include <random>

#include "Message.h"
#include "common.h"

template <typename T>
static T generate_id() {
  // Generate a single random number which is then used as a seed.
  std::random_device rand;

  // Initialize the generator with a seed, which generates 64-bit pseudorandom
  // integers.
  std::mt19937_64 generator(rand());
  std::uniform_int_distribution<T> dist(1, std::numeric_limits<T>::max());

  return dist(generator);
}

// Simulation of rolling one dice.
static uint8_t roll_the_dice() {
  // Generate a single random number which is then used as a seed.
  std::random_device rand;

  // Initialize the generator with a seed, which generates 32-bit pseudorandom
  // integers.
  std::mt19937 generator(rand());
  std::uniform_int_distribution<int> dist(1, NUM_OF_DICE);

  uint8_t new_dice_value = dist(generator);

  return new_dice_value;
}

#endif  // RANDOMGENERATOR_H
