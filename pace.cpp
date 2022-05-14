/*
	This is the code for the pace calculator, which gives you prompts to input a distance, pace, and time
    Enter 2 to calculate the third
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include "pace.h"

typedef unsigned int uint;

//returns true if the user selects metric units, returns false if not
bool units() {

    print_units();
    std::cout << "\nEnter a number to select a unit: ";

    std::string unit_str;
    std::getline(std::cin, unit_str);
    int unit = -1;

    //if input is not correct
    while(unit_str != "1" && unit_str != "2") {
        system("clear");
        print_header();
        print_units();
        std::cout << std::endl;
        std::cerr << "ERROR: \"" << unit_str << "\" is not a proper input.  Please try again" << std::endl;
        std::cout << "Enter a number to select a unit: ";
        std::getline(std::cin, unit_str);
    }

    unit = std::stoi(unit_str);

    /*char unit = getchar();
    while(unit != '1' && unit != '2') {
        print_header();
        print_units();
        std::cout << std::endl;
        std::cerr << "ERROR: Not a proper input.  Please try again" << std::endl;
        std::cout << "Enter a number to select a unit: ";
        unit = getchar();
    }*/

    system("clear");
    print_header();
    print_units();
    std::cout << std::endl;
    std::cout << "Enter a number to select a unit: " << unit << "\n" << std::endl;

    if(unit == 1) { return false; }     //return false if not metric
    else { return true; }               //return true if metric

}

//prints the first few lines of the output
void print_header() {

    system("clear");
    std::cout << "PACE CALCULATOR\n" << std::endl;
    std::cout << "This section will give you prompts to enter a distance, time, and pace" << std::endl;
    std::cout << "Enter 2 to calculate the third.  For the one you want to calculate, enter \"x\"\n" << std::endl;

}

//prints the units text
void print_units() {

    std::cout << "What units do you use?" << std::endl;
    std::cout << "1: Customary (miles)" << std::endl;
    std::cout << "2: Metric (kilometers)" << std::endl;

}

//code for user to input a distance
float input_distance(bool is_metric) {

    //Enter distance
    std::string distance_str;

    //unit check
    if(is_metric == true) { std::cout << "Enter a distance in kilometers: "; }
    else { std::cout << "Enter a distance in miles: "; }

    std::getline(std::cin, distance_str);
    float distance = -1;

    //user entered x, wants to calculate distance
    if(distance_str == "x" || distance_str == "X") { 
        std::cout << std::endl;
        return distance;
    }

    //if input is improper (not a positive number)
    while(distance_str == "" || distance_str == "." || check_number(distance_str) == false || distance_str[0] == '0') {

        system("clear");
        print_header();
        print_units();
        std::cout << "\nEnter a number to select a unit: ";

        if(is_metric == true) { std::cout << "2\n" << std::endl; }
        else { std::cout << "1\n" << std::endl; }

        std::cerr << "ERROR: \"" << distance_str << "\" is not a proper input.  Distance must be a positive number.";
        std::cerr << "  Please try again" << std::endl;

        //unit check
        if(is_metric == true) { std::cout << "Enter a distance in kilometers: "; }
        else { std::cout << "Enter a distance in miles: "; }

        std::getline(std::cin, distance_str);

        //user entered x, wants to calculate distance
        if(distance_str == "x" || distance_str == "X") { break; }

    }

    //converts input string to int
    if(distance_str == "x" || distance_str == "X") { distance = -1; }
    else{ distance = std::stof(distance_str); }
    
    print_distance(is_metric, distance);
    std::cout << std::endl;
    return distance;

}

//code for user to input a time
std::string input_time(bool is_metric, float distance) {

    std::string time;

    std::cout << "Enter a time (format \"HH:MM:SS\"): ";
    std::getline(std::cin, time);

    //user entered x, wants to calculate time
    if(time == "x" || time == "X") { 
        std::cout << std::endl;
        return time;
    }

    //convert char to str
    std::string d0(1, time[0]);
    std::string d1(1, time[1]);
    std::string d3(1, time[3]);
    std::string d4(1, time[4]);
    std::string d6(1, time[6]);
    std::string d7(1, time[7]);

    bool incorrect_input = (d6 == "6") || (d6 == "7") || (d6 == "8") || (d6 == "9") || (d3 == "6") || (d3 == "7") || (d3 == "8") || (d3 == "9");
    bool all_zero = (d0 == "0") && (d1 == "0") && (d3 == "0") && (d4 == "0") && (d6 == "0") && (d7 == "0");
    bool correct_colons = (time[2] == ':') && (time[5] == ':');
    bool all_nums = (check_number(d0) == true) && (check_number(d1) == true) && (check_number(d3) == true) && (check_number(d4) == true) && (check_number(d6) == true) && (check_number(d7) == true);

    while((time.length() != 8) || (all_nums == false) || (incorrect_input == true) || (all_zero == true) || (correct_colons == false)) {

        print_distance(is_metric, distance);
        std::cerr << "\nERROR: \"" << time << "\" is not a proper input.  Please try again" << std::endl;
        std::cout << "Enter a time (format \"HH:MM:SS\"): ";
        std::getline(std::cin, time);

        //user entered x, wants to calculate time
        if(time == "x" || time == "X") { break; }

        d0 = time[0];
        d1 = time[1];
        d3 = time[3];
        d4 = time[4];
        d6 = time[6];
        d7 = time[7];

        incorrect_input = (d6 == "6") || (d6 == "7") || (d6 == "8") || (d6 == "9")
                    || (d3 == "6") || (d3 == "7") || (d3 == "8") || (d3 == "9");
        all_zero = (d0 == "0") && (d1 == "0") && (d3 == "0") && (d4 == "0") && (d6 == "0") && (d7 == "0");
        correct_colons = (time[2] == ':') && (time[5] == ':');
        all_nums = (check_number(d0) == true) && (check_number(d1) == true) && (check_number(d3) == true) && (check_number(d4) == true) && (check_number(d6) == true) && (check_number(d7) == true);

    }

    print_time(is_metric, distance, time);
    std::cout << std::endl;

    return time;

}

//code for user to input a pace
std::string input_pace(bool is_metric, float distance, std::string time) {

    std::string pace;

    //unit check
    if(is_metric == true) { std::cout << "Enter a pace (min/km, format \"MM:SS\"): "; }
    else { std::cout << "Enter a pace (min/mile, format \"MM:SS\"): ";}

    std::getline(std::cin, pace);

    //user entered x, wants to calculate pace
    if(pace == "x" || pace == "X") { 
        std::cout << std::endl;
        return pace;
    }

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

        print_time(is_metric, distance, time);
        std::cerr << "\nERROR: \"" << pace << "\" is not a proper input.  Please try again" << std::endl;
        
        //unit check
        if(is_metric == true) { std::cout << "Enter a pace (min/km, format \"MM:SS\"): "; }
        else { std::cout << "Enter a pace (min/mile, format \"MM:SS\"): ";}


        std::getline(std::cin, pace);

        //user entered x, wants to calculate pace
        if(pace == "x" || pace == "X") { break; }

        d0 = pace[0];
        d1 = pace[1];
        d3 = pace[3];
        d4 = pace[4];

        incorrect_input = (d3 == "6") || (d3 == "7") || (d3 == "8") || (d3 == "9") || (d0 == "6") || (d0 == "7") || (d0 == "8") || (d0 == "9");
        all_zero = (d0 == "0") && (d1 == "0") && (d3 == "0") && (d4 == "0");
        correct_colons = (pace[2] == ':');
        all_nums = (check_number(d0) == true) && (check_number(d1) == true) && (check_number(d3) == true) && (check_number(d4) == true);

    }

    print_time(is_metric, distance, time);
    
    //unit check
    if(is_metric == true) { std::cout << "\nEnter a pace (min/km, format \"MM:SS\"): " << pace << std::endl ; }
    else { std::cout << "\nEnter a pace (min/mile, format \"MM:SS\"): " << pace << std::endl;}

    std::cout << std::endl;
    return pace;

}

//prints all above information up until distance
void print_distance(bool is_metric, float distance) {

    system("clear");
    print_header();
    print_units();
    std::cout << "\nEnter a number to select a unit: ";

    if(is_metric == true) { std::cout << "2\n" << std::endl; }
    else { std::cout << "1\n" << std::endl; }

    //unit check
    if(distance == -1 && is_metric == true) { std::cout << "Enter a distance in kilometers: x" << std::endl; }
    else if(distance == -1 && is_metric == false) { std::cout << "Enter a distance in miles: x" << std::endl; }
    else if(distance != -1 && is_metric == true) { std::cout << "Enter a distance in kilometers: " << distance << std::endl; }
    else { std::cout << "Enter a distance in miles: " << distance << std::endl; }

}

//prints all above information up until time
void print_time(bool is_metric, float distance, std::string time) {

    print_distance(is_metric, distance);
    std::cout << "\nEnter a time (format \"HH:MM:SS\"): " << time << std::endl;

}

//converts time string into seconds (float)
float conv_time(std::string time) {

    std::string time_hour = ""; time_hour += time[0]; time_hour += time[1];
    std::string time_minute = ""; time_minute += time[3]; time_minute += time[4];
    std::string time_second = ""; time_second += time[6]; time_second += time[7];
    int t_h = stoi(time_hour);
    int t_m = stoi(time_minute);
    int t_s = stoi(time_second);
    float total_time = (3600 * t_h) + (60 * t_m) + t_s;
    //std::cout << "total time in seconds is: " << total_time << std::endl;
    return total_time;

}

//converts pace string into seconds (float)
float conv_pace(std::string pace) {

    std::string pace_minute = ""; pace_minute += pace[0]; pace_minute += pace[1];
    std::string pace_second = ""; pace_second += pace[3]; pace_second += pace[4];
    int p_m = stoi(pace_minute);
    int p_s = stoi(pace_second);
    float total_pace = (60 * p_m) + p_s;
    //std::cout << "total pace in seconds is: " << total_pace << std::endl;
    return total_pace;

}

//converts pace from metric to customary
std::string pace_to_cust(float pace) {

    float seconds = pace * 1.60934;
    int minutes = seconds / 60;

    std::string min_str = std::to_string(minutes%60);
    if((minutes%60) < 10) { min_str = "0" + std::to_string(minutes%60); }

    std::string sec_str = std::to_string(((int) seconds)%60);
    if((((int) seconds)%60) < 10) { sec_str = "0" + std::to_string(((int) seconds)%60); }

    std::string cust_pace_str = min_str + ":" + sec_str;
    return cust_pace_str;

}

//converts pace from customary to metric
std::string pace_to_metric(float pace) {

    float seconds = pace / 1.60934;
    int minutes = seconds / 60;

    std::string min_str = std::to_string(minutes%60);
    if((minutes%60) < 10) { min_str = "0" + std::to_string(minutes%60); }

    std::string sec_str = std::to_string(((int) seconds)%60);
    if((((int) seconds)%60) < 10) { sec_str = "0" + std::to_string(((int) seconds)%60); }

    std::string metric_pace_str = min_str + ":" + sec_str;
    return metric_pace_str;

}

//code to calculate a distance with given time and pace
void calculate_distance(bool is_metric, std::string time, std::string pace) {

    float total_pace = conv_pace(pace);
    float total_time = conv_time(time);    

    //unit check
    if(is_metric == true) {

        std::string cust_pace_str = pace_to_cust(total_pace);
        std::cout << "You entered a time of " << time << ", and a pace of " << pace;
        std::cout << " min/km (" << cust_pace_str << " min/mi)" << std::endl; 

    } else {

        std::string metric_pace_str = pace_to_metric(total_pace);
        std::cout << "You entered a time of " << time << ", and a pace of " << pace;
        std::cout << " min/mi (" << metric_pace_str << " min/km)" << std::endl;

    }

    std::cout << "Calculating distance..." << std::endl;

    //calculating distance
    float answer = total_time / total_pace;

    if(is_metric == true) {
        float mi = answer / 1.60934;
        std::cout << "The distance is " << answer << " kilometers (" << mi << " miles)" << std::endl;
    }
    else {
        float km = answer * 1.60934;
        std::cout << "The distance is " << answer << " miles (" << km << " kilometers)" << std::endl;
    }

}

//code to calculate time with given distance and pace
void calculate_time(bool is_metric, float distance, std::string pace) {

    float total_pace = conv_pace(pace);

    //unit check
    if(is_metric == true && distance != 1) {

        float mi = distance / 1.60934;
        std::string cust_pace_str = pace_to_cust(total_pace);
        std::cout << "You entered a distance of " << distance << " kilometers (" << mi;
        std::cout << " miles), and a pace of " << pace << " min/km (" << cust_pace_str << " min/mi)" << std::endl; 

    } else if(is_metric == false && distance != 1) {

        float km = distance * 1.60934;
        std::string metric_pace_str = pace_to_metric(total_pace);
        std::cout << "You entered a distance of " << distance << " miles (" << km;
        std::cout << " kilometers), and a pace of " << pace << " min/mi (" << metric_pace_str << " min/km)" << std::endl;

    } else if(is_metric == true && distance == 1) {

        float mi = distance / 1.60934;
        std::string cust_pace_str = pace_to_cust(total_pace);
        std::cout << "You entered a distance of " << distance << " kilometer (" << mi;
        std::cout << " miles), and a pace of " << pace << " min/km (" << cust_pace_str << " min/mi)" << std::endl; 

    } else {

        float km = distance * 1.60934;
        std::string metric_pace_str = pace_to_metric(total_pace);
        std::cout << "You entered a distance of " << distance << " mile (" << km;
        std::cout << " kilometers), and a pace of " << pace << " min/mi (" << metric_pace_str << " min/km)" << std::endl;

    }

    std::cout << "Calculating time..." << std::endl;

    //calculate time and format into HH:MM:SS
    float seconds = distance * total_pace;
    int minutes = seconds / 60;
    int hours = minutes / 60;
    //std::cout << hours << " " << (minutes%60) << " " << (((int) seconds)%60) << std::endl;

    std::string hour_str = std::to_string(hours);
    if(hours < 10) { hour_str = "0" + std::to_string(hours); }

    std::string min_str = std::to_string(minutes%60);
    if((minutes%60) < 10) { min_str = "0" + std::to_string(minutes%60); }

    std::string sec_str = std::to_string(((int) seconds)%60);
    if((((int) seconds)%60) < 10) { sec_str = "0" + std::to_string(((int) seconds)%60); }

    std::string answer = hour_str + ":" + min_str + ":" + sec_str;
    std::cout << "The time is " << answer << std::endl;

}

//code to calculate pace with given distance and time
void calculate_pace(bool is_metric, float distance, std::string time) {

    //unit check
    if(is_metric == true && distance != 1) {

        float mi = distance / 1.60934;
        std::cout << "You entered a distance of " << distance << " kilometers (" << mi;
        std::cout << " miles), and a time of " << time << std::endl; 

    } else if(is_metric == false && distance != 1) {

        float km = distance * 1.60934;
        std::cout << "You entered a distance of " << distance << " miles (" << km;
        std::cout << " kilometers), and a time of " << time << std::endl;

    } else if(is_metric == true && distance == 1) {

        float mi = distance / 1.60934;
        std::cout << "You entered a distance of " << distance << " kilometer (" << mi;
        std::cout << " miles), and a time of " << time << std::endl; 

    } else {

        float km = distance * 1.60934;
        std::cout << "You entered a distance of " << distance << " mile (" << km;
        std::cout << " kilometers), and a time of " << time << std::endl;

    }

    std::cout << "Calculating pace..." << std::endl;

    float total_time = conv_time(time);

    //calculate pace and format into MM:SS
    float seconds = total_time / distance;
    int minutes = seconds / 60;
    //std::cout << (minutes%60) << " " << (((int) seconds)%60) << std::endl;

    std::string min_str = std::to_string(minutes%60);
    if((minutes%60) < 10) { min_str = "0" + std::to_string(minutes%60); }

    std::string sec_str = std::to_string(((int) seconds)%60);
    if((((int) seconds)%60) < 10) { sec_str = "0" + std::to_string(((int) seconds)%60); }

    std::string answer = min_str + ":" + sec_str;
    

    if(is_metric == true) {

        float pace = conv_pace(answer);
        std::string cust_pace_str = pace_to_cust(pace);
        std::cout << "The pace is " << answer << " min/km (" << cust_pace_str << " min/mi)" << std::endl;

    } else {

        float pace = conv_pace(answer);
        std::string metric_pace_str = pace_to_metric(pace);
        std::cout << "The pace is " << answer << " min/mi (" << metric_pace_str << " min/km)" <<  std::endl;

    }

}

//pace main code
void pace_calculator() {

    system("clear");

    //statement at top of code
	print_header();

    bool is_metric = units();
    
    //declaration of variables
    float distance = input_distance(is_metric);
    std::string time = input_time(is_metric, distance);
    std::string pace = input_pace(is_metric, distance, time);

    if((distance == -1 && (time == "x" || time == "X") ) || (distance == -1 && (pace == "x" || pace == "X") )
        || ( (time == "x" || time == "X") && (pace == "x" || pace == "X") )
        || (distance == -1 && (time == "x" || time == "X") && (pace == "x" || pace == "X") ) ) {

        std::cerr << "ERROR: Too many \"x\" values were entered";
    }
    else if(distance == -1) { calculate_distance(is_metric, time, pace); }
    else if(time == "x" || time == "X") { calculate_time(is_metric, distance, pace); }
    else if(pace == "x" || pace == "X") { calculate_pace(is_metric, distance, time); }
    else {
        std::cerr << "ERROR: No \"x\" was entered.";
    }

    std::string exit;
    std::cout << "\nEnter \"Y\" to stay on the current screen, or anything else to return to the main menu: ";
    std::getline(std::cin, exit);
    if(exit == "y" || exit == "Y") { pace_calculator(); }

    /*std::cout << "\nEnter \"Y\" to stay on the current screen, or anything else to return to the main menu: ";
    char exit = getchar();
    if(exit == 'y' || exit == 'Y') { pace_calculator(); }*/

}