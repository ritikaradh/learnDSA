#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Student{
    public:
    string name;
    int marks;

    //constructor
    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    //operator overloading

    //min-heap
    // bool operator < (const Student &obj) const{
    //     return this->marks > obj.marks;
    // }
    
    //max-heap
    bool operator < (const Student &obj) const{
        return this->marks < obj.marks;
    }
};

int main(){
    priority_queue<Student> pq; //max heap

    pq.push(Student("ritika", 100));
    pq.push(Student("anisha", 72));
    pq.push(Student("tisha", 105));

    while(!pq.empty()){
        cout<<pq.top().name<<", "<<pq.top().marks<<endl;
        pq.pop();
    }

    return 0;
}