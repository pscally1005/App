/*
	This is the code for the rate_log, which lets you rate your nutrition for the day from 1-5
	This gets saved to a log file along with the date and time of the entry
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "bmi.h"

typedef unsigned int uint;

//https://www.tutorialspoint.com/cplusplus-program-to-check-if-input-is-an-integer-or-a-string
bool check_number(std::string str) {
   for (uint i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == false && str[i] != '.') {
            return false;
        }
    }
        return true;
}

//returns true if user selects metric units, false otherwise
bool check_metric() {

    //enter the number for the unit
    std::cout << "What units do you use?" << std::endl;
    std::cout << "1: Customary (in/lbs)" << std::endl;
    std::cout << "2: Metric (cm/kg)" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter a number to select: ";

    std::string unit_str;
    std::getline(std::cin, unit_str);
    int unit = -1;

    //if input is not correct
    while(unit_str == "" || check_number(unit_str) == false) {
        system("cls");
        std::cout << "BMI CALCULATOR\n" << std::endl;
        std::cout << "What units do you use?" << std::endl;
        std::cout << "1: Customary (in/lbs)" << std::endl;
        std::cout << "2: Metric (cm/kg)" << std::endl;
        std::cout << std::endl;
        std::cerr << "ERROR: \"" << unit_str << "\" is not a proper input.  Please try again" << std::endl;
        std::cout << "Enter a number to select: ";
        std::getline(std::cin, unit_str);
    }

    unit = std::stof(unit_str);

    //if input is not correct
    while(unit < 1 || unit > 2) {
        system("cls");
        std::cout << "BMI CALCULATOR\n" << std::endl;
        std::cout << "What units do you use?" << std::endl;
        std::cout << "1: Customary (in/lbs)" << std::endl;
        std::cout << "2: Metric (cm/kg)" << std::endl;
        std::cout << std::endl;
        std::cerr << "ERROR: \"" << unit_str << "\" is not a proper input.  Please try again" << std::endl;
        std::cout << "Enter a number to select: ";
        std::getline(std::cin, unit_str);
        if(unit_str == "" || check_number(unit_str) == false) { continue; }
        unit = std::stoi(unit_str);
    }

    std::cout << std::endl;

    if(unit == 1) { return false; }     //return false if not metric
    else { return true; }               //return true if metric

}

//clears error messages after correct unit is entered
void print_before_height(bool is_metric) {

    system("cls");
    std::cout << "BMI CALCULATOR\n" << std::endl;

    //reprint out unit information
    std::cout << "What units do you use?" << std::endl;
    std::cout << "1: Customary (in/lbs)" << std::endl;
    std::cout << "2: Metric (cm/kg)" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter a number to select: ";

    if(is_metric == false) { std::cout << "1" << std::endl; }
    else { std::cout << "2" << std::endl; }

}

//all height input, calculation, returns height
float height(bool is_metric) {

    std::cout << "\nEnter your height in ";
    if(is_metric == false) { std::cout << "inches: "; }
    else { std::cout << "centimeters: "; }

    std::string height_str;
    std::getline(std::cin, height_str);
    float height = -1;

    //if inproper height is inputted
    while(height_str == "" || height_str == "." || check_number(height_str) == false) {
        print_before_height(is_metric);
        std::cout << std::endl;
        std::cerr << "ERROR: \"" << height_str << "\" is not a proper input.  Please try again" << std::endl;
        std::cout << "Enter your height in inches: ";
        std::getline(std::cin, height_str);
    }

    //converts input string to float
    height = std::stof(height_str);

    //convert inches to meters if is_metric is false
    //entered metric height is in cm, so need to convert that to meters
    if(is_metric == false) { height = height * 0.0254; }
    else { height = height / 100; }

    //returns correctly inputted height
    return height;
}

//clears error messages after correct height is entered
void print_before_weight(bool is_metric, float h) {

    print_before_height(is_metric);

    //reprint out height information
    std::cout << "\nEnter your height in ";
    if(is_metric == false) { std::cout << "inches: "; }
    else { std::cout << "centimeters: "; }

    if(is_metric == false) { h = h / 0.0254; }
    else { h = h * 100; }
    std::cout << h << std::endl;

}

//all hight input, calculation, returns height
float weight(bool is_metric, float h) {

    std::cout << "\nEnter your weight in ";
    if(is_metric == false) { std::cout << "pounds: "; }
    else { std::cout << "kilograms: "; }

    std::string weight_str;
    std::getline(std::cin, weight_str);
    float weight = -1;

    //if inproper weight is inputted
    while(weight_str == "" || weight_str == "." || check_number(weight_str) == false) {
        print_before_weight(is_metric, h);
        std::cout << std::endl;
        std::cerr << "ERROR: \"" << weight_str << "\" is not a proper input.  Please try again" << std::endl;
        std::cout << "Enter your weight in pounds: ";
        std::getline(std::cin, weight_str);
    }

    //converts input from string to float
    weight = std::stof(weight_str);

    //convert lbs to kg if is_metric is false
    if(is_metric == false) { weight = weight * 0.45351473922; }

    //returns correctly inputted weight
    return weight;

}

//clears error messages after correct weight is entered
void print_after_weight(bool is_metric, float h, float w) {

    print_before_height(is_metric);
    print_before_weight(is_metric, h);

    //reprint out weight information
    std::cout << "\nEnter your weight in ";
    if(is_metric == false) { std::cout << "pounds: "; }
    else { std::cout << "kilograms: "; }

    if(is_metric == false) { w = w / 0.45351473922; }
    std::cout << w << std::endl;

}

void print_prev(bool is_metric, float h, float w, float bmi, int digits) {

    print_after_weight(is_metric, h, w);

    //prints bmi
    std::cout << "\nYour BMI is: " << std::setprecision(digits+2) << bmi << std::endl;

    //weight ranges
    if(bmi < 18.5) { std::cout << "You are in the underweight range\n" << std::endl; }
    else if(bmi >= 18.5 && bmi < 25) { std::cout << "You are in the normal weight range\n" << std::endl; }
    else if(bmi >= 25 && bmi < 30) { std::cout << "You are in the overweight weight range\n" << std::endl; }
    else { std::cout << "You are in the obese weight range\n" << std::endl; }

}

bool back_to_main_screen_b(bool is_metric, float h, float w, float bmi, int digits) {

    std::cout << std::endl;
    std::cout << "Do you want to return to the main screen (y/n)? ";
    std::string input;
    getline (std::cin, input);

    //checks to make sure input is only "y" or "n"
    while(input != "y" && input != "n") {
        print_prev(is_metric, h, w, bmi, digits);
        std::cerr << "ERROR: \"" << input << "\" is not a proper input.  Please try again" << std::endl;
        std::cout << "Do you want to return to the main screen (y/n)? ";
        getline (std::cin, input);
    }

    std::cout << std::endl;

    system("cls");
    if(input == "y") { return true; }
    else { return false; }

}

//bmi main code
void bmi_() {

	std::cout << "BMI CALCULATOR\n" << std::endl;

    bool is_metric = check_metric();
    print_before_height(is_metric);
    float h = height(is_metric);
    print_before_weight(is_metric, h);
    float w = weight(is_metric, h);
    print_after_weight(is_metric, h, w);

    //calculate bmi
    float bmi = w / (h * h);

    //make sure that bmi is always rounded to 1 decimal point, regardless of how big/small the number is
    //usless its something.0 (ex: 18.0)
    //calculates number of whole digits
    int temp = bmi;
    int digits = 0;
    while(temp > 0) {
        temp = temp / 10;
        digits++;
    }

    //prints bmi
    std::cout << "\nYour BMI is: " << std::setprecision(digits+2) << bmi << std::endl;

    //weight ranges
    if(bmi < 18.5) { std::cout << "You are in the underweight range" << std::endl; }
    else if(bmi >= 18.5 && bmi < 25) { std::cout << "You are in the normal weight range" << std::endl; }
    else if(bmi >= 25 && bmi < 30) { std::cout << "You are in the overweight weight range" << std::endl; }
    else { std::cout << "You are in the obese weight range" << std::endl; }

    bool back = back_to_main_screen_b(is_metric, h, w, bmi, digits);
    if(back == false) { bmi_(); }

}