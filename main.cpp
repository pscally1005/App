/* 
	[Insert Name Later]
	This is the main code for [Name], showing the main screen
	The main screen will give you the option to launch other screens, and exit the application
*/

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include "rate_log.h"
#include "bmi.h"
#include "exercise_tips.h"

typedef unsigned int uint;

//mainscreen header
void title() {

	std::cout << "#####################" << std::endl;
	std::cout << "#                   #" << std::endl;
	std::cout << "# [ENTER NAME HERE] #" << std::endl;
	std::cout << "#                   #" << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << std::endl;

}

//screen options
void options() {

	std::cout << "1: Rate My Nutrition" << std::endl;
	std::cout << "2: BMI Calculator" << std::endl;
	std::cout << "3: Exercise Tips" << std::endl;
	std::cout << "0: Quit" << std::endl;
	std::cout << std::endl;
}

//prints the previous information from the main screen if screen input is invalid
void print_prev_main() {

	system("cls");
	title();
	options();

}

//returns int of selected screen
int screen_select() {

	//main screen options
	options();
	std::cout << "Enter a number to select: ";

	std::string num_str;
	std::getline(std::cin, num_str);
	int num = -1;

	//if input is improper (not a number)
	while(num_str == "" || check_number(num_str) == false) {
		print_prev_main();
		std::cerr << "ERROR: \"" << num_str << "\" is not a proper input.  Please try again" << std::endl;
		std::cout << "Enter a number to select: ";
        std::getline(std::cin, num_str);
    }

    //convert input from string to int
    num = std::stoi(num_str);

    //if input is improper (not a valid number)
    //also checks if new imput is a number or not
    while(num < 0 || num > 3) {
    	print_prev_main();
    	std::cerr << "ERROR: \"" << num_str << "\" is not a proper input.  Please try again" << std::endl;
    	std::cout << "Enter a number to select: ";
        std::getline(std::cin, num_str);
        if(num_str == "" || check_number(num_str) == false) { continue; }
        num = std::stoi(num_str);
    }

	std::cout << std::endl;

	//return correct input to main
	return num;
	
}

//main code
int main(/*int argc, char* argv[]*/) {

	system("cls");
	title();
	int select = screen_select();

	//if user inputs 1 (rate_log)
	if(select == 1) { 

		system("cls");
		rate_log();
		main();

	//if user inputs 2 (bmi)
	} else if(select == 2) {

		system("cls");
		bmi_();
		main();

	//if user inputs 3 (exercise_tips)
	} else if(select == 3) {

		system("cls");
		exercise_tips();
		main();

	//if user inputs 0 (quit)
	} else if(select == 0) {

		std::cout << "Quitting Now" << std::endl;
		return 1;

	}

	//shouldn't ever run but just in case (somehow inproper input make it past screen_select() )
	else {

		std::cerr << "ERROR: \"" << select << "\" is not a proper input.  Please try again" << std::endl;
		return 0;

	}

	//end of code
	return 1;

}
