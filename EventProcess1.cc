#include <iostream>
#include <fstream>
using namespace std;

void FileRead()
{
 
 ifstream fr;
 fr.open("unweighted_events.lhe",ios::in);
 
 ofstream fw4;
 ofstream fw2;
 fw4.open("four",ios::out);
 fw2.open("two",ios::out);
 
 string tag;
 
 double Event[20][13] = {{0.0}}; 
 
 int EventNum = 0;
 
 while(!fr.eof())     //while circulation
 {
  
  fr>>tag;           //put information into tag
  
  if(tag=="<event>")      
  {
   
   fr>>EventNum;       //if tag=<events>
   fr.ignore(99999999,'\n');
   
   for(int i=0; i<EventNum; i++)
   {
    for(int j=0; j<13; j++)
    {
     fr>>Event[i][j];     // put the particle information PID,px,py,pz,E,m.... into Event
    }
   }
   
   for(int i=0; i<4; i++)
   {
    for(int j=0; j<13; j++)
    {
     fw4<<Event[EventNum-4+i][j]<<" ";    // save some information to fw4
    }
    fw4<<endl;
   }
   
   for(int i=0; i<2; i++)
   {
    for(int j=0; j<13; j++)
    {
     fw2<<Event[EventNum-6+i][j]<<" ";
    }
    fw2<<endl;
   }
   
   
   fr>>tag;
   
   if(fr.eof()) break;
   
  }
  else
  {
   
   fr.ignore(99999999,'\n');
   
  }
  
  }
  
}


int main()
{
 
 FileRead();
 
 return 1;
 
}
