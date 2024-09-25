#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H

#include <ncurses.h>

#include "snake_game.h"

#define TERMINATE_BUTTON 27
#define PAUSE_BUTTON 112
#define START_BUTTON 115

namespace s21 {

class SnakeView {
   public:
    SnakeView() {
        initscr();
        noecho();
        cbreak();
        curs_set(false);
        keypad(stdscr, true);
    }

    ~SnakeView() {
        endwin();  // End ncurses mode
    }

    void render(GameInfo game_info);
    std::pair<UserAction, unsigned long long> get_input(
        unsigned long long time_left);
};

}  // namespace s21

#endif