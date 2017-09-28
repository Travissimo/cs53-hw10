// Name: David Wilkerson, Travis Connelly    Date: 5/9/13
// File: trash.cpp                           Section: 53 A
// Purpose: to define functions in trash class for simulation in hw10.

#include "trash.h"

trash :: trash()
{
  ifstream in;
  int random;
  in.open ("trash.dat");
  
  random = (rand() % MAX_TRASH) + 1;
  for (int i = 0; i < random; i++)
  {
    in >> m_potent;
    in.ignore (1, ' ');
    getline (in, m_name);
  }
  in.close();
}

void trash :: setpotent (const int pot)
{
  m_potent = pot;
  return;
}

void trash :: setname (const string name)
{
  m_name = name;
  return;
}    
