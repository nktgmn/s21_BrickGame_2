#ifndef GAME_PARAMS_H
#define GAME_PARAMS_H

#define FIELD_H 20
#define FIELD_W 10
#define MAX_LEVEL 10
#define SPEED 500
#define MIN_SPEED 50
#define SPEED_STEP 30
#define NEW_LEVEL_TRESHOLD_TETRIS 600
#define NEW_LEVEL_TRESHOLD_SNAKE 5

namespace s21 {

enum struct UserAction_t {
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
    int** next;
    int score;
    int pause;
    int level;
    int speed;
    int max_score;
};

struct Input {
    UserAction_t action_;
    bool hold_;
    bool has_action_;

    Input(UserAction_t action, bool hold, bool has_action)
        : action_(action), hold_(hold), has_action_(has_action) {}
};

}  // namespace s21

#endif