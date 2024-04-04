#include <iostream>
#include<vector>
#include<string>
using namespace std;


class person{        //person class
     string name;
     pair<int,string> level;  // 1 level-lead
                              // 2 level-co-lead
                              //3 level-member
    public:       
     string getname() const{      //const keyword for not changing the state of object
        return name;
    }               
    
    int getlevel() const{
        return level.first;  //level
    }
    
    string get_level() const{
        return level.second;   //power
    }
    
    void setname(string name)
    {
        this->name=name;   //use of this (pointer to current object)
    }
    
     void setlevel(int level)
    {
        this->level.first=level;
    }
    
      void set_level(string level)
    {
        this->level.second=level;
    }
     
};

 class subteam{               //subteam class
        vector<person> members;
        
        public:
                 void addMember(person p) {
                      members.push_back(p); // Add person object to the vector
                     }
                     
             void printMembers() {
                for (const auto &member : members) {   //iterating through each member

                     cout << "Member name: " << member.getname() << endl;
                     cout<< "Member level:"<<member.getlevel()<< endl;
                     cout<< "Member designation:"<<member.get_level()<< endl;
                }
             }                 
        
 };

int main() {
       subteam software;  //subteam object creation
     
     person p1;                 //member 1
     p1.setname("Rohit");         //name
     p1.setlevel(1);               //level
     p1.set_level("lead");           //power(responsibility)
     software.addMember(p1);        //adding to subteam as member

    // Adding more members
    person p2;
    p2.setname("Alice");
    p2.setlevel(2);
    p2.set_level("co-lead");
    software.addMember(p2);
     
    person p3;
    p3.setname("Bob");
    p3.setlevel(3);
    p3.set_level("member");
    software.addMember(p3);
    
    // Print members of the software subteam
    cout << "Members in the software team:" << endl;
    software.printMembers();
} 