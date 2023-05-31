/*
 * student.cpp
 *
 *  Created on: Feb 6, 2022
 *      Author: sushant
 */

#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Student{
public:
	Student(string first, string last, float gpa, int id)
		:first_(first), last_(last), gpa_(gpa), id_(id) {}	

		string full_name() const {
			return first_ + " " + last_;
		}

		int id() const {
			return id_;
		}

		float gpa() const {
			return gpa_;
		}

		void print_info() const {
			cout << full_name() << ", GPA: " << fixed << setprecision(2) << gpa_ << ", ID: " << id_ << endl;
		}


private:
	string first_, last_;
	float gpa_;
	int id_;
};

/**
 * Takes a vector of Student objects, and returns a new vector
 * with all Students whose GPA is > 3.5.
 */
vector<Student> find_excellent_students(const vector<Student> &students) {
	vector<Student> excellent_students;
	// Iterates through the students vector, appending each student whose gpa is
	// more than 3.5 to the excellent_students vector.
	for (const auto& student : students){
			if (student.gpa() > 3.5){
				excellent_students.push_back(student);
			}
	}
	return excellent_students;
}
/**
 * Takes a vector of Student objects and prints them to the screen.
 */
void print_students(const vector<Student> &students) {

	// Iterates through the students vector, calling print_info() for each student.
	for(const auto& student : students){
		student.print_info();
	}
}


/**
 * Allows the user to enter information for multiple students, then * find those students whose GPA is below 1.0 and prints them to the * screen.
 */
int main() {
	string first_name, last_name;
	float gpa;
	int id;
	char repeat;
	vector<Student> students;
	do {
		cout << "Enter student's first name: ";
		cin >> first_name;
		cout << "Enter student's last name: ";
		cin >> last_name;
		gpa = -1;
		while (gpa < 0 || gpa > 4) {
			cout << "Enter student's GPA (0.0-4.0): ";
			cin >> gpa;
		}
		cout << "Enter student's ID: ";
		cin >> id;
		students.push_back(Student(first_name, last_name, gpa, id));
		cout << "Add another student to database (Y/N)? ";
		cin >> repeat;
	} while (repeat == 'Y' || repeat == 'y');
	cout << endl << "All students:" << endl;
	print_students(students);
	cout << endl << "excellent students:";

	// TODO
	// Print a space and the word 'None' on the same line if no students are excellent.
	// Otherwise, print each excellent student on a separate line.
	vector<Student> excellent_students = find_excellent_students(students);
	if(excellent_students.size() == 0){
		cout << " None" << endl;
	} else {
		cout << endl;
		print_students(excellent_students);
	}
	return 0;
}

