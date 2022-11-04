#ifndef GPA_FUNCTIONS_H
#define GPA_FUNCTIONS_H

#include <string>
#include <map>

class Course{
    public:
        /* non-default constructor 
            -> no default constructor should exist  */
        Course(std::string cn, int c, std::string g);

        /* all getters defined via in-lining */
        std::string getCourseName(){ return course_name; }
        int getCredits(){ return credits; }
        std::string getGrade(){ return grade; }

        /* only one setter defined via in-lining */
        void setCourseName(std::string c){ course_name = c; }
        void setCredits(int i);
        void setGrade(std::string g);

        bool deansList();

    private:
        std::string course_name;
        int credits;
        std::string grade;
        double GPA;
}

std::map<std::string, double> gradeValues = {
    {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7},
    {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
    {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7},
    {"D+", 1.3}, {"D", 1.0}, {"F", 0.0},
}

#endif