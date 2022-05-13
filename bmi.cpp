/*
	This is the code for the bmi, which lets you calculator your bmi
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include "bmi.h"

typedef unsigned int uint;

//prints the top header text
void print_top_BMI() {

    system("cls");
    std::cout << "BMI CALCULATOR\n" << std::endl;
    std::cout << "This section will let you enter your height and weight and will calculate your BMI\n" << std::endl;

}

//https://www.tutorialspoint.com/cplusplus-program-to-check-if-input-is-an-integer-or-a-string
bool check_number(std::string str) {
   for (uint i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == false && str[i] != '.') {
            return false;
        }
    }
        return true;
}

//prints the text for unit selection
void unit_select_text() {

    std::cout << "What units do you use?" << std::endl;
    std::cout << "1: Customary (in/lbs)" << std::endl;
    std::cout << "2: Metric (cm/kg)" << std::endl;
    std::cout << std::endl;

}

//returns true if user selects metric units, false otherwise
bool check_metric_BMI() {

    unit_select_text();
    std::cout << "Enter a number to select a unit: ";

    /*std::string unit_str;
    std::getline(std::cin, unit_str);
    int unit = -1;

    //if input is not correct
    while(unit_str != "1" && unit_str != "2") {
        print_top_BMI();
        unit_select_text();
        std::cerr << "ERROR: \"" << unit_str << "\" is not a proper input.  Please try again" << std::endl;
        std::cout << "Enter a number to select a unit: ";
        std::getline(std::cin, unit_str);
    }

    unit = std::stoi(unit_str);
    std::cout << std::endl;

    if(unit == 1) { return false; }     //return false if not metric
    else { return true; }               //return true if metric*/

    char unit = getch();
    while(unit != '1' && unit != '2') {
        print_top_BMI();
        unit_select_text();
        std::cerr << "ERROR: Not a proper input.  Please try again" << std::endl;
        std::cout << "Enter a number to select a unit: ";
        unit = getch();
    }

    if(unit == '1') { return false; }     //return false if not metric
    else { return true; }               //return true if metric*/

}

//clears error messages after correct unit is entered
void print_before_height(bool is_metric) {

    print_top_BMI();
    unit_select_text();
    std::cout << "Enter a number to select a unit: ";

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
        std::cout << "Enter your height in ";
        if(is_metric == false) { std::cout << "inches: "; }
        else { std::cout << "centimeters: "; }

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
        std::cout << "Enter your weight in ";
        if(is_metric == false) { std::cout << "pounds: "; }
        else { std::cout << "kilograms: "; }

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

//bmi main code
void bmi_() {

    print_top_BMI();

    bool is_metric = check_metric_BMI();
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

    /*bool back = back_to_main_screen_b(is_metric, h, w, bmi, digits);
    if(back == false) { bmi_(); }*/

    /*std::string exit;
    std::cout << "\nEnter \"Y\" to stay on the current screen, or anything else to return to the main menu: ";
    std::getline(std::cin, exit);
    if(exit == "y" || exit == "Y") { bmi_(); }*/

    std::cout << "\nEnter \"Y\" to stay on the current screen, or anything else to return to the main menu: ";
    char exit = getch();
    if(exit == 'y' || exit == 'Y') { bmi_(); }

}