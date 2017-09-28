// Name: David Wilkerson, Travis Connelly    Date: 5/9/13
// File: trash.h                             Section: 53 A
// Purpose: to create a trash class for simulation in main.cpp

#ifndef TRASH_H
#define TRASH_H

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_TRASH = 38;

class trash
{
  private:
    string m_name;
    int m_potent;
  
  public:
    
    //Description: constructor that initializes a trash type object
    //PRE: none
    //POST: randomly assigns to m_name and m_potent from trash.dat
    trash ();
    
    //Description: allows any function to acces the m_name string
    //PRE: none
    //POST: string is returned
    string getname () const {return m_name;}
    
    //Description: allows any function to access the m_potent value
    //PRE: none
    //POST: value is returned
    int getpotent () const {return m_potent;}
    
    //Description: reads name into m_name
    //PRE: none
    //POST: m_name is given the value of name
    void setname (const string name);
    
    //Description: reads pot into m_potent
    //PRE: none
    //POST: m_potent is given the value of pot
    void setpotent (const int pot);
};

#endif
