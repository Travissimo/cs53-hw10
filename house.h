// Programmer: David Wilkerson, Travis Connelly      Date: 5/9/13
// File: house.h                                     Section: 53 A
// Description: creates an object of class house for use in hw9main.cpp

#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <cstdlib>
#include "cleaner.h"
#include "family_member.h"

using namespace std;

const short FLOOR_MAX_SIZE = 25;

class house
{
  private:
    char m_floor [FLOOR_MAX_SIZE] [FLOOR_MAX_SIZE];
    int m_floorSize;
    int m_initialTrash;
    
    //Description: randomly places t's into the floor array.
    //PRE: m_floorSize must be greater than zero and m_initialTrash must 
    //     fit into the array without overlapping.
    //POST: t's and a C are randomly placed into the m_floor array.
    void scatterTrash ();
    
  public:
    
    //Description: the constructor that defines how a house type variable is
    //             initialized.
    //PRE: cleaner and family_member objects must be initialized correctly
    //POST: randomly places a family_member array and a cleaner position into 
    //      the m_floor array. Also places initial trash and trash can.
    house (cleaner & clnr, family_member famMemb []);
    
    //Description: the overloaded insertion operator that defines how a house 
    //             is output into the ostream
    //PRE: floorSize can't equal zero
    //POST: the house class object is output to the ostream in a nice format       
    friend ostream & operator << (ostream & out, const house & hse);
    
    //Description: sets m_floor [x][y] to stuff
    //PRE: x and y must be within the limit (0,m_floorSize)
    //POST: m_floor [x][y] is set to stuff
    void setFloor (const char stuff, const int x, const int y);
    
    //Description: allows any function to access the m_floorSize value.
    //PRE: none
    //POST: the value of m_floorSize is returned.
    int getFloorSize () {return m_floorSize;}
    
    //Description: allows any function to access the m_floor array
    //PRE: none
    //POST: a 2-D array is returned.
    char getFloor (const int x, const int y) {return m_floor [x][y];}
    
    //Description: allows any function to acces the m_initialTrash value.
    //PRE: none
    //POST: the value of m_initialTrash is returned.
    int getInitialTrash () {return m_initialTrash;}
    
    //Description: Keeps track of how much trash is in the m_floor array
    //PRE: none
    //POST: returns value
    int counttrash ();
};

#endif
     
