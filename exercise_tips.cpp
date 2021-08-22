/*
	This is the code for the exercise_tips, which lets you read various tips/ways to help you exercise
*/

#include <iostream>
#include <string>
#include "exercise_tips.h"

void tips() {

    //list of exercise tips, will expand as the app goes on.  This is probably all this screen will be used for
    std::cout << "\nHere are a list of tips to help you start and stay exercising:" << std::endl;
    std::cout << "- Develop a plan at the beginning of the week" << std::endl;
    std::cout << "- Stick to a routine, such as exercising around the same time each day" << std::endl;
    std::cout << "- Make sure to have proper rest days to not burn yourself out or injure yourself" << std::endl;
    std::cout << "- Start out small.  Don't try to overwhelm yourself right away" << std::endl;

}

//reprints out information from before, which is just the tips
void print_prev() {

    system("cls");
    std::cout << "EXERCISE TIPS" << std::endl;
    tips();
    std::cout << std::endl;

}

//returning to main screen
bool back_to_main_screen_et() {

    std::cout << std::endl;
    std::cout << "Do you want to return to the main screen (y/n)? ";
    std::string input;
    getline (std::cin, input);

    //checks to make sure input is only "y" or "n"
    while(input != "y" && input != "n") {
        print_prev();
        std::cerr << "ERROR: \"" << input << "\" is not a proper input.  Please try again" << std::endl;
        std::cout << "Do you want to return to the main screen (y/n)? ";
        getline (std::cin, input);
    }

    std::cout << std::endl;

    system("cls");
    if(input == "y") { return true; }
    else { return false; }

}

void exercise_tips() {

    std::cout << "EXERCISE TIPS" << std::endl;
    tips();

    bool back = back_to_main_screen_et();
    if(back == false) { exercise_tips(); }

}