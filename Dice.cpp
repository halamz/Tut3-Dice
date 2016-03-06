#include <iostream>
#include<ctime>
#include<cstdlib>
#define n 5

using namespace std;

class Dice
{
private:

public:
	Dice();
	int roll();
	float average(Dice, int numRolls);
	float average(int *Arr, int numValues);
	~Dice();
};

//constructor
Dice::Dice()
{

}

//Method returns the value of the roll

int Dice::roll()
{
	return  rand() % 6 + 1;
}

//Two globally overloaded functions
float Dice::average(Dice obj, int numRolls)
{
	int sum = 0;
	for (int i = 0; i<numRolls; i++)
	{
		sum += roll();
	}
	return float(sum / numRolls);
}

float Dice::average(int *arr, int numValues)
{
	float sum = 0;
	for (int i = 0; i<numValues; i++)
	{
		sum += arr[i];
	}
	return sum / (float)numValues;
}
//Destructor
Dice::~Dice()
{

}
// main
int main()
{
	srand((unsigned)time(0));// makes the randomly generated values, random
	Dice die;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = die.roll();
		cout << arr[i] << endl;;
	}
	cout << "Average using array : " << die.average(arr, n) << endl;
	cout << "Average using Dice object : " << die.average(die, n) << endl;
}
