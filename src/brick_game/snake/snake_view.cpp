#include "snake_view.h"

#include <ncurses.h>

#include <iostream>
#include <vector>

namespace s21 {

void SnakeView::render(GameInfo game_info) {
    WINDOW *game_window = newwin(FIELD_H + 2, 3 * FIELD_W + 2, 0, 0);
    refresh();
    box(game_window, 0, 0);

    for (int i = 0; i < FIELD_H; ++i) {
        for (int j = 0; j < FIELD_W; ++j) {
            if (game_info.field[j][i] == 1) {
                mvwprintw(game_window, (FIELD_H - i - 1) + 1, 3 * j + 1, "[ ]");
            } else {
                mvwprintw(game_window, (FIELD_H - i - 1) + 1, 3 * j + 1, "   ");
            }
        }
    }

    wrefresh(game_window);

    delwin(game_window);
}

std::pair<UserAction, unsigned long long> SnakeView::get_input(
    unsigned long long time_left) {
    while (time_left > 0) {
        timeout(time_left);
        auto start_time = std::chrono::steady_clock::now();
        int c = getch();
        auto end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed =
            end_time - start_time;
        unsigned long long time_passed =
            static_cast<unsigned long long>(elapsed.count());

        if (c == START_BUTTON) {
            return {UserAction::Start, time_left - time_passed};
        } else if (c == KEY_LEFT) {
            return {UserAction::Left, time_left - time_passed};
        } else if (c == KEY_RIGHT) {
            return {UserAction::Right, time_left - time_passed};
        } else if (c == KEY_UP) {
            return {UserAction::Up, time_left - time_passed};
        } else if (c == KEY_DOWN) {
            return {UserAction::Down, time_left - time_passed};
        } else if (c == ERR) {
            return {UserAction::Down, 0};
        } else {
            time_left -= time_passed;
        }
    }
    return {UserAction::Down, 0};
}

}  // namespace s21