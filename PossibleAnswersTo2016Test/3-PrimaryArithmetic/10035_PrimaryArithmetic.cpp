#include <iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long number1, number2;
	while (cin >> number1 >> number2)
	{
		//cerr << number1 << " " << number2;
		if (number1 == 0 && number2 == 0) { break; }

		int numberOfCarryOperations = 0;

		while (number1 > 0 && number2 > 0) {

			//1. extract rightmost digit of 1st number
			int rightmostDigitOfNumber1 = number1 % 10;
			// stop extracting if there are no more digits left
			if (number1 > 0) {
				number1 = number1 / 10;
			}

			//2. extract rightmost digit of 2nd number 
			int rightmostDigitOfNumber2 = number2 % 10;
			//stop extracting if there are no more digits left
			if (number2 > 0) {
				number2 = number2 / 10;
			}

			//3. add the extracted digits and count the number of carry operations
			int sum = rightmostDigitOfNumber1 + rightmostDigitOfNumber2;
			if (sum > 9){
				numberOfCarryOperations++;
			}
		}

		switch (numberOfCarryOperations)
		{
		case 0:
			cout << "No carry operation.\n";
			break;
		case 1:
			cout << "1 carry operation.\n";
			break;
		default:
			cout << numberOfCarryOperations << " carry operations.\n";
			break;
		}
	}

	return 0;
}

int get_rightmost_digit(int number)
{
	return number % 10;
}