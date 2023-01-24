#include "Student.h"

string name;


Student::Student(string name):
    name(name){
    }

string Student::getName()
{
    return this->name;
}


void Student::addSubject(string subject)
{
    this->subjects.push_back(subject);
}


string Student::toString()
{   
    //we create a stringstream to make it easier for me to format my string
    stringstream output;
   
    output << "Name of student: " << name << endl;
    /*
    output << "Subjects: " << endl;
    for(int i = 0; i < subjects.size(); i++){
       
		output << subjects[i] << "\n";
		
	}*/
    //return output.str();

    return "toSting";
}







