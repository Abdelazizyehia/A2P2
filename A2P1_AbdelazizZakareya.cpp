#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Queue.cpp"
#include "Doctor.cpp"
#include "Patient.cpp"
void readFromFile();
void readFromUser();
string getDoctorName(Doctor *d, int docSize, int id);
void reserve(Patient* p, Doctor* d, int doctorSize);


int main()
{
    char reply;
    cout <<"Type (Y) if you want to enter the information or (N) to read it from a file "<<endl;
    cin >>reply;

    if(toupper(reply) == 'N')
        readFromFile();
    else if(toupper(reply) == 'Y')
        readFromUser();
    else
    {
        cout <<"Please enter a valid response "<<endl;
        return 1;
    }

    return 0;
}
//A function to reserve an appointment with the doctor
void reserve(Patient* p, Doctor* d, int doctorSize)
{
    for (int i = 0; i<24; i++)
    {
    for (int j = 0; j<doctorSize; j++)
     {
            if ( (d+j)->isReserved((p)->getHours(),(p)->getMinutes()) == false && (d+j)->getCounter() == i)
            {
                (d+j)->addAppointment(p->getAppointment());
                p->setDoctorID((d+j)->getID());
                return;
            }
        }
    }
}

//A function that get the name of the doctor based on the doctor's id
string getDoctorName(Doctor *d, int docSize, int id) 
{
    for (int i = 0; i<docSize; i++)
    {
        if( (d+i)->getID() == id)
            return (d+i)->getName();
    }
        return "No doctor with such an ID ";
}
// A function that reads from a file all the information of the patient and the doctor
void readFromFile()
{
    Doctor* d = new Doctor[3];
    ifstream myfile("Doctors.txt");
    string line;
    int num, num1;

    if (myfile.is_open())
    {
        for (int i = 0; i<3; i++)
        {
            myfile >> line;
            (d+i)->setName(line);
            myfile >> num;
            (d+i)->setAge(num);
            myfile >> num;
            (d+i)->setID(num);
            
            for (int j = 0; j<3; j++)
            {
                myfile >> num;
                myfile >> num1;
                appointment b;
                b.hours = num;
                b.minutes = num1;
                (d+i)->addAppointment(b);
            }  
        }
    }
    else
        cout <<"Error1: Unable to open the file "<<endl;


    Patient* p = new Patient[4];
    ifstream myfile2("Patients.txt");
    string line2;
    int num2;
    if (myfile2.is_open())
    {
        for (int i = 0; i<4; i++)
        {
            myfile2 >> line;
            (p+i)->setName(line);
            myfile2 >> num;
            (p+i)->setAge(num);
            myfile2 >> num;
            (p+i)->setID(num);
            myfile2 >> num;
            (p+i)->setHours(num);
            myfile2 >> num;
            (p+i)->setMinutes(num);
            reserve((p+i), d, 3);
        }
    }
    else
        cout <<"Error2: Unable to open the file "<<endl;
    
    cout <<"Before: \n\n\n";
    for (int i = 0; i<4; i++)
    {
        cout <<(p+i)->getName()<<" has an appointment at " <<(p+i)->getHours()<<": "<<(p+i)->getMinutes()<<
        " with "<<getDoctorName(d, 3, (p+i)->getDoctorID())<<endl;
    }

    //Sorting the patient array according to the appointments
    for (int i = 0; i<4;i++)
    {
        for (int j = 0; j < 4-1; j++)
        {
            if ( *(p+j) > *(p+j+1))
            {
                Patient temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = temp;
            }
        }
    }

    cout <<"After: \n\n\n";
    for (int i = 0; i<4; i++)
    {
        cout <<(p+i)->getName()<<" has an appointment at " <<(p+i)->getHours()<<": "<<(p+i)->getMinutes()<<
        " with "<<getDoctorName(d, 3, (p+i)->getDoctorID())<<endl;
    }
    queue <Patient> q;
    cout <<"After Queue: \n\n\n";
    for (int i = 0; i<4; i++)
    {
        q.enque(*(p+i));
    }

    for (int i = 0; i<4; i++)
    {
       
        cout << q.getFront().getName()<<" has an appointment at " <<q.getFront().getHours()<<": "<<q.getFront().getMinutes()<<
        " with "<<getDoctorName(d, 3, q.getFront().getDoctorID())<<endl;
        q.deque();
    }

}

//A function that reads all the information from the user
void readFromUser()
{
    int docSize;
    cout <<"Enter the number of available doctors "<<endl;
    cin >> docSize;
    Doctor* d = new Doctor[docSize];
    string tempName;
    int tempID, tempAge, numAppointments, tempHours, tempMinutes;
    
    for (int i = 0; i<docSize; i++)
    {
        cout <<"Enter Doctor "<<i+1<<" name: "<<endl;
        cin >> tempName;
        (d+i)->setName(tempName);
        cout <<"Enter Doctor "<<i+1<<" ID: "<<endl;
        cin >> tempID;
        (d+i)->setID(tempID);
        cout <<"Enter Doctor "<<i+1<<" Age: "<<endl;
        cin >> tempAge;
        (d+i)->setAge(tempAge);
    }

    int patientSize;
    cout <<"Enter the number of patients "<<endl;
    cin >> patientSize;
    Patient* p = new Patient[patientSize];
    
    for (int i = 0; i<patientSize; i++)
    {
        cout <<"Enter patient "<<i+1<<" name: "<<endl;
        cin >> tempName;
        (p+i)->setName(tempName);
        cout <<"Enter patient "<<i+1<<" ID: "<<endl;
        cin >> tempID;
        (p+i)->setID(tempID);
        cout <<"Enter patient "<<i+1<<" Age: "<<endl;
        cin >> tempAge;
        (p+i)->setAge(tempAge);

        cout <<"Enter the apppointment hour and minute that you would like to book "<<endl;
        cin >> tempHours >> tempMinutes;
        (p+i)->setAppointment(tempHours, tempMinutes);
        reserve((p+i), d, docSize);
    }

    cout <<"Before: \n\n\n";

    for (int i = 0; i<patientSize; i++)
    {
        cout <<(p+i)->getName()<<" has an appointment at " <<(p+i)->getHours()<<": "<<(p+i)->getMinutes()<<
        " with "<<getDoctorName(d, docSize, (p+i)->getDoctorID())<<endl;
    }

    //Sorting the patient array according to the appointments
    for (int i = 0; i<patientSize;i++)
    {
        for (int j = 0; j < patientSize-1; j++)
        {
            if ( *(p+j) > *(p+j+1))
            {
                Patient temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = temp;
            }
        }
    }

    queue <Patient> q;
    cout <<"After Queue: \n\n\n";
    for (int i = 0; i<patientSize; i++)
    {
        q.enque(*(p+i));
    }

    for (int i = 0; i<patientSize; i++)
    {
       
        cout << q.getFront().getName()<<" has an appointment at " <<q.getFront().getHours()<<": "<<q.getFront().getMinutes()<<
        " with "<<getDoctorName(d, docSize, q.getFront().getDoctorID())<<endl;
        q.deque();
    }
}

