// Name: David Wilkerson, Travis Connelly   Date: 5/4/13
// File: main.cpp                           Section: 53 A
// Purpose: to simulate the everyday life of marge as she tries to clean.

#include "house.h"
#include "cleaner.h"
#include "family_member.h"
#include "trash.h"
#include "vacuum.h"
#include "mainfucts.h"
#include <cstdlib>
#include <ctime>


//Before you start grading, I'd like to let you know that our program can
//  vacuum family members. Unfortunately, no sound effects are included. Sorry!

//Also, this is the order of each step:
//  family_members make trash in an adjacent square, then step if alive.
//  cleaner checks for trash can in all adjacent squares, calls empty() 
//       function if there. This function outputs what is emptied to screen.
//  cleaner interacts with a random adjacent square, then steps that way.
//  several checks to see if cleaner is dead/alive are made.
//  if cleaner is dead or trash on the board = 0, while loop is exited.

//Lastly, everyone in our program is forced to move if an empty space or 
//  window is available. The cleaner can never be surrounded, since he/she
//  can vacuum both trash and family members, so he/she always moves.
 
int main()
{ 
  srand (time(NULL)); //causes rand() to be truly random every time this 
                      //program is called
  int deathClnr = 0; //tells how cleaner died 
  
  greetings();
  
  cleaner c ("Marge");
  family_member simpsons[MAX_FAM];
  house h (c, simpsons);
  
  do
  {  
    cout << h << endl; //commented out the house output for each step
    
    for (int i = 0; i < MAX_FAM;i++)
    {
      simpsons[i].maketrash (h);
      simpsons[i].step (h);
    }
    
    c.step (h, simpsons);
    c.getVac().isExplode();
    
    if (c.getVac().getExplode())
    {
      c.setdead (true);
      deathClnr += 1;
    }
    
    if (c.getVac().getshort())
    {
      c.setdead (true);
      deathClnr += 4;
    }
    
    c.calculateStress (h);
    if( c.getstress() >= 100)
    {
      c.setdead (true);
      deathClnr += 7;
    }                
  } while(!c.getdead() && h.counttrash());  
  
    cout << h << endl;
    cout << "Here are the results: " << endl << endl << endl;
    
    if (!c.getdead())
      cout << c;
    else
    {
      switch (deathClnr)
      {
        case 0://death by window
          cout << c << " has been splattered by falling out a window."
               << endl << endl; 
          break;
          
        case 1://death by exploding
          cout << c << " has been blown up by the vacuum cleaner " 
                       "exploding." << endl << endl;
          break;
          
        case 4://death by electrocution
          cout << c << " has been electrocuted by vacuuming "
                       "with a shorted vacuum." << endl;
          cout << "\tThis was the cause of the short: " 
               << c.getVac().getTrash().getname() << endl << endl;   
          break;
          
        case 5://death by exploding AND electrocution
          cout << c << " has been blown up by the vacuum cleaner "
                       "exploding, and\n also electrocuted "
                       "by vacuuming with a shorted vacuum.\n"
                       " Poor " << c << "!" << endl;
          cout << "\tThis was the cause of the short: "
               << c.getVac().getTrash().getname() << endl << endl;
          break;
          
        case 7://death by heart attack
          cout << c << " has died of a heart attack from an overload of stress."
               << endl << endl;
          break;
          
        case 8://death by heart attack AND exploding
          cout << c << " has been blown up by the vacuum cleaner "
                       "exploding, and\n also died of a heart attack from "
                       "an overload of stress.\n Poor " << c << "!";
          cout << endl << endl;
          break;
          
        case 11://death by heart attack AND electrocution
          cout << c << " has been electrocuted by vacuuming with a shorted "
                       "vacuum, and\n also died of a heart attack from "
                       "an overload of stress.\n Poor " << c << "!";
          cout << endl;
          cout << "\tThis was the cause of the short: "
               << c.getVac().getTrash().getname() << endl << endl;
          break;
          
        case 12://death by heart attack, exploding, AND electrocution (unlikely)
          cout << c << " has been blown up by the vacuum cleaner,\n "
                       "electrocuted by vacuuming with a shorted vacuum,\n " 
                       "and also died of a heart attack from an overload of "
                       "stress.\n WORST CASE SCENARIO HAPPENED! CRAZY!!!";
          cout << endl;
          cout << "\tThis was the cause of the short: "
               << c.getVac().getTrash().getname() << endl << endl;             
      }    
    }
    
    c.getVac().printBag(); //outputs what was left in vac bag
    
    for ( int i = 0; i < MAX_FAM;i++)
    {
      if (simpsons[i].getdead())
      {
        if (simpsons[i].getvacuumed())
          cout << simpsons[i] << " has been killed by being vacuumed." << endl;
        else
          cout << simpsons[i] << " has been splattered by falling "
                  "out the window." << endl;
      }
      else
        cout << simpsons[i];         
    }                     
  cout << endl;
       
  farewell();   
  
  return 0;
} 

