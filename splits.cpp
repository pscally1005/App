/*
	This is the code for the split calculator, which gives you prompts to input a pace and it
	will print out the splits you need to run for various distances
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <conio.h>
#include "pace.h"

typedef unsigned int uint;

//prints the first few lines of the screen
void print_top() {

	system("cls");
	std::cout << "SPLIT CALCULATOR" << std::endl;
	std::cout << "\nThis section will give you a prompt to enter a pace (in min/mi or min/km), and will give you your splits" << std::endl;

}

//returns true if the user selects metric units, returns false if not
bool check_metric_SPLITS() {

	std::cout << std::endl;
	print_units();
	std::cout << "\nEnter a number to select a unit: ";

    /*std::string unit_str;
    std::getline(std::cin, unit_str);
    int unit = -1;

    //if input is not correct
    while(unit_str != "1" && unit_str != "2") {
        print_top();
        std::cout << std::endl;
        print_units();
        std::cerr << "\nERROR: \"" << unit_str << "\" is not a proper input.  Please try again" << std::endl;
        std::cout << "Enter a number to select a unit: ";
        std::getline(std::cin, unit_str);
    }

    unit = std::stoi(unit_str);*/

    char unit = getch();
    while(unit != '1' && unit != '2') {
        print_top();
        std::cout << std::endl;
        print_units();
        std::cerr << "\nERROR: Not a proper input.  Please try again" << std::endl;
        std::cout << "Enter a number to select a unit: ";
        unit = getch();
    }

    print_top();
    std::cout << std::endl;
    print_units();
    std::cout << std::endl;
    std::cout << "Enter a number to select a unit: " << unit << "\n" << std::endl;

    if(unit == '1') { return false; }     //return false if not metric
    else { return true; }               //return true if metric

}

std::string input_pace(bool is_metric) {

	if(is_metric == false) { std::cout << "Enter a pace (min/mile, format \"MM:SS\"): "; }
	else { std::cout << "Enter a pace (min/km, format \"MM:SS\"): "; }

	std::string pace;
	std::getline(std::cin, pace);

	int unit = 1;
    if(is_metric == true) { unit = 2; }

	//convert char to str
    std::string d0(1, pace[0]);
    std::string d1(1, pace[1]);
    std::string d3(1, pace[3]);
    std::string d4(1, pace[4]);

    bool incorrect_input = (d3 == "6") || (d3 == "7") || (d3 == "8") || (d3 == "9");// || (d0 == "6") || (d0 == "7") || (d0 == "8") || (d0 == "9");
    bool all_zero = (d0 == "0") && (d1 == "0") && (d3 == "0") && (d4 == "0");
    bool correct_colons = (pace[2] == ':');
    bool all_nums = (check_number(d0) == true) && (check_number(d1) == true) && (check_number(d3) == true) && (check_number(d4) == true);

    while((pace.length() != 5) || (all_nums == false) || (incorrect_input == true) || (all_zero == true) || (correct_colons == false)) {

        print_top();
        std::cout << std::endl;
        print_units();
    	std::cout << "\nEnter a number to select a unit: " << unit << "\n" << std::endl;
        std::cerr << "ERROR: \"" << pace << "\" is not a proper input.  Please try again" << std::endl;
        
        //unit check
        if(is_metric == true) { std::cout << "Enter a pace (min/km, format \"MM:SS\"): "; }
        else { std::cout << "Enter a pace (min/mile, format \"MM:SS\"): ";}

        std::getline(std::cin, pace);

        d0 = pace[0];
        d1 = pace[1];
        d3 = pace[3];
        d4 = pace[4];

        incorrect_input = (d3 == "6") || (d3 == "7") || (d3 == "8") || (d3 == "9");// || (d0 == "6") || (d0 == "7") || (d0 == "8") || (d0 == "9");
        all_zero = (d0 == "0") && (d1 == "0") && (d3 == "0") && (d4 == "0");
        correct_colons = (pace[2] == ':');
        all_nums = (check_number(d0) == true) && (check_number(d1) == true) && (check_number(d3) == true) && (check_number(d4) == true);

    }

    print_top();
    std::cout << std::endl;
    print_units();
    std::cout << "\nEnter a number to select a unit: " << unit << "\n" << std::endl;

    //unit check
    if(is_metric == true) { std::cout << "Enter a pace (min/km, format \"MM:SS\"): " << pace << std::endl ; }
    else { std::cout << "Enter a pace (min/mile, format \"MM:SS\"): " << pace << std::endl;}

    std::cout << std::endl;
	return pace;

}

//calculates pace for various distances, stores them in a vector (shortest --> longest)
std::vector<float> calculate_splits(std::string pace, bool is_metric) {

	/** Paces I want to calculate and what index thex are stored in:
	 * 
	 * [0] 100 m
	 * [1] 200 m
	 * [2] 400 m
	 * [3] 800 m
	 * [4] 1 km
	 * [5] 1 mile
	 * [6] 5 km
	 * [7] 10 km
	 * [8] Half marathon
	 * [9] Marathon
	 * 
	**/

	std::cout << "Calculating splits based on a pace of " << pace;
	if(is_metric == true) {
		float cust_pace = conv_pace(pace);
		std::string cust_pace_str = pace_to_cust(cust_pace);
		std::cout << " min/km (" << cust_pace_str << " min/mi)..." << std::endl;
	}
	else {
		float metric_pace = conv_pace(pace);
		std::string metric_pace_str = pace_to_metric(metric_pace);
		std::cout << " min/mi (" << metric_pace_str << " min/km)..." << std::endl;
	}

	float pace_num = conv_pace(pace);

	std::vector<float> splits;
	//create 10 slots in vector
	for(uint i = 0; i < 10; i++) { splits.push_back(-1); }

	if(is_metric == false) {

		splits[0] = pace_num / 16.0;	//100 m time
		splits[1] = pace_num / 8.0;		//200 m time
		splits[2] = pace_num / 4.0;		//400 m time
		splits[3] = pace_num / 2.0;		//800 m time
		splits[4] = pace_num / 1.60934;	//1000 m time
		splits[5] = pace_num;			//1 mile time
		splits[6] = pace_num * 3.10686;	//5 km time
		splits[7] = pace_num * 6.21371;	//10 km time
		splits[8] = pace_num * 13.1;	//half marathon time
		splits[9] = pace_num * 26.2;	//marathon time

	} else {

		splits[0] = pace_num / 10.0;	//100 m time
		splits[1] = pace_num / 5.0;		//200 m time
		splits[2] = pace_num / 2.5;		//400 m time
		splits[3] = pace_num / 1.25;	//800 m time
		splits[4] = pace_num;			//1000 m time
		splits[5] = pace_num * 1.60934;	//1 mile time
		splits[6] = pace_num * 5.0;		//5 km time
		splits[7] = pace_num * 10.0;	//10 km time
		splits[8] = pace_num * 21.0975;	//half marathon time
		splits[9] = pace_num * 42.195;	//marathon time

	}

	return splits;

}

//code to format the pace in seconds to MM:SS
std::vector<std::string> format_vec(const std::vector<float> &splits) {

	std::vector<std::string> formatted_splits;

	for(uint i = 0; i < splits.size(); i++) { formatted_splits.push_back("-1"); }

	//leave 100m, and 200m the way they are (keep them in seconds)
	for(uint i = 0; i < 2; i++) {
		formatted_splits[i] = std::to_string(splits[i]);
	}

	//make 400m, 800m, 1km, 1 mile, and 5km into MM:SS
	for(uint i = 2; i < 7; i++) {
    	int minutes = splits[i] / 60;

    	std::string min_str = std::to_string(minutes%60);
    	if((minutes%60) < 10) { min_str = "0" + std::to_string(minutes%60); }

    	std::string sec_str = std::to_string(((int) splits[i])%60);
    	if((((int) splits[i])%60) < 10) { sec_str = "0" + std::to_string(((int) splits[i])%60); }

    	std::string answer = min_str + ":" + sec_str;
    	formatted_splits[i] = answer;

	}

	//make 10km, half marathon, and marathon in HH:MM:SS
	for(uint i = 7; i < 10; i++) {
    	int minutes = splits[i] / 60;
    	int hours = minutes / 60;

    	std::string hour_str = std::to_string(hours);
    	if(hours < 10) { hour_str = "0" + std::to_string(hours); }

    	std::string min_str = std::to_string(minutes%60);
    	if((minutes%60) < 10) { min_str = "0" + std::to_string(minutes%60); }

    	std::string sec_str = std::to_string(((int) splits[i])%60);
    	if((((int) splits[i])%60) < 10) { sec_str = "0" + std::to_string(((int) splits[i])%60); }

    	std::string answer = hour_str + ":" + min_str + ":" + sec_str;
    	formatted_splits[i] = answer;

	}

	//for(uint i = 0; i < formatted_splits.size(); i++) {std::cout << formatted_splits[i] << " "; }
	std::cout << std::endl;
	return formatted_splits;

}

//code to print the splits
void print_splits(const std::vector<std::string> &formatted_splits) {

	//round the 100 m and 200 m times to 2 decimal places (4 sig figs)
	std::string one;
	std::string two;
	for(uint i = 0; i < 5; i ++) { one += formatted_splits[0][i]; }
	for(uint i = 0; i < 5; i ++) { two += formatted_splits[1][i]; }

	//print statements for all the splits
	std::cout << "100 m:         " << one << " seconds" << std::endl;
	std::cout << "200 m:         " << two << " seconds" << std::endl;
	std::cout << "400 m:         " << formatted_splits[2] << " (MM:SS)" << std::endl;
	std::cout << "800 m:         " << formatted_splits[3] << " (MM:SS)" << std::endl;
	std::cout << "1 km:          " << formatted_splits[4] << " (MM:SS)" << std::endl;
	std::cout << "1 mi:          " << formatted_splits[5] << " (MM:SS)" << std::endl;
	std::cout << "5 km:          " << formatted_splits[6] << " (MM:SS)" << std::endl;
	std::cout << "10 km:         " << formatted_splits[7] << " (HH:MM:SS)" << std::endl;
	std::cout << "Half marathon: " << formatted_splits[8] << " (HH:MM:SS)" << std::endl;
	std::cout << "Marathon:      " << formatted_splits[9] << " (HH:MM:SS)" << std::endl;

}

//essentially main function for split calculator, code for the whole screen
void splits_() {

	print_top();
	bool is_metric = check_metric_SPLITS();
	std::string pace = input_pace(is_metric);

	std::vector<float> splits = calculate_splits(pace, is_metric);
	std::vector<std::string> formatted_splits = format_vec(splits);
	print_splits(formatted_splits);

	/*std::string exit;
    std::cout << "\nEnter \"Y\" to stay on the current screen, or anything else to return to the main menu: ";
    std::getline(std::cin, exit);
    if(exit == "y" || exit == "Y") { splits_(); }*/

    std::cout << "\nEnter \"Y\" to stay on the current screen, or anything else to return to the main menu: ";
    char exit = getch();
    if(exit == 'y' || exit == 'Y') { splits_(); }

}