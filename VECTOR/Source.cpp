#include<ctime>
#include<random>
#include<iostream>
#include"VECTOR.h"

using namespace std;

int main() {
	srand(time(0));
	double direction;
	VECTOR step;
	VECTOR result(0.0, 0.0, VECTOR::POLAR);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance: ";
	cin >> target;
	cout << "Enter step length: ";
	cin >> dstep;
	while (result.length() < target) {
		direction = rand() % 360;
		step.reset(dstep, direction, VECTOR::POLAR);
		result = result + step;
		steps++;
	}
	cout << "After " << steps << " steps, the subject has the following location:\n";
	cout << result;
	result.set_mode(VECTOR::POLAR);
	cout << "or\n";
	cout << result;
	cout << "Average distance per step = " << result.length() / steps << endl;
	system("pause");
	return 0;
}