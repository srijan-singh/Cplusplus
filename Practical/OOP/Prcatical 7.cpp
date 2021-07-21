#include <iostream>

using namespace std;

class Date{

	int day;
	int month;
	int year;
	
	public:
	Date(int d, int m, int y){
		day = d;
		month = m;
		year = y;
	}

	void showDate(){
		cout<<day<<"-"<<month<<"-"<<year;
	}

	~Date(){
		cout<<endl<<"Date Destructor was called";
	}
};

class College{

	protected:
	string college_name;

	public:
	College(){
		college_name = "PIET";
	}

	College(string name){
		college_name = name;
	}
};

class Student:protected College{
	
	string college = college_name;
	string name;
	
	public:

	bool present;

	Student(string student_name, bool present_today){
		
		name = student_name;
		present = present_today;
	}

	void studentData(){
		cout<<name<<" of "<<college;
	}
};

class Attendance{
	
	public:
	Attendance(Student &s, Date &d, string event){
		
		s.studentData();

		if(s.present == true)
		{
			cout<<" was present in "<<event<<" on ";			
		}

		else
		{
			cout<<" was absent in "<<event<<" on ";			
		}

		d.showDate();
	}
};

int main() {
	
	Date d(17,7,2021);

	Student s("Srijan", true);

	Attendance(s, d, "C++ lab");

	return 0;
}