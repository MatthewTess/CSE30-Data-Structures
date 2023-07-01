#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Course {
    string name;
    string days;
    Time startTime;
    Time endTime;
    int credits;
    double avgGrade;
    bool majorRequirement;
};

int main() {
    ifstream file;

    file.open("in.txt");

    string content;
    int course_count;
    getline(file, content);
    course_count = stoi(content); // gets how many courses
    Course courses[course_count];

    for (int i = 0; i < course_count; i++) { // loop through amount of courses
        for (int j = 0; j < 7; j++) { // 7 things to get in each course
            if (j == 0) { // course name
                getline(file, content);
                courses[i].name = content;
            }
            else if (j == 1) { // course credits
                string temp;
                getline(file, content);
                temp = content;
                courses[i].credits = stoi(temp);
            }
            else if (j == 2) { // major requirement
                int temp;
                bool bool_temp;
                getline(file, content);
                temp = stoi(content);
                if (temp == 1) {
                    bool_temp = true;
                }
                else if (temp == 0) {
                    bool_temp = false;
                }
                courses[i].majorRequirement = bool_temp;
            }
            else if (j == 3) { // average grade
                string temp;
                getline(file, content);
                temp = content;
                courses[i].avgGrade = stod(temp);
            }
            else if (j == 4) { // lecture days
                getline(file, content);
                courses[i].days = content;
            }
            else if (j == 5) { // starting time
                string temp;
                getline(file, content);
                temp = content;
                courses[i].startTime.hours = stoi(temp.substr(0, 2));
                courses[i].startTime.minutes = stoi(temp.substr(3, 2));
                courses[i].startTime.seconds = stoi(temp.substr(6, 8));
            }
            else if (j == 6) { // ending time
                string temp;
                getline(file, content);
                temp = content;
                courses[i].endTime.hours = stoi(temp.substr(0, 2));
                courses[i].endTime.minutes = stoi(temp.substr(3, 2));
                courses[i].endTime.seconds = stoi(temp.substr(6, 8));
            }
        }
    }
    file.close();

    cout << "−−−−−−−−−−−−−−−−−−−" << endl << "SCHEDULE OF STUDENT" << endl << "−−−−−−−−−−−−−−−−−−−" << endl;
    for (int i = 0; i < course_count; i++) {
        cout << "COURSE " << (i + 1) << ": " << courses[i].name << endl;
        if (courses[i].majorRequirement) {
            cout << "Note: this course is a major requirement!" << endl;
        }
        else {
            cout << "Note: this course is not a major requirement..." << endl;
        }
        cout << "Number of Credits: " << courses[i].credits << endl;
        cout << "Days of Lectures: " << courses[i].days << endl;
        cout << "Lecture
