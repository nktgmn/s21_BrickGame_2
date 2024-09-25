#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <list>

#include "game_params.h"

namespace s21 {

enum class State { Start, Move, Pause, GameLost, GameWon };

enum class Direction {
    Up,
    Down,
    Left,
    Right,
};

enum class UserAction { Start, Pause, Terminate, Left, Right, Up, Down };

struct GameInfo {
    GameInfo();
    ~GameInfo();
    int** field;
    int score;
};

class SnakeGame {
   public:
    SnakeGame();

    GameInfo get_game_info();
    void user_input(UserAction action);

   public:
    class Point {
       public:
        Point(int x, int y);
        Point(const Point& other);

        bool operator==(const Point& other) const;
        bool operator!=(const Point& other) const;

       private:
        int x_;
        int y_;
        friend class SnakeGame;
    };

    class Snake {
       public:
        Snake();

       private:
        std::list<Point> body;
        Direction direction;
        friend class SnakeGame;
    };

    Point apple;
    Snake snake;
    State state;
    int score;

    bool can_turn(Direction direction);
    bool game_won();
    bool game_lost();
    Point get_new_head(Direction direction);
    void move();
    void turn(Direction direction);
};

}  // namespace s21

#endif