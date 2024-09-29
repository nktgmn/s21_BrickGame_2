#include "game_params.h"

namespace s21 {

GameInfo::GameInfo()
    : field(nullptr),
      next(nullptr),
      score(0),
      pause(0),
      level(1),
      max_score(0) {}

GameInfo::~GameInfo() {
    if (field != nullptr) {
        for (int i = 0; i < FIELD_W; ++i) {
            delete[] field[i];
        }
        delete[] field;
    }

    if (next != nullptr) {
        for (int i = 0; i < 4; ++i) {
            delete[] next[i];
        }
        delete[] next;
    }
}

}  // namespace s21