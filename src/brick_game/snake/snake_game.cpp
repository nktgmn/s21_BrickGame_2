#include "snake_game.h"

namespace s21 {

GameInfo::GameInfo() : field(nullptr), score(0) {}

GameInfo::~GameInfo() {
    // for (int i = 0; i < FIELD_H; ++i) {
    //     delete[] (field + FIELD_W * i);
    // }
    // delete[] field;
}

SnakeGame::Point::Point(int x, int y) : x_(x), y_(y) {}

SnakeGame::Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {}

bool SnakeGame::Point::operator==(const Point& other) const {
    return (x_ == other.x_ && y_ == other.y_);
}

bool SnakeGame::Point::operator!=(const Point& other) const {
    return !(*this == other);
}

SnakeGame::Snake::Snake()
    : body({Point(3, 7), Point(3, 6), Point(3, 5), Point(3, 4)}),
      direction(Direction::Up) {}

SnakeGame::SnakeGame()
    : apple(Point(1, 2)), snake(Snake()), state(State::Start), score(0) {}

bool SnakeGame::can_turn(Direction direction) {
    // if ((direction == Direction::Up || direction == Direction::Down) &&
    //     (snake.direction == Direction::Up ||
    //      snake.direction == Direction::Down)) {
    //     return false;
    // }

    // if ((direction == Direction::Left || direction == Direction::Right) &&
    //     (snake.direction == Direction::Left ||
    //      snake.direction == Direction::Right)) {
    //     return false;
    // }

    // Point new_head = get_new_head(direction);

    // if ((new_head.x_ < 0) || (new_head.y_ < 0) || (new_head.x_ > FIELD_W - 1) ||
    //     (new_head.y_ > FIELD_H - 1)) {
    //     return false;
    // }

    Point new_head = get_new_head(direction);

    if (new_head == *(++snake.body.begin())) {
        return false;
    }

    return true;
}

bool SnakeGame::game_won() { return snake.body.size() == FIELD_H * FIELD_W; }

bool SnakeGame::game_lost() {
    Point& current_head = snake.body.front();

    for (auto it = ++snake.body.begin(); it != snake.body.end(); ++it) {
        if (*it == current_head) {
            return true;
        }
    }

    if ((current_head.x_ < 0) || (current_head.y_ < 0) ||
        (current_head.x_ > FIELD_W - 1) || (current_head.y_ > FIELD_H - 1)) {
        return true;
    }

    return false;
}

SnakeGame::Point SnakeGame::get_new_head(Direction direction) {
    Point new_head = Point(snake.body.front());

    if (direction == Direction::Up) {
        ++new_head.y_;
    } else if (direction == Direction::Down) {
        --new_head.y_;
    } else if (direction == Direction::Left) {
        --new_head.x_;
    } else {
        ++new_head.x_;
    }

    return new_head;
}

void SnakeGame::move() {
    Point new_head = get_new_head(snake.direction);
    snake.body.push_front(new_head);
    if (new_head == apple) {
        ++score;

        if (game_won() == true) {
            state = State::GameWon;
        } else {
            apple.x_ = 1;
            apple.y_ = 1;
        }
    } else {
        snake.body.pop_back();
        if (game_lost() == true) {
            state = State::GameLost;
        }
    }
}

void SnakeGame::turn(Direction direction) {
    // Point new_head = get_new_head(direction);
    // snake.body.push_front(new_head);
    snake.direction = direction;
    // if (new_head == apple) {
    //     ++score;
    //     if (game_won() == true) {
    //         state = State::GameWon;
    //     } else {
    //         apple.x_ = 1;
    //         apple.y_ = 1;
    //     }
    // } else {
    //     snake.body.pop_back();
    //     if (game_lost() == true) {
    //         state = State::GameLost;
    //     }
    // }
}

GameInfo SnakeGame::get_game_info() {
    GameInfo game_info;

    game_info.score = score;

    game_info.field = new int*[FIELD_W];

    for (int i = 0; i < FIELD_W; ++i) {
        game_info.field[i] = new int[FIELD_H]();
    }

    if (state == State::Move) {
        game_info.field[apple.x_][apple.y_] = 1;

        for (auto it = snake.body.begin(); it != snake.body.end(); ++it) {
            game_info.field[(*it).x_][(*it).y_] = 1;
        }
    } else if (state == State::Start) {
        game_info.field[5][10] = 1;
    }

    return game_info;
}

void SnakeGame::user_input(UserAction action) {
    if (action == UserAction::Up && state == State::Move &&
        can_turn(Direction::Up) == true) {
        turn(Direction::Up);
    } else if (action == UserAction::Down && state == State::Move &&
               can_turn(Direction::Down) == true) {
        turn(Direction::Down);
    } else if (action == UserAction::Left && state == State::Move &&
               can_turn(Direction::Left) == true) {
        turn(Direction::Left);
    } else if (action == UserAction::Right && state == State::Move &&
               can_turn(Direction::Right) == true) {
        turn(Direction::Right);
    }

    if (action == UserAction::Start) {
        state = State::Move;
    }
}

}  // namespace s21
