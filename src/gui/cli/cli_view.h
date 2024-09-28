#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H

#include <ncurses.h>
#include <string>

#include "../../game_params.h"

#define ACTION_BUTTON 32
#define TERMINATE_BUTTON 27
#define PAUSE_BUTTON 112
#define START_BUTTON 115
#define HOLD_TIMEOUT 100

namespace s21 {

class CLIView {
   public:
    CLIView() {
        initscr();
        noecho();
        cbreak();
        curs_set(false);
        keypad(stdscr, true);
    }

    ~CLIView() { endwin(); }

    struct Input {
        UserAction action_;
        bool hold_;
        bool has_action_;

        Input(UserAction action, bool hold, bool has_action = true)
            : action_(action), hold_(hold), has_action_(has_action) {}
    };

    void render(GameInfo& game_info);
    Input get_input(double time_left);

   private:
    bool check_for_hold(int c);
};

}  // namespace s21

#endif
