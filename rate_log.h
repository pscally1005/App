/*
	This is the .h for the rate_log, which lets you rate your nutrition for the day from 1-5
*/

#ifndef __rate_log_h_
#define __rate_log_h_

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <cstdio>

//prints the top header information
void print_top_RL();

//returns true if string is a number
bool check_number(std::string str);

//prints out header information up until after entering the num
void after_num(int num);

//enter a num from 1 to 5, return the inputted number or -1 if error
/*int*/ char enter_num();

//returns formatted date and time
std::string return_date_time();

//essentially main function for rate_log, code for the whole screen
void rate_log();

#endif