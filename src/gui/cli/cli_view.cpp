#include "cli_view.h"

namespace s21 {

void CLIView::render(GameInfo &game_info) {
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

    WINDOW *params_window =
        newwin(FIELD_H + 2, 3 * FIELD_W + 2, 0, 3 * FIELD_W + 4);
    refresh();
    box(params_window, 0, 0);

    std::string score = std::to_string(game_info.score);
    mvwprintw(params_window, 2, 5, "SCORE: ");
    mvwprintw(params_window, 2, 12, score.c_str());

    std::string max_score = std::to_string(game_info.max_score);
    mvwprintw(params_window, 4, 5, "MAX SCORE: ");
    mvwprintw(params_window, 4, 16, max_score.c_str());

    std::string level = std::to_string(game_info.level);
    mvwprintw(params_window, 6, 5, "LEVEL: ");
    mvwprintw(params_window, 6, 12, level.c_str());

    std::string speed = std::to_string(game_info.speed);
    mvwprintw(params_window, 8, 5, "SPEED: ");
    mvwprintw(params_window, 8, 12, speed.c_str());

    if (game_info.pause == 1) {
        mvwprintw(params_window, 10, 5, "GAME PAUSED");
        mvwprintw(params_window, 11, 5, "press P to resume");
    }

    wrefresh(params_window);

    delwin(game_window);
    delwin(params_window);
}

Input CLIView::get_input(double time_left) {
    timeout(time_left);

    int c = getch();

    if (c == START_BUTTON) {
        return Input(UserAction_t::Start, check_for_hold(c), true);
    } else if (c == KEY_LEFT) {
        return Input(UserAction_t::Left, check_for_hold(c), true);
    } else if (c == KEY_RIGHT) {
        return Input(UserAction_t::Right, check_for_hold(c), true);
    } else if (c == KEY_UP) {
        return Input(UserAction_t::Up, check_for_hold(c), true);
    } else if (c == KEY_DOWN) {
        return Input(UserAction_t::Down, check_for_hold(c), true);
    } else if (c == TERMINATE_BUTTON) {
        return Input(UserAction_t::Terminate, check_for_hold(c), true);
    } else if (c == PAUSE_BUTTON) {
        return Input(UserAction_t::Pause, check_for_hold(c), true);
    } else if (c == ACTION_BUTTON) {
        return Input(UserAction_t::Action, check_for_hold(c), true);
    } else {
        return Input(UserAction_t::Up, false, false);
    }
}

bool CLIView::check_for_hold(int c) {
    timeout(HOLD_TIMEOUT);
    int next_ch = getch();
    timeout(0);
    while (getch() != ERR)
        ;
    return (next_ch == c);
}

}  // namespace s21