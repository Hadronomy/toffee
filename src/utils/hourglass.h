/**
 * @file hourglass.h
 * @author Pablo Hernández Jiménez (alu0101495934@ull.edu.es)
 * @brief 
 * @version 1.0
 * @date 2021-11-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <chrono>
#include <stack>

#ifndef LIB_HOURGLASS
#define LIB_HOURGLASS

namespace utils {

/**
 * @brief A utility class for managing time
 * 
 */
class Hourglass {
 public:
  /**
   * @brief Starts the hourglass,
   * this will add a new hourglass to the active timers.
   * 
   */
  static void Start();

  /**
   * @brief Stops the most recently started hourglass and returns it 
   * @return Hourglass 
   */
  static Hourglass Stop();

  /**
   * @brief Returns the elapsed from starting the hourglass and ending it
   * @return double 
   */
  double Elapsed() const;

 private:
  Hourglass();
  
 private:
  static std::stack<Hourglass> timers_;

  using clock_t = std::chrono::high_resolution_clock;
  using second_t = std::chrono::duration<double, std::ratio<1>>;

  std::chrono::time_point<clock_t> start_;
  std::chrono::time_point<clock_t> end_;
};

}

#endif
