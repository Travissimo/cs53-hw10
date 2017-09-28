// Name: David Wilkerson, Travis Connelly       Date: 4/26/13
// File: family_member.cpp                      Section: 53 A
// Description: defines the functions found in the family_member.h file.

#include "family_member.h"
#include "house.h"


family_member :: family_member (const int x, const int y)
{
  ifstream in;
  static int count = 1;
  m_dead = false;
  m_vacuumed = false;
  m_x = x;
  m_y = y;
  in.open ("family_member.txt");
  
  for (int i = 0; i < count; i++)
  {
    in >> m_name;
    in >> m_sloppinessFactor;
  }
  count++;
  in.close ();
}
    
void family_member :: setx (const int x)
{
  m_x = x;
  return;
}

void family_member :: sety (const int y)
{
  m_y = y;
  return;
}

void family_member :: giveName (string & name)
{
  name = m_name;
  return;
}

ostream & operator << (ostream & out, const family_member & famMemb)
{
  if ( famMemb.m_dead == true)
  {
    out << famMemb.m_name;
  }
  else
  {  
    out << famMemb.m_name << " survived the cleaning and is located at ("
        << famMemb.m_x << "," << famMemb.m_y << ")." << endl; 
  }
  return out;
}

void family_member :: step (house & h)
{
  int direct;
  char temp; 
  bool suc = false;
  
  if (!m_dead)
  {
    if(h.getFloor (m_x+1, m_y) != ' ' && h.getFloor (m_x-1, m_y) != ' ' &&
       h.getFloor (m_x, m_y+1) != ' ' && h.getFloor (m_x, m_y-1) != ' ')
    {
      suc = true;
      if (h.getFloor (m_x+1, m_y) == 'W' || h.getFloor (m_x-1, m_y) == 'W' ||
          h.getFloor (m_x, m_y+1) == 'W' || h.getFloor (m_x, m_y-1) == 'W')
        suc = false;          
    }     
    
    do
    {
      direct = rand()%4;
      switch (direct)
      {
        case 0:
          temp = h.getFloor (m_x, m_y-1);
          switch (temp)
          {
            case ' ':
              h.setFloor (m_name[0], m_x, m_y-1);
              h.setFloor (' ', m_x, m_y);
              m_y -= 1;
              suc = true;
              break;
            case 'W':
              m_dead = true;
              h.setFloor (' ',m_x, m_y);
              m_x = 0;
              m_y = 0;
              suc = true;
          }  
          break;
        case 1:
          temp = h.getFloor (m_x-1, m_y);
          switch (temp)
          {
            case ' ':
              h.setFloor (m_name[0], m_x-1, m_y);
              h.setFloor (' ', m_x, m_y);
              m_x -= 1;
              suc = true;
              break;
            case 'W': 
              h.setFloor (' ',m_x, m_y);
              m_dead = true;
              m_x = 0;
              m_y = 0;
              suc = true;
          }  
          break;
        case 2:
          temp = h.getFloor (m_x+1, m_y);
          switch (temp)
          {
            case ' ':  
              h.setFloor (m_name[0], m_x+1, m_y);
              h.setFloor (' ', m_x, m_y);
              m_x += 1;
              suc = true;
              break;
            case 'W':
              h.setFloor (' ', m_x, m_y);  
              m_dead = true;
              m_x = 0;
              m_y = 0;
              suc = true;
          }
          break;
        case 3:
          temp = h.getFloor (m_x, m_y+1);
          switch (temp)
          {
            case ' ':
              h.setFloor (m_name[0], m_x, m_y+1);
              h.setFloor (' ', m_x, m_y);
              m_y += 1;
              suc = true;
              break;
            case 'W':
              h.setFloor (' ', m_x, m_y);
              m_dead = true;
              m_x = 0;
              m_y = 0;
              suc = true;
          }
          break;
      }
    }while (!suc);
  }
  return;
}                               

void family_member :: setdead (bool dead)
{
  m_dead = dead;
  return;
}

void family_member :: setvacuumed (bool vac)
{
  m_vacuumed = vac;
  return;
}    

void family_member :: maketrash (house & h)
{
  int temp;
  int direct;
  bool suc = false;
  
  temp = rand()%100;
  if(temp < (m_sloppinessFactor / 2))//chance to throw trash is 1/2 of the 
  {                                  //sloppiness factor
    if (h.getFloor (m_x, m_y-1) != ' ' && h.getFloor (m_x, m_y+1) != ' ' &&
        h.getFloor (m_x+1, m_y) != ' ' && h.getFloor (m_x-1, m_y) != ' ')
      suc = true;
    do
    {
      direct = rand()%4;
      switch (direct)
      {
        case 0:
          if (h.getFloor (m_x, m_y-1) == ' ')
          {
            h.setFloor ('t', m_x, m_y-1);
            suc = true;
          }
          break;
        case 1:
          if (h.getFloor (m_x, m_y+1) == ' ')
          { 
            h.setFloor ('t', m_x, m_y+1);
            suc = true;
          }
          break;
        case 2:
          if (h.getFloor (m_x-1, m_y) == ' ')
          {  
            h.setFloor ('t', m_x-1, m_y);
            suc = true;
          }
          break;
        case 3:
          if (h.getFloor (m_x+1, m_y) == ' ')
          {
            h.setFloor ('t', m_x+1, m_y);
            suc = true;
          }
          break;
          
      }     
    } while (!suc);
  }  
  return;
} 
   
