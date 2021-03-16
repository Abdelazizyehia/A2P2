#include "Doctor.h"

Doctor::Doctor()
{
    ap = new appointment[counter + 1];
}
Doctor::~Doctor()
{
    delete[] ap;
}
void Doctor::setCounter(int c)
{
    counter = c;
}

int Doctor::getCounter()
{
    return counter;
}
//Checking whether an appointment is available for the doctor
bool Doctor::isReserved(int h, int m)
{
    for (int i = 0; i<=counter; i++)
    {
        if( ap[i].hours == h && ap[i].minutes == m)
        return true;
    }
    return false;
}

void Doctor::setAppointment(int h, int m, int j)
{
    ap[j].hours  = h;
    ap[j].minutes = m;
}

int Doctor::getHours(int j)
{
    return ap[j].hours;
}

int Doctor::getMinutes(int j)
{
    return ap[j].minutes;
}
void Doctor::addAppointment(appointment p)
{
    ap[counter].hours = p.hours;
    ap[counter].minutes = p.minutes;
    counter++;
}
