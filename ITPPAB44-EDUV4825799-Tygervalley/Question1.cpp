#include <iostream>
#include <string>
#include <fstream>

//discounts
const double DISCOUNT_RATE = 0.10; // 10% discount
const double DISCOUNT_THRESHOLD = 100.00; // Discount applies if bill is over R100

//Menu Prices
const double coffee_p = 15.00;
const double sandwich_p = 30.00;
const double salad_p = 25.00;
const double juice_p = 10.00;
const double muffin_p = 20.00;
const double pizza_p = 35.00;
const double soup_p = 18.00;
const double burger_p = 40.00;

//glb variables
bool itemvalid = false;
int iItemNum = 0, sum = 0, picked = 0;

using namespace std;

void static drawMenu() {
	//Second Bullet Point

	cout << "Menu Prices:" << endl;
	//By using raw string literals aka R"()", we save alot of time and effort
	cout << R"(
1. Coffee - R15.00
2. Sandwich - R30.00
3. Salad - R25.00
4. Juice - R10.00
5. Muffin - R20.00
6. Pizza - R35.00
7. Soup - R18.00
8. Burger - R40.00
)";
}

void static selection() {
	
	//Third Bullet Point
	cout << "Select how many items you would like to select (1-8): ";

	while (itemvalid == false) {
		cin >> iItemNum;
		if ((iItemNum < 1) || (iItemNum > 8)) {
			cout << "Please select a valid input: ";
		}
		else {
			itemvalid = true;
		}

	}

	//the loop of the selection
	//Item num = Number of items;	Sum is self evident; picked = which item is picked

	//fourth bullet point
	for (int i = 0; i < iItemNum; i++) {
		cout << "Select Item (" + to_string(i+1) + "): ";
		cin >> picked;

		if (picked == 1) {
			sum = sum + coffee_p;
		}
		else if (picked == 2) {
			sum = sum + sandwich_p;
		}
		else if (picked == 3) {
			sum = sum + salad_p;
		}
		else if (picked == 4) {
			sum = sum + juice_p;
		}
		else if (picked == 5) {
			sum = sum + muffin_p;
		}
		else if (picked == 6) {
			sum = sum + pizza_p;
		}
		else if (picked == 7) {
			sum = sum + soup_p;
		}
		else if (picked == 8) {
			sum = sum + burger_p;
		}
	}
		
		//fifth and sixth
		cout << "\nTotal Bill: " + to_string(sum) << endl;


		if (sum > DISCOUNT_THRESHOLD) {
			cout << "Discount will be applied" << endl;
			sum = sum * (1 - DISCOUNT_RATE);
		}

		cout << "\nFinal Bill: " + to_string(sum) << endl;
}

//the main function. We split up the code to make this nicer to read

int main() {
	//First bullet point
	string name, surname;
	
	cout << "Please enter your name: ";
	cin >> name;

	cout << "Please enter your surname: ";
	cin >> surname;

	drawMenu();

	selection();
	
	//open our input file
	ofstream OutFile; 
	OutFile.open("cafeteriabill.txt");


	//writing to the file
	if (OutFile.is_open()) {
		OutFile << name + " " + surname + " ";
		OutFile << "The final bill was R" + to_string(sum) << endl;
		cout << "Your bill has been written to cafeteriabill.txt";

		OutFile.close();
	}

	else {
		perror("File opening failed");
		cout << "Therefore, there were issues opening a file.\n " << endl;
	}
	
	

	system("pause");
	return 0;
}