// Name: David Wilkerson, Travis Connelly   Date: 5/4/13
// File: vacuum.h                           Section: 53 A
// Purpose: to create a vacuum class for use by the cleaner class in hw10.cpp

#ifndef VACUUM_H
#define VACUUM_H

#include <iostream>
#include <cstdlib>
#include "trash.h"
#include "family_member.h"

using namespace std;

const int BMAX = 35;

class vacuum
{
  private:
    trash m_bag [BMAX];
    bool m_short;
    int m_numtrash;
    bool m_explode;
  
  public:
    
    //Description: constructor that initializes a vacuum type object 
    //PRE: none
    //POST: values set to each member variable
    vacuum ();
    
    //Description: vacuums up a trash type object
    //PRE: none
    //POST: inserts trash type object into m_bag, chance to short
    void vac ();
    
    //Description: vacuums up a family_member type object
    //PRE: family_member type object must be initialized correctly
    //POST: inserts family_member type object into m_bag, chance to short
    void vac (family_member & m);
    
    //Description: empties the vacuum bag
    //PRE: none
    //POST: m_numtrash = 0 and contents of bag output to screen
    void empty ();
    
    //Description: outputs what is left in bag to screen
    //PRE: none
    //POST: outputs message to screen
    void printBag ();
    
    //Description: allows any function to access the m_short value
    //PRE: none
    //POST: value is returned
    bool getshort() const{return m_short;}
    
    //Description: checks whether the amount of trash in bag exceeds the
    //             maximum amount
    //PRE: none
    //POST: m_explode is set to true if amount trash is too big
    void isExplode();
    
    //Description: allows any function to access the m_explode value
    //PRE: none
    //POST: value is returned
    bool getExplode() const{return m_explode;}
    
    //Description: allows any function to access the m_bag[] object
    //PRE: none
    //POST: object is returned
    trash getTrash() const{return m_bag[m_numtrash-1];}
};

#endif
