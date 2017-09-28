// Name: David Wilkerson, Travis Connelly      Date: 5/9/13
// File: cleaner.h                             Section: 53 A
// Description: creates an object of class cleaner for use in main.cpp

#ifndef CLEANER_H
#define CLEANER_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "vacuum.h"
using namespace std;

const int CLNR_MAX_SIZE = 100;

class house;
class cleaner
{
  private:
    char m_name [CLNR_MAX_SIZE];
    int m_x;
    int m_y;
    float m_stressLevel;
    bool m_dead;
    vacuum m_vac;
  public:
    
    //Description: constructor that defines how a cleaner type object is 
    //             initialized.
    //PRE: name [] must contain less than CLNR_MAX_SIZE characters.
    //POST: a name, location, and stressLevel are input into the cleaner object
    cleaner (const char name [], const int x = 0, const int y = 0);
    
    //Description: reads in a value to m_x.
    //PRE: none
    //POST: value is read into m_x.
    void setx (const int x);
    
    //Description: reads in a value to m_y.
    //PRE: none
    //POST: value is read into m_y.
    void sety (const int y);
    
    //Description: allows any function to gain access to the m_x value.
    //PRE: none
    //POST: value is returned.
    int getx () const {return m_x;}
    
    //Description: allows any function to gain access to the m_y value.
    //PRE: none
    //POST: value is returned.
    int gety () const {return m_y;}
    
    //Description: allows any function to gain access to the m_dead bool.
    //PRE: none
    //POST: bool is returned.
    bool getdead () const {return m_dead;}
    
    //Description: allows any function to gain access to the m_stressLevel bool
    //PRE: none
    //POST: bool is returned.
    float getstress () const {return m_stressLevel;}
    
    //Description: allows any function to gain access to the first character of
    //             the m_name array.
    //PRE: none
    //POST: char is returned.
    char getFirstLetter () const {return m_name [0];}
    
    //Description: allows any function to gain access to the m_vac object
    //PRE: none
    //POST: m_vac object is returned.
    vacuum getVac () const {return m_vac;}
    
    //Description: defines how an object of type cleaner will be inserted into
    //             the output stream.
    //PRE: none
    //POST: ostream is returned.
    friend ostream & operator << (ostream & out, const cleaner & clnr);
    
    //Description: calculates the value of m_stressLevel.
    //PRE: hse must be initialized properly.
    //POST: value is input into m_stressLevel.
    void calculateStress (house & hse);
    
    //Description: moves the cleaner within the house.
    //PRE: h and m[] must be initialized properly.
    //POST: randomly picks a direction to move cleaner object and updates
    //      house.
    void step (house & h, family_member m[]);
    
    //Description: reads in a value to m_dead
    //PRE: none
    //POST: value read into m_dead
    void setdead(const bool dead);
};

#endif
