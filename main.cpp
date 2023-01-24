#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;
vector<Student*> vectorsOfStudents;



int main(){
 
    int posCurrentStudent = 0; //Position of the current student in the vectorsOfStudents

    fstream newfile;
    newfile.open("A3Data.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        
        string line;

        while(getline(newfile, line)){ //read data from file object and put it into string.
            
            if(line.empty()!=true){ //if that line is just empty, we don't process that line, it's the size of students
                if(line.size()==1){
                    cout << "size: " << line << endl;
                }

                else {

                    // if that line has CSCI something in it, means it is a subject
                    std::size_t found = line.find("CSCI");
                    if(found!=std::string::npos){ 
                        cout << "subject:" << line << line.find("CSCI") << endl;

                        //cout <<"line 36 "<< endl;
                        //cout <<"posCurrentStudent-0"<< to_string(posCurrentStudent-0)<<endl;
                        vectorsOfStudents.at(posCurrentStudent-1)->addSubject(line);
                        //cout <<"line 48 "<< endl;
                    }
                    
                    else{

                        //find the position where the comma is in the string
                        int commaPos = line.find(',');

                        //before the comma is the name, so extract that part of the string
                        string name = line.substr(0, commaPos);
                        cout << "name:" << name << endl;

                        //cout <<"line 47 "<< endl;

                        //create new Student object
                        Student *newStudent = new Student(name);
                        vectorsOfStudents.push_back(newStudent);
                        posCurrentStudent ++;

                        //cout <<"line 54 "<< endl;

                        //extract the string which is having the number of subjects after the comma onwards
                        string afterCommaString = line.substr(commaPos + 1); //rest of the data without name

                        //cout <<"line 59 "<< endl;

                        //remove spaces from string which is after the commma. That string is having the number of subjects.
                        string numSubjects;
                        for(char ch : afterCommaString)
                        {
                            if(ch != ' ')
                            {
                                numSubjects.push_back(ch);//we can treat a string like a vector in STL
                            }
                        }

                        //cout <<"line 71 "<< endl;
                        cout << "numSubjects:" << numSubjects << endl;
                    }
                }

            }

        }
        newfile.close(); //close the file object.
    }

   
    //printout my vectorsOfStudents

    cout <<"/printout my vectorsOfStudents"<< endl;
    vectorsOfStudents.at(0)->toString();
    vectorsOfStudents.at(1)->toString();
    vectorsOfStudents.at(2)->toString();
    vectorsOfStudents.at(3)->toString();
    vectorsOfStudents.at(4)->toString();

    for(int i = 0; i < vectorsOfStudents.size(); i++){
        cout <<"i: "<< i<< endl;
	    vectorsOfStudents[i]->toString();
		
	}


    //de allocate my vector of pointer
    for (Student* s : vectorsOfStudents){
        delete s;
    } 
    vectorsOfStudents.clear();
}

