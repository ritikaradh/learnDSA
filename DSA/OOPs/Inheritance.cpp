#include <iostream>
using namespace std;

class Person {
    protected: 
        string name;
        int age;

    public:
        Person(string name, int age) {
            this -> name = name;
            this -> age = age;
            cout<<"Person created!"<<endl;
        }
};

class Student: public Person {
    string studentId;

    public:
        //calling parent class constructor inside child class
        Student(string name, int age, string studentId) : Person(name, age) {
            this -> studentId = studentId;
            cout<<"student created!"<<endl;
        }

        //method to display student information
        void displayStudentInfo() {
            cout<<"\nGetting Information..\n";
            cout<<"name:  "<<name<<endl;
            cout<<"age: "<<age<<endl;
            cout<<"studentId: "<<studentId<<endl;
        }
};

int main(){
    Student student("Ritika", 22, "18730621003ABC");
    student.displayStudentInfo();
    return 0;
}