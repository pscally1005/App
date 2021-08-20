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

typedef unsigned int uint;

void title() {

	std::cout << "#####################" << std::endl;
	std::cout << "#                   #" << std::endl;
	std::cout << "# [ENTER NAME HERE] #" << std::endl;
	std::cout << "#                   #" << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << std::endl;

}

int screen_select() {

	std::cout << "1: Rate My Nutrition" << std::endl;
	std::cout << "2: BMI Calculator" << std::endl;
	std::cout << "3: Quit" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a number to select: ";

	std::string num_str;
	std::getline (std::cin, num_str);
	int num = -1;

	while(check_number(num_str) == false) {
		std::cerr << "ERROR: Improper input.  Please try again" << std::endl;
        std::cout << std::endl;
        
		std::cout << "1: Rate My Nutrition" << std::endl;
		std::cout << "2: BMI Calculator" << std::endl;
		std::cout << "3: Quit" << std::endl;
		std::cout << std::endl;
		std::cout << "Enter a number to select: ";

        std::getline(std::cin, num_str);
    }

    num = std::stoi(num_str);

    while(num < 1 || num > 3) {
    	std::cerr << "ERROR: Improper input.  Please try again" << std::endl;
        std::cout << std::endl;

		std::cout << "1: Rate My Nutrition" << std::endl;
		std::cout << "2: BMI Calculator" << std::endl;
		std::cout << "3: Quit" << std::endl;
		std::cout << std::endl;
		std::cout << "Enter a number to select: ";

        std::getline(std::cin, num_str);
        if(check_number(num_str) == false) { continue; }
        num = std::stoi(num_str);
    }

	std::cout << std::endl;
	return num;
	
}

bool back_to_main_screen() {

	std::cout << std::endl;
	std::cout << "Do you want to return to the main screen (y/n)? ";
	std::string input;
	getline (std::cin, input);

	while(input != "y" && input != "n") {
		std::cerr << "ERROR: Improper input, please try again" << std::endl;
		std::cout << "Do you want to return to the main screen (y/n)? ";
		getline (std::cin, input);
	}

	std::cout << std::endl;

	if(input == "y") { return true; }
	else { return false; }

}

int main(/*int argc, char* argv[]*/) {

	title();
	int select = screen_select();

	if(select == 1) { 

		bool stay = true;
		while(stay == true) {
			rate_log();
			if(back_to_main_screen() == true) { stay = false; main(); }
			else { continue; }
		}

	} else if(select == 2) {

		bool stay = true;
		while(stay == true) {
			bmi();
			if(back_to_main_screen() == true) { stay = false; main(); }
			else { continue; }
		}

	} else if(select == 3) {
		std::cout << "Quitting Now" << std::endl;
		exit(1);
	}
	else {

		std::cerr << "ERROR: Improper Input" << std::endl;
		return 0;

	}

	return 1;

}
