#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <fstream>
#include <list>
#include <random>

#include "../../game_params.h"

#define NEW_LEVEL_TRESHOLD 5
#define MAX_LEVEL 10
#define SPEED 500
#define MIN_SPEED 100
#define SPEED_STEP 100

namespace s21 {

enum class State { Start, Move, Pause, GameLost, GameWon };

enum class Direction {
    Up,
    Down,
    Left,
    Right,
};

class SnakeGame {
   public:
    SnakeGame();

    GameInfo& get_game_info();
    void user_input(UserAction action, bool hold);
    void move();
    double get_time_left() const;

    class Point {
       public:
        Point(int x, int y);
        Point(const Point& other);

        Point& operator=(const Point& other);

        bool operator==(const Point& other) const;
        bool operator!=(const Point& other) const;

       private:
        int x_;
        int y_;
        friend class SnakeGame;
    };

    private:
    std::list<Point> snake_body;
    Direction snake_direction;
    Point apple;
    State state;
    int score;
    int level;
    int speed;
    int normal_speed;
    int max_score;
    std::chrono::time_point<std::chrono::steady_clock> timestamp;
    double time_left;

    bool game_won();
    bool game_lost();
    Point get_new_head(Direction direction);
    void turn(Direction direction);
    Point spawn_apple();
    void reinitialize_game();
    void update_level_and_max_score();
    int get_max_score();
    void refresh_timer();
};

}  // namespace s21

#endif