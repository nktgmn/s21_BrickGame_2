#include "snake_game.h"

namespace s21 {

GameInfo::GameInfo()
    : field(nullptr),
      score(0),
      pause(0),
      level(1),
      speed(SPEED),
      max_score(0) {}

GameInfo::~GameInfo() {
    if (field != nullptr) {
        for (int i = 0; i < FIELD_W; ++i) {
            delete[] field[i];
        }
        delete[] field;
    }
}

SnakeGame::Point::Point(int x, int y) : x_(x), y_(y) {}

SnakeGame::Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {}

SnakeGame::Point& SnakeGame::Point::operator=(const Point& other) {
    if (this != &other) {
        x_ = other.x_;
        y_ = other.y_;
    }
    return *this;
}

bool SnakeGame::Point::operator==(const Point& other) const {
    return (x_ == other.x_ && y_ == other.y_);
}

bool SnakeGame::Point::operator!=(const Point& other) const {
    return !(*this == other);
}

SnakeGame::SnakeGame()
    : snake_body({Point(3, 7), Point(3, 6), Point(3, 5), Point(3, 4)}),
      snake_direction(Direction::Up),
      apple(spawn_apple()),
      state(State::Start),
      score(0),
      level(1),
      speed(SPEED),
      normal_speed(SPEED),
      max_score(get_max_score()),
      time_left(SPEED) {}

void SnakeGame::reinitialize_game() {
    snake_body = {Point(3, 7), Point(3, 6), Point(3, 5), Point(3, 4)};
    snake_direction = Direction::Up;
    apple = spawn_apple();
    score = 0;
    level = 1;
    speed = SPEED;
    normal_speed = SPEED;
    time_left = SPEED;
}

bool SnakeGame::game_won() { return snake_body.size() == FIELD_H * FIELD_W; }

bool SnakeGame::game_lost() {
    Point& current_head = snake_body.front();

    for (auto it = ++snake_body.begin(); it != snake_body.end(); ++it) {
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
    Point new_head = Point(snake_body.front());

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
    Point new_head = get_new_head(snake_direction);
    snake_body.push_front(new_head);
    if (new_head == apple) {
        ++score;

        update_level_and_max_score();

        if (game_won() == true) {
            state = State::GameWon;
        } else {
            apple = spawn_apple();
        }
    } else {
        snake_body.pop_back();
        if (game_lost() == true) {
            state = State::GameLost;
        }
    }
    timestamp = std::chrono::steady_clock::now();
    time_left = speed;
}

double SnakeGame::get_time_left() const {
    return time_left;
}

void SnakeGame::turn(Direction direction) {
    Point new_head = get_new_head(direction);

    if (new_head != *(++snake_body.begin())) {
        snake_direction = direction;
    }
}

GameInfo& SnakeGame::get_game_info() {
    GameInfo* game_info = new GameInfo;

    game_info->score = score;
    game_info->level = level;
    game_info->speed = speed;
    game_info->max_score = max_score;
    game_info->pause = (state == State::Pause) ? 1 : 0;

    game_info->field = new int*[FIELD_W];

    for (int i = 0; i < FIELD_W; ++i) {
        game_info->field[i] = new int[FIELD_H]();
    }

    if ((state == State::Move || state == State::Pause)) {
        game_info->field[apple.x_][apple.y_] = 1;

        for (auto it = snake_body.begin(); it != snake_body.end(); ++it) {
            game_info->field[(*it).x_][(*it).y_] = 1;
        }
    }

    return *game_info;
}

void SnakeGame::user_input(UserAction action, bool hold) {
    if (action == UserAction::Pause) {
        if (state == State::Move) {
            state = State::Pause;
            time_left = -1;
        } else if (state == State::Pause) {
            state = State::Move;
            timestamp = std::chrono::steady_clock::now();
            time_left = speed;
        }
    }

    if (action == UserAction::Up && state == State::Move) {
        turn(Direction::Up);
    } else if (action == UserAction::Down && state == State::Move) {
        turn(Direction::Down);
    } else if (action == UserAction::Left && state == State::Move) {
        turn(Direction::Left);
    } else if (action == UserAction::Right && state == State::Move) {
        turn(Direction::Right);
    } else if ((action == UserAction::Start) &&
               (state == State::Start || state == State::GameWon ||
                state == State::GameLost)) {
        reinitialize_game();
        state = State::Move;
        timestamp = std::chrono::steady_clock::now();
    }

    if (action == UserAction::Action && hold == true) {
        speed = MIN_SPEED;
        move();
    } else {
        speed = normal_speed;
    }

    if (state != State::Pause) {
        refresh_timer();
    }
}

SnakeGame::Point SnakeGame::spawn_apple() {
    int free_slots = FIELD_H * FIELD_W - snake_body.size();

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(1, free_slots);

    int random_number = distrib(gen);

    int count = 0;
    int snake_count = 0;
    int row = 0;
    int col = 0;

    while (snake_count != random_number) {
        ++count;
        ++snake_count;

        for (auto it = snake_body.begin(); it != snake_body.end(); ++it) {
            if (((*it).x_ == col) && ((*it).y_ == row)) {
                --snake_count;
                break;
            }
        }

        row = (count - 1) / FIELD_W;
        col = (count - 1) % FIELD_W;
    }

    return Point(col, row);
}

void SnakeGame::update_level_and_max_score() {
    int new_level = score / NEW_LEVEL_TRESHOLD + 1;
    if (new_level > MAX_LEVEL) {
        new_level = MAX_LEVEL;
    }

    normal_speed -= (new_level - level) * SPEED_STEP;
    level = new_level;

    if (score > max_score) {
        max_score = score;
        std::ofstream file("max_score.txt");

        if (file.is_open()) {
            file << max_score;
            file.close();
        }
    }
}

int SnakeGame::get_max_score() {
    int max_score = 0;

    std::ifstream file("max_score.txt");

    if (file.is_open()) {
        file >> max_score;
        file.close();
    }

    return max_score;
}

void SnakeGame::refresh_timer() {
    std::chrono::time_point<std::chrono::steady_clock> current_time =
        std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed =
        current_time - timestamp;
    timestamp = current_time;
    double time_passed = static_cast<double>(elapsed.count());

    if (time_passed < time_left) {
        time_left -= time_passed;
    } else {
        time_left = 0;
    }
}

}  // namespace s21
