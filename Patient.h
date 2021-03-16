#include "Person.cpp"

class Patient: public Person
{
private:
    appointment app;
    int doctorID;
public:
    Patient();
    bool operator <(Patient& p);
    bool operator >(Patient& p);
    bool operator == (Patient& p);
    void setHours(int h);
    void setMinutes(int m);
    int getHours();
    int getMinutes();
    void setDoctorID(int docId);
    int getDoctorID();
    void setAppointment(int h, int m);
    appointment getAppointment();
    void print();
};