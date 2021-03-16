#include "Person.cpp"

class Doctor: public Person
{
private:
    int counter = 0;
    appointment *ap;
public:
    Doctor();
    ~Doctor();
    bool isReserved(int h, int m);
    void setCounter(int c);
    int getCounter();
    void setAppointment(int h, int m, int j);
    int getHours(int j);
    int getMinutes(int j);
    void addAppointment(appointment p);
};