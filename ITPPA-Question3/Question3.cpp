#include <iostream>
#include <string>

using namespace std;

int arrScores[5] = { 0, 0, 0, 0, 0 }; // a)

float average() {
	float sum = 0;

	for (int i = 0; i <= 4; i++) {
		sum = sum + arrScores[i];
	}

	return sum/5;
}

int highest() {
	int largest = arrScores[0];
	
	for (int i = 0; i <= 4; i++) { 
			if (arrScores[i] > largest) {
				largest = arrScores[i];
			}
	}
	return largest;
}

int lowest() {
	int smallest = arrScores[0];
	for (int i = 0; i <= 4; i++) {
		if (arrScores[i] < smallest) {
			smallest = arrScores[i];
		}
	}
	return smallest;
}

int main() {

	cout << "Enter the scores of 5 students:\n" << endl;

	for (int i = 0; i <= 4; i++) { // entering the scores
		cout << "Enter the score of student " + to_string(i+1) + ":";
		cin >> arrScores[i];


	}
	cout << endl;

	for (int i = 0; i <= 4; i++) { // entering the scores
		cout << "Student " + to_string(i + 1) + ": " + to_string(arrScores[i]) << endl;
	}
	cout << endl;

	
	
	cout << "Average Score: " + to_string(average()) << endl; // average
	cout << "Highest Score: " + to_string(highest()) << endl; // largest
	cout << "Lowest Score: "  + to_string(lowest()) << endl; // lowest

	return 0;
}