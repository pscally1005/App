/*
	This is the code for the rate_log, which lets you rate your nutrition for the day from 1-5
	This gets saved to a log file along with the date and time of the entry
*/

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <conio.h>
#include "rate_log.h"

typedef unsigned int uint;

//prints the top header information
void print_top_RL() {

    system("cls");
    std::cout << "RATE MY NUTRITION\n" << std::endl;
    std::cout << "This section will let you rate your daily nutrition and why you feel this way.  The results will be saved to a log file\n" << std::endl;

}

//prints out header information up until after entering the num
void after_num(/*int*/ char num) {

    print_top_RL();
    std::cout << "Rate your nutrition today from 1 to 5: " << num << std::endl;

}

//enter a num from 1 to 5, return the inputted number or -1 if error
/*int*/ char enter_num() {

	std::string num_str;
	std::cout << "Rate your nutrition today from 1 to 5: ";

	/*std::getline(std::cin, num_str);
    int num = -1;

    //if input is improper (not a number)
    while(num_str == "" || check_number(num_str) == false) {
        print_top_RL();
        std::cerr << "ERROR: \"" << num_str << "\" is not a proper input.  Please try again" << std::endl;
        std::cout << "Rate your nutrition today from 1 to 5: ";
        std::getline(std::cin, num_str);
    }

    //converts input string to int
    num = std::stoi(num_str);

    //if input is improper (wrong number)
    //also checks if input is a number
    while(num < 1 || num > 5) {
        print_top_RL();
        std::cerr << "ERROR: \"" << num_str << "\" is not a proper input.  Please try again\n" << std::endl;
        std::cout << "Rate your nutrition today from 1 to 5: ";
        std::getline(std::cin, num_str);
        if(num_str == "" || check_number(num_str) == false) { continue; }
        num = std::stoi(num_str);
    }

    after_num(num);

    //returns correct input
	return num;*/

    char input = getch();
    while(input != '1' && input != '2' && input != '3' && input != '4' && input != '5') {
        print_top_RL();
        std::cerr << "ERROR: Not a proper input.  Please try again" << std::endl;
        std::cout << "Rate your nutrition today from 1 to 5: ";
        input = getch();
    }
    after_num(input);
    return input;
}

//returns formatted date and time
std::string return_date_time() {

	//declaring the time
  	//https://www.geeksforgeeks.org/c-program-print-current-day-date-time/
    time_t tt;
    struct tm * ti;
    time (&tt);
    ti = localtime(&tt);
   	//std::cout << "Current Day, Date and Time is = " << asctime(ti);
    std::string date_time = asctime(ti);
    date_time += " ";

    //set different variables for day of week, month, date, time, year (to format how I want it)
    std::string day = "";	//day of week, this will be unused
    std::string month = "";	//month
    std::string date = "";	//date of month
    std::string time = "";	//time of day
    std::string year = "";	//year
    int last = 0;
    for(uint i = 0; i < date_time.size(); i++) {
    	
    	//set day of week variable (make sure day is blank)
    	if(date_time[i] == ' ' && day == "") {
    		for(uint j = last; j < i; j++) {
    			day += date_time[j];
    		}
    		last = i+1;
    	} 

    	//set month variable (check to make sure day is already set, and month is blank)
    	else if(date_time[i] == ' ' && day != "" && month == "") {
    		for(uint j = last; j < i; j++) {
    			month += date_time[j];
    		}
    		last = i+1;
    	}

    	//set date variable (check to make sure day and month are already set, and date is blank)
    	else if(date_time[i] == ' ' && day != "" && month != "" && date == "") {
    		for(uint j = last; j < i; j++) {
    			date += date_time[j];
    		}
    		last = i+1;
    	}

    	//set time variable (check to make sure day, month, and date are already set, and time is blank)
    	else if(date_time[i] == ' ' && day != "" && month != "" && date != "" && time == "") {
    		for(uint j = last; j < i; j++) {
    			time += date_time[j];
    		}
    		last = i+1;
    	}

    	//set year variable (check to make sure day, month, date, and time are already set, and year is blank)
    	else if(date_time[i] == ' ' && day != "" && month != "" && date != "" && time != "" && year == "") {
    		for(uint j = last; j < i; j++) {
    			year += date_time[j];
    		}
    		last = i+1;
    		year = year.substr(0,year.size()-1);
    	}

    }

    //add leading 0 to single digit dates
    if(date == "1") { date = "01"; }
    else if(date == "1") { date = "01"; }
    else if(date == "2") { date = "02"; }
    else if(date == "3") { date = "03"; }
    else if(date == "4") { date = "04"; }
    else if(date == "5") { date = "05"; }
    else if(date == "6") { date = "06"; }
    else if(date == "7") { date = "07"; }
    else if(date == "8") { date = "08"; }
    else if(date == "9") { date = "09"; }
    else if(date == "0") {
    	std::cerr << "ERROR: date cannot be 0" << std::endl;
    	exit(0);
    }

    //change month from word to num
    if(month == "Jan") { month = "01"; }
    else if(month == "Feb") { month = "02"; }
    else if(month == "Mar") { month = "03"; }
    else if(month == "Apr") { month = "04"; }
    else if(month == "May") { month = "05"; }
    else if(month == "Jun") { month = "06"; }
    else if(month == "Jul") { month = "07"; }
    else if(month == "Aug") { month = "08"; }
    else if(month == "Sep") { month = "09"; }
    else if(month == "Oct") { month = "10"; }
    else if(month == "Nov") { month = "11"; }
    else if(month == "Dec") { month = "12"; }
    else {
    	std::cerr << "ERROR: Month doesnt exist" << std::endl;
    	exit(0);
    }

    //change year to 2 digits
    year = year.substr(2,2);

    //get rid of seconds in time
    time = time.substr(0, time.size() - 3);
    
    //convert 24hr to 12hr
    std::string hour = time.substr(0,2);
    if(hour == "00" || hour == "01" || hour == "02" || hour == "03" || hour == "04" || hour == "05" || hour == "06" 
    	|| hour == "07" || hour == "08" || hour == "09" || hour == "10" || hour == "11") {
    	
    	if(hour == "00") { hour = "12"; }
    	time = hour + time.substr(2, time.size()-2) + "am";

    } else if(hour == "12") { time = hour + time.substr(2, time.size()-2) + "pm"; }
    else if(hour == "13") { hour = "01"; time = hour + time.substr(2, time.size()-2) + "pm"; }
    else if(hour == "14") { hour = "02"; time = hour + time.substr(2, time.size()-2) + "pm"; }
    else if(hour == "15") { hour = "03"; time = hour + time.substr(2, time.size()-2) + "pm"; }
    else if(hour == "16") { hour = "04"; time = hour + time.substr(2, time.size()-2) + "pm"; }
    else if(hour == "17") { hour = "05"; time = hour + time.substr(2, time.size()-2) + "pm"; }
    else if(hour == "18") { hour = "06"; time = hour + time.substr(2, time.size()-2) + "pm"; }
    else if(hour == "19") { hour = "07"; time = hour + time.substr(2, time.size()-2) + "pm"; }
    else if(hour == "20") { hour = "08"; time = hour + time.substr(2, time.size()-2) + "pm"; }
    else if(hour == "21") { hour = "09"; time = hour + time.substr(2, time.size()-2) + "pm"; }
    else if(hour == "22") { hour = "10"; time = hour + time.substr(2, time.size()-2) + "pm"; }
    else if(hour == "23") { hour = "11"; time = hour + time.substr(2, time.size()-2) + "pm"; }

    //testing date & time variables
    /*std::cout << "day: " << day << std::endl;
    std::cout << "month: " << month << std::endl;
    std::cout << "date: " << date << std::endl;
    std::cout << "time: " << time << std::endl;
    std::cout << "year: " << year << std::endl;*/

    //make formatted date and time string (ex: [08/14/21, 03:01pm])
    std::string formatted_string = "[" + month + "/" + date + "/" + year + ", " + time + "]";\

    //returns the date and time in the format I want, used in log.txt
    return formatted_string;

}

//rate log main code
void rate_log() {

    print_top_RL();
	
	//take number from enter_num()
	/*int*/ char num = enter_num();

	//read in description of why day was rated as specific number
	std::string str;;
  	std::cout << "\nPlease describe why you rated your day as a \"" << num << "\"? ";
  	getline (std::cin, str);

  	//save str to a file with the date and time of entry as a log
  	std::cout << "\nSaving..." << std::endl;
  	std::ofstream file;
  	file.open("log.txt", std::ios_base::app);
  	file << return_date_time() << " " << num << ": " << str << std::endl;
  	file.close();

    /*std::string exit;
    std::cout << "\nEnter \"Y\" to stay on the current screen, or anything else to return to the main menu: ";
    std::getline(std::cin, exit);
    if(exit == "y" || exit == "Y") { rate_log(); }*/

    std::cout << "\nEnter \"Y\" to stay on the current screen, or anything else to return to the main menu: ";
    char exit = getch();
    if(exit == 'y' || exit == 'Y') { rate_log(); }

}