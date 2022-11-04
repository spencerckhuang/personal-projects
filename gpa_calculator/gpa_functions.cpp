#include "gpa_functions.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector;



Course::Course(string cn, int c, string g): course_name(cn){
    setCredits(c);
    setGrade(g);
}

void Course::setCredits(int c){
    if(c < 1){
        cerr << "Invalid credits entered in setCredits for course " << course_name << ". Changing to 1 by default." << endl;
        credits = 1;
    } else {
        credits = c;
    }
    return;
}

void Course::setGrade(string g){
    if(gradeValues.find(g) != gradeValues.end()){
        grade = g;
    } else {
        cerr << "Invalid grade entered in setGrade for " << course_name << ". Changing to C by default." << endl;
        grade = "C";
    }
    return;
}

bool deansList(double g, int c){
    return(g >= 3.5 && c >= 14);
}

double calculateGPA(vector<Course> courses){
    return 0.0;
}