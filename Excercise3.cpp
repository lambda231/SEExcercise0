#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class Person{
protected:
    string name = "", address = "";
    int id = -1;
public:
    Person(string n, string a, int i){
        name = n;
        address = a;
        id = i;
    }
    string getName(){
        return name;
    }
    string getAddress(){
        return address;
    }
    void setAddress(string a){
        address = a;
    }
    int getId(){
        return id;
    }
    void setId(int i){
        id = i;
    }
    virtual string toString(){
        return "Person[name=" + name + ", address=" + address + "]";
    }
};

class Student: public Person{
private:
    string program = "";
    int year = 2023;
    double fee = 0.0;
public:
    Student(string n, string a, int i, string p, int y, double f) : Person(n, a, i){
        program = p;
        year = y;
        fee = f;
    }
    string getProgram(){
        return program;
    }
    void setProgram(string p){
        program = p;
    }
    int getYear(){
        return year;
    }
    void setYear(int y){
        year = y;
    }
    double getFee(){
        return fee;
    }
    void setFee(double f){
        fee = f;
    }
    string toString(){
        return "Student[" + Person::toString() + ", program=" + program +", year=" + to_string(year) + ", fee=" + to_string(fee) +"]";
    }
    bool operator == (const Student &another){
        return name == another.name && address == another.address && program == another.program && year == another.year && fee == another.fee;
    }
};

class Staff: public Person{
private:
    string school = "";
    double pay = 0.0;
public:
    Staff(string n, string a, int i, string s, double p) : Person(n,a,i){
        school = s;
        pay = p;
    }
    string getSchool(){
        return school;
    }
    void setSchool(string s){
        school = s;
    }
    double getPay(){
        return pay;
    }
    void setPay(double p){
        pay = p;
    }
    string toString(){
        return "Staff[" + Person::toString() + ", school=" + school + ", pay=" + to_string(pay) +"]";
    }
    bool operator == (const Staff &another){
        return name == another.name && address == another.address && school == another.school && pay == another.pay;
    }
};

class Course{
private:
    string courseID = "", courseName = "", courseDescription = "";
    int noCredit = 0;
    vector<Student> studentList;
    vector<Staff> staffList;
public:
    void addStudent(Student s){
        studentList.push_back(s);
    }
    void removeStudent(Student s){
        auto it = find(studentList.begin(), studentList.end(), s);
        if (it != studentList.end()){
            studentList.erase(it);
        }
    }
    void addStaff(Staff s){
        staffList.push_back(s);
    }
    void removeStaff(Staff s){
        auto it = find(staffList.begin(), staffList.end(), s);
        if (it != staffList.end()){
            staffList.erase(it);
        }
    }
    string toString(){
        string o = "";
        for (unsigned int i = 0; i < studentList.size(); i++){
            o += studentList[i].toString() + "\n";
        }
        for (unsigned int i = 0; i < staffList.size(); i++){
            o += staffList[i].toString() + "\n";
        }
        return o;
    }
};

class SchoolBusinessTest{
public:
    void driver(){
        Student* arr[5];
        for (int i = 0; i < 5; i++){
            arr[i] = new Student("a", "b", 50, "c", 2023, 0);
            cout << arr[i]->toString() << "\n";
        }
        Staff a("a", "b", 4 , "c", 1.0);
        cout << a.toString() << '\n';
        a.setAddress("New Address");
        cout << a.toString() << '\n';
        
        Course course;
        course.addStudent(*arr[0]);
        cout << "Add 1 student:\n" + course.toString();
        course.addStudent(*arr[4]);
        cout << "Add 1 student:\n" + course.toString();
        course.removeStudent(*arr[0]);
        cout << "Remove first student:\n" + course.toString();
        course.addStaff(a);
        cout << "Add 1 Staff:\n" + course.toString();
        course.removeStaff(a);
        cout << "Remove first staff:\n" + course.toString();
    }
};

int main()
{
    SchoolBusinessTest test;
    test.driver();
    return 0;
}
