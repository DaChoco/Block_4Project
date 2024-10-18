#include <iostream>
#include <string>
int arrScores[5] = { 0, 0, 0, 0, 0 }; // a)

//function average scores

float average() {
	float sum = 0;

	for (int i = 0; i <= 4; i++) {
		sum = sum + arrScores[i];
	}

	return sum/5;
}

//function find and return largest number
int highest() {
	int largest = arrScores[0];
	
	for (int i = 0; i <= 4; i++) { 
			if (arrScores[i] > largest) {
				largest = arrScores[i];
			}
	}
	return largest;
}

//function find and return lowest number
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

	std::cout << "Enter the scores of 5 students:\n" << std::endl;

	for (int i = 0; i <= 4; i++) { // entering the scores
		std::cout << "Enter the score of student " + std::to_string(i+1) + ": ";
		std::cin >> arrScores[i];


	}
	std::cout << std::endl;

	for (int i = 0; i <= 4; i++) { // entering the scores
		std::cout << "Student " + std::to_string(i + 1) + ": " + std::to_string(arrScores[i]) << std::endl;
	}
	std::cout << std::endl;

	
	
	std::cout << "Average Score: " + std::to_string(average()) << std::endl; // average
	std::cout << "Highest Score: " + std::to_string(highest()) << std::endl; // largest
	std::cout << "Lowest Score: "  + std::to_string(lowest()) << std::endl; // lowest

	return 0;
}