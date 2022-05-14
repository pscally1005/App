/*
	This is the .h for the split calculator
*/

#ifndef __splits_h_
#define __splits_h_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdio>

//prints the first few lines of the screen
void print_top();

//returns true if user selects metric units, returns false if not
bool check_metric_SPLITS();

//code for user to input a pace, returns the pace as a string
std::string input_pace(bool is_metric);

//calculates pace for various distances, stores them in a vector (shortest --> longest)
std::vector<float> calculate_pace(std::string pace, bool is_metric);

//code to format the pace in seconds to MM:SS
std::vector<std::string> format_vec(const std::vector<float> &splits);

//code to print the splits
void print_splits(const std::vector<std::string> &formatted_splits);

//essentially main function for split calculator, code for the whole screen
void splits_();

#endif