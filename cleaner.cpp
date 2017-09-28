// Name: David Wilkerson, Travis Connelly     Date: 5/9/13
// File: cleaner.cpp                          Section: 53 A
// Description: defines the functions prototyped in cleaner.h

#include "house.h"
#include "cleaner.h"
#include "family_member.h"

cleaner :: cleaner (const char name [], const int x, const int y)
{
  strcpy (m_name, name);
  m_x = x;
  m_y = y;
  m_stressLevel = 0;
  m_dead = false;
}

void cleaner :: setx (const int x)
{
  m_x = x;
  return;
}

void cleaner :: sety (const int y)
{
  m_y = y;
  return;
}

ostream & operator << (ostream & out, const cleaner & clnr)
{
  if (!clnr.m_dead)
  {
    out << "Congratulations, " << clnr.m_name
        << " you have successfully cleaned the room!" << endl;
    out << "Your final location was (" << clnr.m_x << "," << clnr.m_y
        << ")." << endl << endl;
  }
  else
    out << clnr.m_name;
  return out;
}

void cleaner :: calculateStress (house & hse)
{
  int floorSize = (hse.getFloorSize() - 2);
  int trash = hse.counttrash();
  
  m_stressLevel = static_cast <float> (trash) / 
                  ((floorSize) * (floorSize)) * 100;
  for (int i = 1; i < floorSize + 1; i++)
  {
    for (int j = 1; j < floorSize + 1; j++)
    {
      if (hse.getFloor (j,i) != ' ' && hse.getFloor (j,i) != 't' &&
          hse.getFloor (j,i) != 'C')
        m_stressLevel += 2;
    }
  }
  return;
}

void cleaner :: step (house & h, family_member m[])
{
  char direct; //int direct;
  char temp;
  bool suc = false;
  
  if (h.getFloor (m_x+1, m_y) == 'C' || h.getFloor (m_x-1, m_y) == 'C' ||
      h.getFloor (m_x, m_y+1) == 'C' || h.getFloor (m_x, m_y-1) == 'C')
  {
    m_vac.empty();
  }
  
  do
  {
    //direct = rand()%4;
    cout << h << endl;
    cout << "Put in a direction (w,a,s,d)";
    cin >> direct;
    cout << endl;
    switch (direct)
    {
      case 'w':
        temp = h.getFloor (m_x, m_y-1);
        switch (temp)
        {
          default:
            for (int i = 0; i < MAX_FAM; i++)
            {
              if (m[i].getFirstLetter() == temp)
              {
                m_vac.vac (m[i]);
                h.setFloor (m_name[0], m_x, m_y-1);
                h.setFloor (' ', m_x, m_y);
                m_y -= 1;
                suc = true;
              }
            }
            break;
          case 't':
            m_vac.vac();
            h.setFloor (m_name[0], m_x, m_y-1);
            h.setFloor (' ', m_x, m_y);
            m_y -= 1;
            suc = true;
            break;
          case ' ':
            h.setFloor (m_name[0], m_x, m_y-1);
            h.setFloor (' ', m_x, m_y);
            m_y -= 1;
            suc = true;
            break;
          case 'W':
            m_dead = true;
            h.setFloor(' ', m_x, m_y);
            suc = true;
        }
        break;
      case 'a':
        temp = h.getFloor (m_x-1, m_y);
        switch (temp)
        {
          default:
            for (int i = 0; i < MAX_FAM; i++)
            {
              if (m[i].getFirstLetter() == temp)
              {
                m_vac.vac (m[i]);
                h.setFloor (m_name[0], m_x-1, m_y);
                h.setFloor (' ', m_x, m_y);
                m_x -= 1;
                suc = true;
              }
            }
            break;
          case 't':
            m_vac.vac();
            h.setFloor (m_name[0], m_x-1, m_y);
            h.setFloor (' ', m_x, m_y);
            m_x -= 1;
            suc = true;
            break;
          case ' ':
            h.setFloor (m_name[0], m_x-1, m_y);
            h.setFloor (' ', m_x, m_y);
            m_x -= 1;
            suc = true;
            break;
          case 'W':
            h.setFloor (' ', m_x, m_y);
            m_dead = true;
            suc = true;
        }
        break;
      case 'd':
        temp = h.getFloor (m_x+1, m_y);
        switch (temp)
        {
          default:
            for (int i = 0; i < MAX_FAM; i++)
            {
              if (m[i].getFirstLetter() == temp)
              {
                m_vac.vac (m[i]);
                h.setFloor (m_name[0], m_x+1, m_y);
                h.setFloor (' ', m_x, m_y);
                m_x += 1;
                suc = true;
              }
            }
            break;
          case 't':
            m_vac.vac();
            h.setFloor (m_name[0], m_x+1, m_y);
            h.setFloor (' ', m_x, m_y);
            m_x += 1;
            suc = true;
            break;
          case ' ':
            h.setFloor (m_name[0], m_x+1, m_y);
            h.setFloor (' ', m_x, m_y);
            m_x += 1;
            suc = true;
            break;
          case 'W':
            h.setFloor (' ', m_x, m_y);
            m_dead = true;
            suc = true;
            break;
        }
        break;
      case 's':
        temp = h.getFloor (m_x, m_y+1);
        switch (temp)
        {
          default:
            for (int i = 0; i < MAX_FAM; i++)
            {
              if (m[i].getFirstLetter() == temp)
              {
                m_vac.vac (m[i]);
                h.setFloor (m_name[0], m_x, m_y+1);
                h.setFloor (' ', m_x, m_y);
                m_y += 1;
                suc = true;
              }
            }
            break;
          case 't':
            m_vac.vac();
            h.setFloor (m_name[0], m_x, m_y+1);
            h.setFloor (' ', m_x, m_y);
            m_y += 1;
            suc = true;
            break;
          case ' ':
            h.setFloor (m_name[0], m_x, m_y+1);
            h.setFloor (' ', m_x, m_y);
            m_y += 1;
            suc = true;
            break;
          case 'W':
            h.setFloor (' ', m_x, m_y);
            m_dead = true;
            suc = true;
        }
        break;
    }
  } while (!suc);
  
  return;
}

void cleaner :: setdead (const bool dead)
{
  m_dead = dead;
  return;
}
