// Programmer: David Wilkerson, Travis Connelly       Date: 5/9/13
// File: house.cpp                                    Section: 53 A
// Purpose: This file defines the functions contained in the house.h function.

#include "house.h"

void house :: scatterTrash()
{
  int x = ((rand() % (m_floorSize - 2)) + 1);
  int y = ((rand() % (m_floorSize - 2)) + 1);
  
  while (m_floor [x][y] != ' ')
  {
    x = ((rand() % (m_floorSize - 2)) + 1);
    y = ((rand() % (m_floorSize - 2)) + 1);
  }
  m_floor [x][y] = 'C';
  
  for (int i = 0; i < m_initialTrash; i++)
  {
    while (m_floor [x][y] != ' ')
    {
      x = ((rand() % (m_floorSize - 2)) + 1);
      y = ((rand() % (m_floorSize - 2)) + 1);
    }
    m_floor [x][y] = 't';
  }
  return;
}

ostream & operator << (ostream & out, const house & hse)
{ 
  //////////////////////////////////////////////////////
  out << "  ";                                        //
  for (int i = 0; i < hse.m_floorSize; i++)           //
    out << " " << (i / 10); //outputs the one's digit //
  out << endl;                                        ////this section labels
  out << "  ";                                        ////the top of the grid
  for (int i = 0; i < hse.m_floorSize; i++)           //
    out << " " << (i % 10); //outputs the ten's digit //
  out << endl;                                        //
  //////////////////////////////////////////////////////
  
  for (int i = 0; i < hse.m_floorSize; i++)
  { 
    ////////////////
    if (i < 10)   //
      out << 0;   ////this section labels the left of the grid
    out << i;     //
    ////////////////
    for (int j = 0; j < hse.m_floorSize; j++)
    {
      out << "|";
      out << hse.m_floor [j][i];
    } 
    out << "|" << endl;
  }
  return out;
}
                                    
house :: house (cleaner & clnr, family_member famMemb[])
{
  const int F_MIN = 6; //Minimum floorSize that includes windows in m_floor
  int tMax;
  
  cout << "Please enter the size of the floor [" 
       << F_MIN << "-" << FLOOR_MAX_SIZE << "]: ";
  cin >> m_floorSize;
  cout << endl;
  
  while (m_floorSize < F_MIN || m_floorSize > FLOOR_MAX_SIZE)
  {
    cout << "ERROR! Please enter a size within the range [" << F_MIN << "-"
         << FLOOR_MAX_SIZE << "]: ";
    cin >> m_floorSize;
    cout << endl;
  }
  
  tMax = (m_floorSize - 2) * (m_floorSize - 2) - MAX_FAM - 2;
  cout << "Please enter the amount of trash in the house initially [0-"
       << tMax << "]: ";
  cin >> m_initialTrash;
  cout << endl; 
  
  while (m_initialTrash < 0 || m_initialTrash > tMax)
  {
    cout << "ERROR! Please enter an amount within the range [0-";
    cout << tMax << "]: ";
    cin >> m_initialTrash;
    cout << endl;
  }
    
  for (int i = 0; i < m_floorSize; i++) //this loop clears the floor
  {
    for (int j = 0; j < m_floorSize; j++)
      m_floor [i][j] = ' ';
  }
  
  for (int i = 1; i < m_floorSize - 1; i++)
  {
    if ( i % 4 == 0)
    {
      m_floor [i][0] = 'W';
      m_floor [i][m_floorSize - 1] = 'W';
      m_floor [0][i] = 'W';
      m_floor [m_floorSize - 1][i] = 'W';   
    }
    else
    {
      m_floor [i][0] = 'b';
      m_floor [i][m_floorSize - 1] = 'b';
      m_floor [0][i] = 'b';
      m_floor [m_floorSize - 1][i] = 'b';
    } 
  } 
  
  clnr.setx ((rand() % (m_floorSize - 2)) + 1);
  clnr.sety ((rand() % (m_floorSize - 2)) + 1);
  m_floor [clnr.getx()] [clnr.gety()] = clnr.getFirstLetter();  
  
  for (int i = 0; i < MAX_FAM; i++)
  {
    do
    {
      famMemb[i].setx ((rand() % (m_floorSize - 2)) + 1);
      famMemb[i].sety ((rand() % (m_floorSize - 2)) + 1);
    } while (m_floor [famMemb[i].getx()] [famMemb[i].gety()] != ' ');
    m_floor [famMemb[i].getx()] [famMemb[i].gety()] 
          = famMemb[i].getFirstLetter();
  }  
  scatterTrash ();//outputs trashcan and trash ('C' and 't')
}

void house :: setFloor (const char stuff, const int x, const int y)
{ 
  m_floor [x][y] = stuff; 
  return;
}

  
int house :: counttrash()
{
  int count = 0;
  
  for (int i = 1; i < m_floorSize - 1; i++)
  {
    for (int j = 1; j < m_floorSize - 1; j++)
    {
      if (m_floor[i][j] == 't')
        count++;
    }
  }
  return count;
}    
