// Programmer: David Wilkerson, Travis Connelly     Date: 4/26/13
// File: family_member.h                            Section: 53 A
// Description: creates an object of class house for use in main.cpp

#ifndef FAMILY_MEMBER_H
#define FAMILY_MEMBER_H

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MEMB_MAX_LENGTH = 100; 
const int MAX_FAM = 4;

class house;
class family_member
{
  private:
    char m_name [MEMB_MAX_LENGTH];
    int m_x;
    int m_y;
    int m_sloppinessFactor;
    bool m_dead;
    bool m_vacuumed;
 
  public:
    
    //Description: constructor that defines how a family_member type object is
    //             initialized.
    //PRE: name [] must contain less than MEMB_MAX_LENGTH characters, 
    //     filename family_member.txt must exist, and x and y must be less 
    //     than FLOOR_MAX_SIZE
    //POST: a name, location, and sloppinessFactor are input into the cleaner 
    //      object.
    family_member (const int x = 0, const int y = 0);
    
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
    int getx () const  {return m_x;}
    
    //Description: allows any function to gain access to the m_y value.
    //PRE: none
    //POST: value is returned.
    int gety () const  {return m_y;}
    
    //Description: allows any function to gain access to the first character of
    //             the m_name array.
    //PRE: none
    //POST: char is returned.
    char getFirstLetter () const {return m_name [0];}
    
    //Description: allows any function to gain access to the m_sloppinessFactor
    //             value.
    //PRE: none
    //POST: value is returned.
    int getSloppy () const {return m_sloppinessFactor;}
    
    //Description: allows any function to gain access to the m_dead bool.
    //PRE: none
    //POST: bool is returned.
    bool getdead () const { return m_dead;}
    
    //Description: allows any function to gain access to the m_vacuumed bool.
    //PRE: none
    //POST: bool is returned.
    bool getvacuumed () const { return m_vacuumed;}
    
    //Description: reads in a bool to m_dead 
    //PRE: none
    //POST: bool is read into m_dead
    void setdead (bool dead);
    
    //Description: reads in a bool to m_vacuumed
    //PRE: none
    //POST: bool is read into m_vacuumed
    void setvacuumed (bool vac);
    
    //Description: reads m_name into the string that is called
    //PRE: none
    //POST: m_name is read into calling string
    void giveName (string & name);
    
    //Description: has a random chance to throw trash in a spot adjacent to 
    //             the family_member position
    //PRE: house object must be initialized correctly
    //POST: chance that t is input into h.m_floor
    void maketrash (house & h);
       
    //Description: defines how an object of type cleaner will be inserted into
    //             the output stream.
    //PRE: none
    //POST: ostream is returned.
    friend ostream & operator << (ostream & os, const family_member & famMemb);
    
    //Description: moves family members. 
    //PRE: house object must be initialized correctly
    //Post: updates the location of the family members within the house. 
    void step (house & h);
};

#endif
