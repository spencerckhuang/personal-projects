#include "gpa_functions.h"
#include <iostream>

using std::cout; using std::endl; using std::cerr;

std::map<std::string, double> gradeValues = {
    {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7},
    {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
    {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7},
    {"D+", 1.3}, {"D", 1.0}, {"F", 0.0},
}

Course::Course(string cn, int c, string g): course_name(cn){
    /* make sure credit # is valid */
    if(c < 1){
        cerr << "Invalid credits entered for course " << course_name << ". Changing to 1 by default." << endl;
        credits = 1;
    } else {
        credits = c;
    }

    /* make sure grade is valid */
    if(gradeValues.find(g) != gradeValues.end()){
        grade = g;
    } else {
        cerr << "Invalid grade entered for " << course_name << ". Changing to C by default." << endl;
        grade = "C";
    }

    GPA = 0.0;
}

void Course::setCredits(int i){
    return;
}

void Course::setGrade(string g){
    return;
}