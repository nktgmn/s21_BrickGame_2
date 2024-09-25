#include "snake_controller.h"

#include <unistd.h>

#include <iostream>

namespace s21 {

SnakeController::SnakeController(SnakeGame& game, SnakeView& view)
    : game_(game), view_(view) {}

SnakeController::~SnakeController() { exit(0); }

void SnakeController::run() {
    unsigned long long time_left = GAME_SPEED;

    while (true) {
        GameInfo game_info = game_.get_game_info();
        view_.render(game_info);
        std::pair<UserAction, unsigned long long> input_result =
            view_.get_input(time_left);
        if (input_result.second == 0) {
            game_.move();
            time_left = GAME_SPEED;
        } else {
            game_.user_input(input_result.first);
            time_left = input_result.second;
        }
    }
}

}  // namespace s21
