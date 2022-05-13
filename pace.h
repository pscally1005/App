/*
	This is the .h for the pace calculator
*/

#ifndef __pace_h_
#define __pace_h_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>

//returns true if string is a number
bool check_number(std::string str);

//returns true if user selects metric units, returns false if not
bool units();

//prints the first few lines of the screen
void print_header();

//prints the units text
void print_units();

//code to input a distance
float input_distance(bool is_metric);

//code to input a time
std::string input_time(bool is_metric, float distance);

//code to input a pace
std::string input_pace(bool is_metric, float distance, std::string time);

//print everything up until after distance
void print_distance(bool is_metric, float distance);

//print everything up until after time
void print_time(bool is_metric, float distance, std::string time);

//converts time string into seconds (float)
float conv_time(std::string time);

//converts pace string into seconds (float)
float conv_pace(std::string pace);

//converts pace from metric to customary
std::string pace_to_cust(float pace);

//converts pace from customary to metric
std::string pace_to_metric(float pace);

//calculate a distance with a given time and pace
void calculate_distance(bool is_metric, std::string time, std::string pace);

//calculate a time with a given distance and pace
void calculate_time(bool is_metric, float distance, std::string pace);

//calculate a pace with a given distance and time
void calculate_pace(bool is_metric, float distance, std::string time);

//essentially main function for pace calculator, code for the whole screen
void pace_calculator();

#endif