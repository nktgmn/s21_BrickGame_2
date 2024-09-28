#ifndef GAME_PARAMS_H
#define GAME_PARAMS_H

#define FIELD_H 20
#define FIELD_W 10

namespace s21 {

enum class UserAction {
    Start,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action
};

struct GameInfo {
    GameInfo();
    ~GameInfo();
    int** field;
    int score;
    int pause;
    int level;
    int speed;
    int max_score;
};

}  // namespace s21

#endif