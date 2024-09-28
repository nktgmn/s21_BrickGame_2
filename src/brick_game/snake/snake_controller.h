#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

#include "snake_game.h"
#include "../../gui/cli/cli_view.h"

namespace s21 {

class SnakeController {
   public:
    SnakeController(SnakeGame& game, CLIView& view);
    ~SnakeController();

    void run();

   private:
    SnakeGame& game_;
    CLIView& view_;
};

}  // namespace s21

#endif