struct appointment
{
    int hours, minutes;
};

class Person
{
private:
    string name;
    int ID, age;
public:
    Person();
    Person(const Person& s);
    Person(string n, int id, int a);
    void setName(string n);
    string getName();
    void setID(int id);
    int getID();
    void setAge(int a);
    int getAge();
    void print();
};