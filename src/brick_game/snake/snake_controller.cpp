#include "snake_controller.h"

namespace s21 {

SnakeController::SnakeController(SnakeGame& game, CLIView& view)
    : game_(game), view_(view) {}

SnakeController::~SnakeController() {
    game_.~SnakeGame();
    view_.~CLIView();
    exit(0);
}

void SnakeController::run() {
    while (true) {
        GameInfo& game_info = game_.get_game_info();
        view_.render(game_info);
        delete &game_info;

        CLIView::Input input_result = view_.get_input(game_.get_time_left());

        if (input_result.action_ == UserAction::Terminate) {
            this->~SnakeController();
        } else if (input_result.has_action_ == true) {
            game_.user_input(input_result.action_, input_result.hold_);
        } else {
            game_.move();
        }
    }
}

}  // namespace s21
