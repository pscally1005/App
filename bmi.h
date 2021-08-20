/*
	This is the .h for the bmi calculator
*/

#ifndef __bmi_h_
#define __bmi_h_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

//returns true if string is a number
bool check_number(std::string str);

//returns true if user selects metric units, false otherwise
bool check_metric();

//essentially main function for rate_log, code for the whole screen
void bmi();

#endif