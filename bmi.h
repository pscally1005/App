/*
	This is the .h for the bmi calculator
*/

#ifndef __bmi_h_
#define __bmi_h_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdio>

//prints the top header text
void print_top_BMI();

//returns true if string is a number
bool check_number(std::string str);

//prints the text for unit selection
void unit_select_text();

//returns true if user selects metric units, false otherwise
bool check_metric_BMI();

//clears error messages after correct unit is entered
void print_before_height(bool is_metric);

//all height input, calclulation, returns height
float height(bool is_metric);

//clears error messages after correct height is entered
void print_before_weight(bool is_metric, float h);

//all weight input, calculation, returns weight
float weight(bool is_metric);

//clears error messages after correct weight is entered
void print_after_weight(bool is_metric, float h, float w);

//essentially main function for bmi calculator, code for the whole screen
void bmi_();

#endif