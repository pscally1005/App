/*
	This is the .h for the exercise_tips, which is essentially just a page of text that lets you read different tips on exercising
*/

#ifndef __exercise_tips_h_
#define __exercise_tips_h_

#include <iostream>
#include <string>

//back_to_main_screen specific to exercise_tips
bool back_to_main_screen_et();

//prints all the previos information, used if wrong input is put for back_to_main_screen_et
void print_prev();

//essentially main function for exercise_tips, code for the whole screen
void exercise_tips();

#endif