#include "Patient.h"

Patient::Patient()
{
    app.hours = -1;
    app.minutes = -1;
    doctorID = 0;
}

bool Patient::operator <(Patient& p)
{
    
    if ( (app.hours < p.app.hours) || (app.hours == p.app.hours && app.minutes < p.app.minutes) )
        return true;
    else
        return false;
}
bool Patient::operator >(Patient& p)
{
    if ( (app.hours > p.app.hours) || (app.hours == p.app.hours && app.minutes > p.app.minutes) )
        return true;
    else
        return false;
}

bool Patient::operator == (Patient& p)
{
    if ( app.hours == p.app.hours && app.minutes == p.app.minutes)
        return true;
    else
        return false;

}
void Patient::setHours(int h)
{
    app.hours = h;
}
void Patient::setMinutes(int m)
{
    app.minutes = m;
}
int Patient::getHours()
{
    return app.hours;
}
int Patient::getMinutes()
{
    return app.minutes;
}
void Patient::setDoctorID(int docId)
{
    doctorID = docId;
}
int Patient::getDoctorID()
{
    return doctorID;
}

void Patient::print()
{
    Person::print();
    cout <<"Doctor ID "<<doctorID<<endl;
    cout <<"Appointment "<<app.hours<<": "<<app.minutes<<endl;
}
void Patient::setAppointment(int h, int m)
{
    app.hours = h;
    app.minutes = m;
}
appointment Patient::getAppointment()
{
    return app;
}