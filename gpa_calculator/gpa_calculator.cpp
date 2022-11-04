#include "gpa_functions.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using std::cout; using std::endl; using std::cerr;
using std::ifstream; using std::string;

#define RC_INVALID_ARGUMENTS 1
#define RC_IO_ERROR          2


int main(int argc, char *argv[]){
    if(argc != 2){
        cerr << "Incorrect command line arguments. Format: " << endl;
        cerr << "\"./<executable> <input_file_name>\"";
        return RC_INVALID_ARGUMENTS;
    }

    ifstream ifile(argv[1]);
    if(!ifile.is_open()){ 
        cerr << "File failed to open. " << endl;
        return RC_IO_ERROR;
    }

    string line;
    while(getline(ifile, line)){

    }

}