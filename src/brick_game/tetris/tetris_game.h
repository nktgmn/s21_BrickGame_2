#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include <stdlib.h>
#include <sys/time.h>

#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <vector>

#include "../../game_params.h"

namespace s21 {

enum class State { Start, Move, Pause, GameLost, GameWon };

enum Block_type { ALPHA, BETA, GAMMA, DELTA, OMEGA, PSI, ZETA };

class TetrisGame {
   public:
    TetrisGame();

    GameInfo& updateCurrentState() const;
    void userInput(UserAction_t action, bool hold);
    double get_time_left() const;
    void move();

    int get_max_score() const;
    void initialize_game();

   private:
    struct Point {
        Point() : x_(0), y_(0) {}
        Point(int x, int y) : x_(x), y_(y) {}
        Point(const Point& other) : x_(other.x_), y_(other.y_) {}

        Point& operator=(const Point& other) {
            if (this != &other) {
                x_ = other.x_;
                y_ = other.y_;
            }
            return *this;
        }

        bool operator==(const Point& other) {
            return (x_ == other.x_ && y_ == other.y_);
        }

        int x_;
        int y_;
    };
    struct Block {
        Block();
        Block(const Block& other)
            : points_(other.points_),
              size_(other.size_),
              coordinates_(other.coordinates_) {}

        Block& operator=(const Block& other) {
            if (this != &other) {
                points_ = other.points_;
                size_ = other.size_;
                coordinates_ = other.coordinates_;
            }
            return *this;
        }

        std::vector<Point> points_;
        int size_;
        Point coordinates_;

        void rotate();
        void shift(int shift_x, int shift_y);
    };

    std::list<Point> field_points_;
    Block block;
    Block next_block;
    State state;
    int score;
    int level;
    int speed;
    int normal_speed;
    int max_score;
    std::chrono::time_point<std::chrono::steady_clock> timestamp;
    double time_left;

    void update_level_and_max_score();
    void refresh_timer();
    bool block_is_attached();
    bool can_move_block();

    bool attach_block();
    void consume_rows();
    bool game_lost();

    bool valid_coordinate(int x, int y) const;
};

}  // namespace s21

#endif