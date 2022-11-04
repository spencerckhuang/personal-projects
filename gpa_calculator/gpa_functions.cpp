#include "gpa_functions.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::map;



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
    int creditSum = 0;
    double gpa = 0.0;

    map<string, double> gradeValues = {
            {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7},
            {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
            {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7},
            {"D+", 1.3}, {"D", 1.0}, {"F", 0.0},
    };

    for(vector<Course>::iterator it = courses.begin(); it != courses.end(); ++it){
        creditSum += (*it).getCredits();
        map<string, double>::const_iterator gradeIt = gradeValues.find((*it).getGrade());
        /* shouldn't have to handle error since grade should always be valid */
        gpa += gradeIt->second * (*it).getCredits();
    }

    return gpa/creditSum;
}

void addCourse(string cn, int c, string g, vector<Course>& v){
    v.push_back(Course(cn, c, g));
}