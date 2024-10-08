#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "brick_game/snake/snake_game.h"
#include "brick_game/tetris/tetris_game.h"
#include "gui/cli/cli_view.h"
#include "gui/desktop/desktop_view.h"

namespace s21 {
template <typename GameType, typename ViewType>
class GameController {
   public:
    GameController(GameType& game, ViewType& view) : game_(game), view_(view) {}

    ~GameController() {
        game_.~GameType();
        view_.~ViewType();
        exit(0);
    }

    void run() {
        while (true) {
            GameInfo& game_info = game_.updateCurrentState();
            view_.render(game_info);
            delete &game_info;

            Input input_result = view_.get_input(game_.get_time_left());

            if (input_result.action_ == UserAction_t::Terminate) {
                this->~GameController();
            } else if (input_result.has_action_ == true) {
                game_.userInput(input_result.action_, input_result.hold_);
            } else {
                game_.move();
            }
        }
    }

   private:
    GameType& game_;
    ViewType& view_;
};
}  // namespace s21

#endif