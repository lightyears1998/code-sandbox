#include <iostream>
using namespace std;

// 轮胎
class Tire {
protected:
	int weight;	
};

// 底盘
class Chassis : private Tire {

} 

int main()
{
	
}