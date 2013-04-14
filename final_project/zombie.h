//Tyler Morgan	
//Apr-13-2013
//UW winter online c++ class 1st qtr
//final projec
//zombie.h
//contains the logic and location information for a zombie
class Level;
class Player;

class Zombie
{
public:
	Zombie();
	Zombie(int x, int y);
	~Zombie();
	void set_location(int x, int y);
	void move(Player&, Level *);
	int get_x();
	int get_y();

private:
	int distance_to_player_x(Player&);
	int distance_to_player_y(Player&);
	Point my_location;


};