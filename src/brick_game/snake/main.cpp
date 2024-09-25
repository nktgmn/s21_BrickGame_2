#include "snake_controller.h"
#include "snake_game.h"
#include "snake_view.h"

int main() {
    int c = getch();

    s21::SnakeGame game;
    s21::SnakeView view;
    s21::SnakeController controller(game, view);

    controller.run();

    return 0;
}
