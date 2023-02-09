#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <iomanip>

using namespace std;

int main(); 

void FirstFunction() {

	// first text file
	ofstream outFirst;
	outFirst.open("first.txt");
	for (int i = 4; i <= 4 * 10; i = i + 4) {
		outFirst << i << endl; // writing to file first ten even numbers
	}
	outFirst.close();


	// second text file
	ofstream outSecond;
	outSecond.open("second.txt");
	for (int i = 3; i <= 3 * 10; i = i + 3) {
		outSecond << i << endl; // writing to file first ten multiples of five
	}
	outSecond.close();

	// calculting the sum
	ifstream inFirst;
	ifstream inSecond;

	inFirst.open("first.txt");
	inSecond.open("second.txt");

	int total = 0;
	int num1 = 0;
	int num2 = 0;

	// calculating the total
	while (inFirst && inSecond) {
		total += num1 + num2;	
		inFirst >> num1;
		inSecond >> num2;
	}
	inFirst.close();
	inSecond.close();

	// third file for the sum
	ofstream out_total("sum.txt");
	out_total << total << endl;
	out_total.close();

	// sum output
	ifstream inTotal;
	inTotal.open("sum.txt");

	cout << "Files created\n";

	inTotal >> total;
	cout << "Sum: " << total << "\n\n";
	
	inTotal.close();
}

int main(){
	for (int k = 0; k < 3; k++) {
		system("cls");
	    cout << "Choose: \n" << "1.\n" << "quit.\n";

		switch (_getch())
		{
		case 49:
			system("cls");
			FirstFunction();
			system("pause");
			break;

		case 113:
			system("cls");
			return 0;

		default:
			cout << "Unavailable choice.\nTry again\n";
			system("pause");
			break;
		}
	}

	system("pause");
	return 0;
}