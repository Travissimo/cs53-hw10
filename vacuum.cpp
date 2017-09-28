// Name: David Wilkerson, Travis Connelly   Date: 5/4/13
// File: vacuum.cpp                         Section: 53 A
// Purpose: to define functions  for vacuum class in vacuum.cpp

#include "vacuum.h"

vacuum :: vacuum()
{
  m_short = false;
  m_explode = false;
  m_numtrash = 0;
}

void vacuum :: vac()
{
  int temp;
  trash t;
  if (m_numtrash < BMAX)
  {
    m_bag[m_numtrash] = t;
    m_numtrash++;
  }
  else 
    m_explode = true;
    
  temp=rand()%100;
  if (temp < (t.getpotent()/2)) //chance to short is 1/2 of potential
  {
    m_short = true;
  } 
  return;
}

void vacuum:: isExplode()
{
  if (m_numtrash >= BMAX-1)
  {
    m_explode = true;
  }
  return;
}

void vacuum::empty()
{
  cout << "The cleaner emptied this into the trash can: " << endl;
  if (!m_numtrash)
    cout << "\tNOTHING!?! hmmmmmmm..." << endl;
  else
  {
    for (int i = 0; i < m_numtrash; i++)
      cout << "\t" << m_bag[i].getname() << endl;
  } 
  m_numtrash = 0;
  cout << endl;
  
  return;
}

void vacuum::printBag()
{
  cout << "This is what was left in the vacuum bag: " << endl;
  if (!m_numtrash)
    cout << "\tNOTHING!?! Try harder next time!" << endl;
  else
  {
    for (int i = 0; i < m_numtrash; i++)
      cout << "\t" << m_bag[i].getname() << endl;
  }
  cout << endl;
  
  return;
}


void vacuum:: vac(family_member & m)
{
  int temp;
  string name;
  int pot = (m.getSloppy()/2); // % chance to short is 1/2 of sloppiness 
                               // factor 
  m.giveName (name);
  if (m_numtrash < BMAX) 
  {
    m_bag[m_numtrash].setpotent(pot*2);
    m_bag[m_numtrash].setname(name);
    m_numtrash++;
  }
  else 
    m_explode = true;
  
  m.setdead(true);
  m.setvacuumed(true);
  m.setx(0);
  m.sety(0);
  temp = rand()%100;
  if (temp < pot)
  {
    m_short = true;
  }    
  return;
}

            
