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

bool check_metric() {
    std::cout << "What units do you use?" << std::endl;
    std::cout << "1: Customary (in/lbs)" << std::endl;
    std::cout << "2: Metric (cm/kg)" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter a number to select: ";

    std::string unit_str;
    std::getline(std::cin, unit_str);
    int unit = -1;

    while(check_number(unit_str) == false) {
        std::cout << std::endl;
        std::cerr << "ERROR: Improper input.  Please try again" << std::endl;
        std::cout << "Enter 1 for customary (in/lbs), enter 2 for metric (cm/kg): ";
        std::getline(std::cin, unit_str);
    }

    unit = std::stof(unit_str);

    while(unit < 1 || unit > 2) {
        std::cout << std::endl;
        std::cerr << "ERROR: Improper input.  Please try again" << std::endl;
        std::cout << "Enter 1 for customary (in/lbs), enter 2 for metric (cm/kg): ";
        std::getline(std::cin, unit_str);
        if(check_number(unit_str) == false) { continue; }
        unit = std::stoi(unit_str);
    }

    if(unit == 1) { return false; }     //return false if not metric
    else { return true; }               //return true if metric

}

void bmi() {

	std::cout << "You selected: BMI Calculator" << std::endl;

    bool is_metric = check_metric();

    //user enters their height in inches (want to have a unit selection)
    std::cout << "Enter your height in ";
    if(is_metric == false) { std::cout << "inches: "; }
    else { std::cout << "centimeters: "; }

    std::string height_str;
    std::getline(std::cin, height_str);
    float height = -1;

    while(height_str == "." || check_number(height_str) == false) {
        std::cout << std::endl;
        std::cerr << "ERROR: Improper input.  Please try again" << std::endl;
        std::cout << "Enter your height in inches: ";
        std::getline(std::cin, height_str);
    }

    height = std::stof(height_str);

    //convert inches to meters if is_metric is false
    //entered metric height is in cm, so need to convert that to meters
    if(is_metric == false) { height = height * 0.0254; }
    else { height = height / 100; }

    //user enters their weight in lbs (want to have a unit selection)
    std::cout << "Enter your weight in ";
    if(is_metric == false) { std::cout << "pounds: "; }
    else { std::cout << "kilograms: "; }

    std::string weight_str;
    std::getline(std::cin, weight_str);
    float weight = -1;

    while(weight_str == "." || check_number(weight_str) == false) {
        std::cout << std::endl;
        std::cerr << "ERROR: Improper input.  Please try again" << std::endl;
        std::cout << "Enter your weight in pounds: ";
        std::getline(std::cin, weight_str);
    }

    weight = std::stof(weight_str);

    //convert lbs to kg if is_metric is false
    if(is_metric == false) { weight = weight * 0.45351473922; }

    //calculate bmi
    float bmi = weight / (height * height);

    //make sure that bmi is always rounded to 1 decimal point, regardless of how big/small the number is
    //usless its something.0 (ex: 18.0)
    //calculates number of whole digits
    int temp = bmi;
    int digits = 0;
    while(temp > 0) {
        temp = temp / 10;
        digits++;
    }

    std::cout << "Your BMI is: " << std::setprecision(digits+2) << bmi << std::endl;

    if(bmi < 18.5) { std::cout << "You are in the underweight range" << std::endl; }
    else if(bmi >= 18.5 && bmi < 25) { std::cout << "You are in the normal weight range" << std::endl; }
    else if(bmi >= 25 && bmi < 30) { std::cout << "You are in the overweight weight range" << std::endl; }
    else { std::cout << "You are in the obese weight range" << std::endl; }

}