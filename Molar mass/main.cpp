#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const double weights[] = {12.01, 1.008, 16.00, 14.01};

void addToElement(const char &element, const int &amount, double num_elements[]);

int main()
{
	double num_elements[] = {0, 0, 0, 0};
	int num_cases;
	int extra_val = 0;
	double total;
	string test_case, currentNumber;
	char currentElement;

	cin >> num_cases;
	cin.get();

	// Iterates over each test case
	for (int i = 0; i < num_cases; i++)
	{
		// Resets values
		total = 0;
		for (int j = 0; j < 4; j++)
			num_elements[j] = 0;

		// Gets next line
		getline(cin, test_case);

		for (int j = 0; j < test_case.length(); j++)
		{
			if (isalpha(test_case[j]))
			{
				if (!currentNumber.empty())
				{
					j--;
					test_case[j] = currentElement;
					extra_val = stoi(currentNumber) - 2;
					currentNumber.clear();
				}

				switch(test_case[j])
				{
					case 'C':
						num_elements[0] += 1 + extra_val;
						break;
					case 'H':
						num_elements[1] += 1 + extra_val;
						break;
					case 'O':
						num_elements[2] += 1 + extra_val;
						break;
					case 'N':
						num_elements[3] += 1 + extra_val;
						break;
				}

				currentElement = test_case[j];
				extra_val = 0;
			}

			else
				currentNumber += test_case[j];
		}

		if (!currentNumber.empty())
		{	
			addToElement(currentElement, (stoi(currentNumber)-1), num_elements);
			currentNumber.clear();
		}
		// Calculates & outputs results of current test case
		for (int j = 0; j < 4; j++)
			total += num_elements[j] * weights[j];
		cout << setprecision(3) << fixed << total << endl;
	}

	return 0;
}

void addToElement(const char &element, const int &amount, double num_elements[])
{
	switch(element)
	{
		case 'C':
			num_elements[0] += amount;
			break;
		case 'H':
			num_elements[1] += amount;
			break;
		case 'O':
			num_elements[2] += amount;
			break;
		case 'N':
			num_elements[3] += amount;
			break;
	}

	return;
}