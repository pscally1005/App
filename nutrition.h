/*
	This is the .h for the exercise_tips, which is essentially just a page of text that lets you read 
	different tips on exercising and nutrition
*/

#ifndef __nutrition_h_
#define __nutrition_h_

#include <iostream>
#include <string>
#include <cstdio>

//prints header of screen
void print_top_NE();

//list of exercise tips
void e_tips();

//list of nutrition tips
void n_tips();

//reprints top with choice of nutrition of exercise tips
void print_choice_NE(std::string /*char*/ str);

//essentially main function for nutrition, code for the whole screen
void nutrition();

#endif