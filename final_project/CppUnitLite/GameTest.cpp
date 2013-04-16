#include "TestHarness.h"
#include "../level.h"
#include <sstream>
#include <iostream>


// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
TEST(point_fucntions, Point)
{
	Point point1(0,0);
	point1.set_y(4);
	point1.inc_x(5);
	point1.inc_y(-1);
	CHECK_EQUAL(3, point1.get_y());
	CHECK_EQUAL(5, point1.get_x());
}


TEST(level_draw, Level)
{
	std::stringstream ss;
	Level level1(0);
	level1.draw_level(ss);
	CHECK_EQUAL('*',ss.str().at(0)); //check for a * at location 0,0
	CHECK_EQUAL('*', ss.str().at(1536)); // check for a * at location 128,64
	//I won't check for a ' ' because the walls in the interior of the level 
	// will be generated randomly
}

TEST(goal_location_methods, GoalLocaiton)
{
	GoalLocation goal;
	CHECK_EQUAL(false, goal.check_goal_set());
	goal.set_goal(10,10);
	CHECK_EQUAL(true, goal.check_goal_set());
	goal.set_goal(20,20);
	CHECK_EQUAL(10,goal.get_x());
	CHECK_EQUAL(10,goal.get_y());
	goal.unset_goal();
	goal.set_goal(20,20);
	CHECK_EQUAL(20, goal.get_x());
	CHECK_EQUAL(20, goal.get_y());

}
TEST(player_position, Player)
{
	Player player1;
	Player player2(15,20);
	player1.set_location(5,6);
	player1.move(1);
	player1.move(4);
	player2.change_score(15);

	CHECK_EQUAL(15, player2.get_score());
	CHECK_EQUAL(0, player1.get_score());
	CHECK_EQUAL(4,player1.get_x());
	CHECK_EQUAL(7, player1.get_y());

}
TEST(Zombies_kill_player, Level)
{
	//Test to see that if a player occupies the same space as a zombie the level ends
	Level level(1);
	level.set_player_location(1,1);
	level.set_zombie_location(0,1,1);
	level.update_level();
	CHECK_EQUAL(true, level.level_end());
}

TEST(Multiple_zombies_kill_player, Level)
{
	Level level(3);
	level.set_player_location(1,1);
	level.set_zombie_location(1,1,1);
	level.update_level();
	CHECK_EQUAL(true, level.level_end());
}

TEST(Player_win, Level)
{
	Level level(1);
	level.set_player_location(level.get_goal_location_x(),level.get_goal_location_y());
	level.update_level();
	CHECK_EQUAL(true, level.level_end());
	CHECK_EQUAL(true, level.did_player_win());
}

TEST(level_generation2, Level)
{
	//Hard to write a test to see if the random level looks alright, so this is more of
	//visual test to run when testing.
	std::stringstream ss;
	Level level1(1);
	level1.draw_level(ss);
	std::cout << ss.str();

}

