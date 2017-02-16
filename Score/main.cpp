#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num_tests;
	int total;
	int oPrevTotal;
	string testCase;

	cin >> num_tests;
	cin.get();

	for (int i = 0; i < num_tests; i++)
	{
		total = 0;
		oPrevTotal = 1;
		getline(cin, testCase);

		for (int j = 0; j < testCase.length(); j++)
		{
			switch(testCase[j])
			{
				case 'O':
					total += oPrevTotal;
					oPrevTotal++;
					break;

				case 'X':
					oPrevTotal = 1;
					break;
			}
		}

		cout << total << endl;
	}
	
	return 0;
}