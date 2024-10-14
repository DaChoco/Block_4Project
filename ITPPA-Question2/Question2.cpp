#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string name = "", itemName = "";
	int numItems = 0, quantity = 0, itemPrice = 0, cart = 0;

	cout << "Hello, please input your name and surname: ";
	getline(cin >> ws, name);

	//drawing the menu
	cout << "\nList of available items:	" << endl;

	cout << "Red Apples			R5" << endl;
	cout << "Chicken Breasts			R54" << endl;
	cout << "Hot Chocolate Powder		R92" << endl;
	cout << "Still Water			R25" << endl;
	cout << "Lays Chips			R22" << endl;
	cout << "Red Grapes			R29" << endl;
	cout << "Beef Rump Steak	R118" << endl;

	//done drawing the menu

	cout << "\nHow many of each item do you want?: ";
	cin >> numItems;
	cout << endl;
	//open the text file
	ofstream TFile; //open file
	TFile.open("itemslist.txt");

	if (TFile.is_open()) {

		TFile << name << endl;
		for (int i = 0; i < numItems; i++) {
			cout << "Select an item: ";
			getline(cin >> ws, itemName);
			cout << endl;

			cout << "How much of this item do you want?: ";
			cin >> quantity;
			cout << endl;

			if (itemName == "Red Apples" || itemName == "red apples") {
				itemPrice = 5 * quantity;
				cart = cart + itemPrice;
				TFile << itemName + "(x" + to_string(quantity) + ")		" + "R" + to_string(itemPrice) << endl; //we add to the text file line by line

			}
			else if (itemName == "Chicken Breasts" || itemName == "chicken breasts") {
				itemPrice = 54 * quantity;
				cart = cart + itemPrice;	
				TFile << itemName + "(x" + to_string(quantity) + ")		" + "R" + to_string(itemPrice) << endl;
			}
			else if (itemName == "Hot Chocolate Powder" || itemName == "hot chocolate powder") {
				itemPrice = 92 * quantity;
				cart = cart + itemPrice;
				TFile << itemName + "(x" + to_string(quantity) + ")		" + "R" + to_string(itemPrice) << endl;
			}
			else if (itemName == "Still Water" || itemName == "still water") {
				itemPrice = 25 * quantity;
				cart = cart + itemPrice;
				TFile << itemName + "(x" + to_string(quantity) + ")		" + "R" + to_string(itemPrice) << endl;
			}
			else if (itemName == "Lays Chips" || itemName == "lays chips") {
				itemPrice = 22 * quantity;
				cart = cart + itemPrice;
				TFile << itemName + "(x" + to_string(quantity) + ")		" + "R" + to_string(itemPrice) << endl;
			}
			else if (itemName == "Red Grapes" || itemName == "red grapes") {
				itemPrice = 29 * quantity;
				cart = cart + itemPrice;
				TFile << itemName + "(x" + to_string(quantity) + ")		" + "R" + to_string(itemPrice) << endl;
			}
			else if (itemName == "Beef Rump Steak" || itemName == "beef rump steak") {
				itemPrice = 118 * quantity;
				cart = cart + itemPrice;
				TFile << itemName + "(x" + to_string(quantity) + ")		" + "R" + to_string(itemPrice) << endl;
			}
			else {
				cout << "That is not an actual item, please input again" << endl;
				i = i - 1;
			} // if else chain
		} // for loop
	} //if open?
	else {
		perror("File opening failed");
	}

	if (cart > 200) {
		cout << "Discount available!" << endl;
		cart = cart * (1 - 0.05);

	}
	

	
	cout << "\nR" + to_string(cart) ;
	TFile << "-------------------------------\n" << endl;
	TFile << "Total Bill: " + to_string(cart) << endl;

	TFile.close(); // close file

	

	
	return 0;
}