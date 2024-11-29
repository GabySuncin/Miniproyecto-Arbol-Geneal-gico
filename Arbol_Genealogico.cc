#include <iostream>
#include <string>
#include <set> 

struct FamilyMemembers {
std::string name; 
int age;
std::set <FamilyMemembers*> children; 

//Compara por edad
bool operator<(const FamilyMemembers& other) const {
        return age < other.age;
    }

};



int main (int argc, char *argv[]) {
  



  return 0; 
}