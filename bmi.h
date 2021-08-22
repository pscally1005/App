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

//prints all the previos information, used if wrong input is put for back_to_main_screen_b
void print_prev(bool is_metric, float h, float g, float bmi, int digits);

//back_to_main_screen specific to bmi
bool back_to_main_screen_b(bool is_metric, float h, float g);

//essentially main function for rate_log, code for the whole screen
void bmi_();

#endif