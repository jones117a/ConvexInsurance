#include <vector>
#include <iostream>

using namespace std;

int ChooseOddAppearanceNumber(vector<int> List) //Takes the list  of integers as a parameter.
{
	vector<int> CountingVector(List.size(), 1); //Creates a vector to count how many of each number appears in the list.
	
	for (int i = 0; i < List.size(); ++i) //Loop over the full list to check how many of each number appear.
	{
		for (int j = i + 1; j < List.size(); ++j) //Check each number against each subsequent number in the list.
		{
			if (List[i] == List[j]) //If the number is in the list again
			{
				++CountingVector[i]; //add 1 to the count
				List.erase(List.begin() + j); //and remove that number from the list.
			}
		}
		if (CountingVector[i] %2 != 0) return List[i]; //If the number of counts of a number is odd then return that number.
	}
}

int main()
{
	int NInts = 0, CurrentInt = 0;
	cout << "Please input the number of integers in the list." << endl;
	cin >> NInts;
	vector<int> List(NInts, 0);
	cout << "Please input the first integer in the list." << endl;
	cin >> CurrentInt;
	List[0] = CurrentInt;
	for (int i = 1; i < NInts; ++i)
	{
		cout << "Please input the next integer in the list." << endl;
		cin >> CurrentInt;
		List[i] = CurrentInt;
	}
        cout << "The number which appears an odd number of times in the list is " <<  ChooseOddAppearanceNumber(List) << "." << endl;
        return 0;
}
