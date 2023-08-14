#include <iostream>
#include<queue>
using namespace std;
class Elevator
{
private:
	int totalfloor;
	int currentfloor;
	queue<int> reuqest;
public :
	Elevator(int totalflor)
	{
		totalfloor = totalflor;
		currentfloor = 1;
	}
	void request(int floor)
	{
		if (floor > 1 && floor <= totalfloor)
		{
			reuqest.push(floor);
			cout << " the request is  done ....." << " " << endl;
		}
	}
	void move()
	{
		while (!reuqest.empty())
		{
			int  going = reuqest.front();
			reuqest.pop();
			cout << " Elevator moving from the floor" << currentfloor << endl;
			currentfloor = going;
			cout << "  Elevator is at floor" << currentfloor << endl;



		}
	 }

};
int main()
{
	int numFloors = 10;
	Elevator elevator(numFloors);

	elevator.request(5);
	elevator.request(3);
	elevator.request(8);

	elevator.move();

	return 0;
}