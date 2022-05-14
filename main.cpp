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
#include <cstdio>
#include "rate_log.h"
#include "bmi.h"
#include "nutrition.h"
#include "pace.h"
#include "splits.h"

typedef unsigned int uint;

//mainscreen header
void title() {

	std::cout << "#####################" << std::endl;
	std::cout << "#                   #" << std::endl;
	std::cout << "# [Enter Name Here] #" << std::endl;
	std::cout << "#                   #" << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << std::endl;

}

//screen options
void options() {

	std::cout << "1: Rate My Nutrition" << std::endl;
	std::cout << "2: BMI Calculator" << std::endl;
	std::cout << "3: Nutrition & Exercise Tips" << std::endl;
	std::cout << "4: Pace Calculator" << std::endl;
	std::cout << "5: Split Calculator" << std::endl;
	std::cout << "X: Quit" << std::endl;
	std::cout << std::endl;
}

//prints the previous information from the main screen if screen input is invalid
void print_prev_main() {

	system("clear");
	title();
	options();

}

//returns int of selected screen
int /*char*/ screen_select() {

	//main screen options
	options();
	std::cout << "Enter a number to select: ";

	std::string num_str;
	std::getline(std::cin, num_str);
	int num = -1;

	if(num_str == "X" || num_str == "x") {
		return 0;
	}

	//if input is improper (not a number)
	while(num_str == "" || check_number(num_str) == false) {
		print_prev_main();
		std::cerr << "ERROR: \"" << num_str << "\" is not a proper input.  Please try again" << std::endl;
		std::cout << "Enter a number to select: ";
        std::getline(std::cin, num_str);

        if(num_str == "X" || num_str == "x") {
			return 0;
		}
    }

    //convert input from string to int
    num = std::stoi(num_str);

    //if input is improper (not a valid number)
    //also checks if new imput is a number or not
    while(num < 1 || num > 5) {
    	print_prev_main();
    	std::cerr << "ERROR: \"" << num_str << "\" is not a proper input.  Please try again" << std::endl;
    	std::cout << "Enter a number to select: ";
        std::getline(std::cin, num_str);

        if(num_str == "X" || num_str == "x") {
			return 0;
		}

        if(num_str == "" || check_number(num_str) == false) { continue; }
        num = std::stoi(num_str);
    }

	std::cout << std::endl;

	//return correct input to main
	return num;

	/*int input = getchar();
	while(input != 'x' && input != 'X' && input != '1' && input != '2' && input != '3' && input != '4' && input != '5') {
		print_prev_main();
		std::cerr << "ERROR: Not a proper input.  Please try again" << std::endl;
		std::cout << "Enter a number to select: ";
		input = getchar();
	}
	return input;*/

}

//main code
int main(/*int argc, char* argv[]*/) {

	system("clear");
	system("clear");
	title();
	int /*char*/ select = screen_select();

	//if user inputs 1 (rate_log)
	if(select == 1) { 

		system("clear");
		rate_log();
		main();

	//if user inputs 2 (bmi)
	} else if(select == 2) {

		system("clear");
		bmi_();
		main();

	//if user inputs 3 (exercise_tips)
	} else if(select == 3) {

		system("clear");
		nutrition();
		main();

	//if the user inputs 4 (pace)
	} else if(select == 4) {

		system("clear");
		pace_calculator();
		main();

	//if the user inputs 5 (splits)
	} else if(select == 5) {

		system("clear");
		splits_();
		main();

	//if user inputs x (quit)
	} else if(select == 0 /*select == 'x' || select == 'X'*/) {

		system("clear");
		return 1;

	}

	//shouldn't ever run but just in case (somehow inproper input make it past screen_select() )
	else {

		std::cerr << "Achievement unlocked: How did we get here?" << std::endl;
		return 0;

	}

	//end of code
	return 1;

}
