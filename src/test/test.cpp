#include "test.h"

TEST(SnakeGameTest, Constructors) {
    s21::SnakeGame game;

    s21::GameInfo& game_info = game.updateCurrentState();
    EXPECT_TRUE(game_info.level == 1);
    delete &game_info;

    EXPECT_FALSE(game.game_lost());
    EXPECT_FALSE(game.game_won());

    for (int i = 0; i < 15; ++i) {
        game.move();
    }

    EXPECT_TRUE(game.game_lost());
    EXPECT_FALSE(game.game_won());

    game.initialize_game();

    game.userInput(s21::UserAction_t::Start, false);
    game.move();
    game.userInput(s21::UserAction_t::Right, false);
    game.move();
    game.userInput(s21::UserAction_t::Down, false);
    game.move();
    game.userInput(s21::UserAction_t::Left, false);
    game.move();
    game.userInput(s21::UserAction_t::Up, false);
    game.move();

    game.userInput(s21::UserAction_t::Pause, false);
    EXPECT_TRUE((int)game.get_time_left() == -1);
    s21::GameInfo& game_info_2 = game.updateCurrentState();
    EXPECT_TRUE(game_info.level == 1);
    delete &game_info_2;
    game.userInput(s21::UserAction_t::Pause, false);

    game.update_level_and_max_score();

    game.userInput(s21::UserAction_t::Action, true);
    s21::GameInfo& game_info_3 = game.updateCurrentState();
    EXPECT_TRUE(game_info.speed == MIN_SPEED);
    delete &game_info_3;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}