/*
	This is the code for nutrition, which lets you read various tips/ways to help you exercise and give you nutrition tips
*/

#include <iostream>
#include <string>
#include <cstdio>
#include "nutrition.h"

//prints header of screen
void print_top_NE() {
    system("clear");
    std::cout << "NUTRITION & EXERCISE TIPS" << std::endl;
    std::cout << "This section will give you various exercise and nutrition tips to help you" << std::endl;
}

//reprints top with choice of nutrition of exercise tips
void print_choice_NE(/*std::string*/ char str) {
    print_top_NE();

    std::cout << "\nWould you like to see exercise or nutrition tips?" << std::endl;
    std::cout << "1: Nutrition Tips" << std::endl;
    std::cout << "2: Exercise Tips" << std::endl;
    std::cout << "\nPlease enter a number: " << str << std::endl;
}

//list of exercise tips
void e_tips() {

    //list of exercise tips, will expand as the app goes on
    std::cout << "\nHere are a list of tips to help you start and stay exercising:" << std::endl;

    std::cout << "- Develop a plan at the beginning of the week" << std::endl;
    std::cout << "- Stick to a routine, such as exercising around the same time each day" << std::endl;
    std::cout << "- Make sure to have proper rest days to not burn yourself out or injure yourself" << std::endl;
    std::cout << "- Start out small.  Don't try to overwhelm yourself right away" << std::endl;

}

//list of nutrition tips
void n_tips() {

    //list of nutrition tips, will expand as the app goes on
    std::cout << "\nHere are a list of tips to help you eat healthy:" << std::endl;

    std::cout << "- There are approximately 9 calories in a gram of fat" << std::endl;
    std::cout << "- There are approximately 4 calories in a gram of carb or protein" << std::endl;

}

void nutrition() {

    print_top_NE();

    std::cout << "\nWould you like to see exercise or nutrition tips?" << std::endl;
    std::cout << "1: Nutrition Tips" << std::endl;
    std::cout << "2: Exercise Tips" << std::endl;
    std::cout << "\nPlease enter a number: ";
    
    /*std::string input;
    std::getline(std::cin, input);

    while(input != "1" && input != "2") {
        print_top_NE();
        std::cout << "\nWould you like to see exercise or nutrition tips?" << std::endl;
        std::cout << "1: Nutrition Tips" << std::endl;
        std::cout << "2: Exercise Tips" << std::endl;
        std::cerr << "\nERROR: \"" << input << "\" is not a valid input.  Please try again" << std::endl;
        std::cout << "Please enter a number: ";
        std::getline(std::cin, input);
    }

    print_top_NE();
    print_choice_NE(input);

    if(input == "1") { n_tips(); }
    else if(input == "2") { e_tips(); }
    else { std::cerr << "ERROR: \"" << input << "\" is invalid" << std::endl; }*/

    char input = getchar();
    while(input != '1' && input != '2') {
        print_top_NE();
        std::cout << "\nWould you like to see exercise or nutrition tips?" << std::endl;
        std::cout << "1: Nutrition Tips" << std::endl;
        std::cout << "2: Exercise Tips" << std::endl;
        std::cerr << "\nERROR: Not a valid input.  Please try again" << std::endl;
        std::cout << "Please enter a number: ";
        input = getchar();
    }

    print_top_NE();
    print_choice_NE(input);
    if(input == '1') { n_tips(); }
    else if(input == '2') { e_tips(); }
    else { std::cerr << "Achievement unlocked: How did we get here?" << std::endl; }

    /*std::string exit;
    std::cout << "\nEnter \"Y\" to stay on the current screen, or anything else to return to the main menu: ";
    std::getline(std::cin, exit);
    if(exit == "y" || exit == "Y") { nutrition(); }*/

    std::cout << "\nEnter \"Y\" to stay on the current screen, or anything else to return to the main menu: ";
    char exit = getchar();
    if(exit == 'y' || exit == 'Y') { nutrition(); }

}