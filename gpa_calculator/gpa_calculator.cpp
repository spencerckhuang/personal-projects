#include "gpa_functions.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using std::cout; using std::endl; using std::cerr;
using std::ifstream; using std::string; using std::vector;
using std::stringstream; using std::setprecision; using std::fixed;

#define RC_INVALID_ARGUMENTS 1
#define RC_IO_ERROR          2
#define RC_INVALID_FILE      3

int main(int argc, char *argv[]){
    if(argc != 2){
        cerr << "Incorrect command line arguments. Format: " << endl;
        cerr << "\"./<executable> <input_file_name>\"" << endl;
        return RC_INVALID_ARGUMENTS;
    }

    ifstream ifile(argv[1]);
    if(!ifile.is_open()){ 
        cerr << "File failed to open. " << endl;
        return RC_IO_ERROR;
    }

    string line;
    vector<Course> classList;

    while(getline(ifile, line)){
        stringstream lineStream(line);
        string className; 
        int credits; 
        string grade;
        lineStream >> className >> credits >> grade;
        if(lineStream.fail()){
            cerr << "Invalid file format." << endl;
            return RC_INVALID_FILE;
        }
        
        Course addedCourse = Course(className, credits, grade);
        classList.push_back(addedCourse);
    }

    double gpa = calculateGPA(classList);
    cout << "GPA: " << setprecision(2) << fixed << gpa << endl << "Deans list: " << (gpa >= 3.5 ? "Yes" : "No") << endl;

}