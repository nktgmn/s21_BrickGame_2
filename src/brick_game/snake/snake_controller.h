#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

#include "snake_game.h"
#include "snake_view.h"

namespace s21 {

class SnakeController {
   public:
    SnakeController(SnakeGame& game, SnakeView& view);
    ~SnakeController();

    void run();

   private:
    SnakeGame& game_;
    SnakeView& view_;
};

}  // namespace s21

#endif