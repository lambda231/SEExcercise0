#include <iostream>
#include <string.h>

using namespace std;

class Person{
private:
    string name = "", address = "";
public:
    Person(string n, string a){
        name = n;
        address = a;
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
    Student(string n, string a, string p, int y, double f) : Person(n, a){
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
};

class Staff: public Person{
private:
    string school = "";
    double pay = 0.0;
public:
    Staff(string n, string a, string s, double p) : Person(n,a){
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
};

class SchoolBusinessTest{
public:
    void driver(){
        Student* arr[5];
        for (int i = 0; i < 5; i++){
            arr[i] = new Student("a", "b", "c", 2023, 0);
            cout << arr[i]->toString() << "\n";
            delete arr[i];
        }
        Staff a("a", "b", "c", 1.0);
        cout << a.toString() << '\n';
        a.setAddress("New Address");
        cout << a.toString() << '\n';
    }
};

int main()
{
    SchoolBusinessTest test;
    test.driver();
    return 0;
}
