#ifndef P
#define P

#include "Person.h"
Person::Person()
{
    name = "*****";
    ID = 0;
    age = 0;
}
Person::Person(const Person& s)
{
    name = s.name;
    ID = s.ID;
    age = s.age;   
}
Person::Person(string n, int id, int a)
{
    name = n;
    ID = id;
    age = a;
}
void Person::setName(string n)
{
    name = n;
}
string Person::getName()
{
    return name;
}
void Person::setID(int id)
{
    ID = id;
}
int Person::getID()
{
    return ID;
}
void Person::setAge(int a)
{
    age = a;
}
int Person::getAge()
{
    return age;
}
void Person::print()
{
    cout <<"Name: "<<name<<endl;
    cout <<"ID: "<<ID<<endl;
    cout <<"Age: "<<age<<endl;
}
#endif