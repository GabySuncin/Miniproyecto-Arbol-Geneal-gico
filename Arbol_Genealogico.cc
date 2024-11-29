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

//Main Functions

//Auxiliar Functions
void MainMenu (int &option);


int main (int argc, char *argv[]) {
  int option; 

  do {
  
    MainMenu(option);

  switch (option)
  {
  case 1: 
    break;

  case 2: 
    break;

  case 3: 
    break;
  
  case 4: 
    break;

  case 5: 
    break;

  case 6: 
    std::cout << "\nSaliendo del Programa..." <<std::endl; 
    break;

  default:
    std::cout << "Ha ingresado una opcion de menu incorrecta" <<std::endl;
    break;
  }
  } while (option != 6);

  return 0; 
}

void MainMenu (int &option) {
  std::cout << "\n-------FAMILY TREE-------" << std::endl; 
  std::cout << "1. Insertar miembros de la familia" << std::endl; 
  std::cout << "2. Eliminar miembros de la familia" << std::endl; 
  std::cout << "3. Buscar un miembro de la familia" <<std::endl; 
  std::cout << "4. Imprimir arbol completo" <<std::endl; 
  std::cout << "5. Imprimir la relacion entre miembros" <<std::endl; 
  std::cout << "6. Salir" <<std::endl;
  std::cout << "Ingrese una opcion: ";
  std::cin >> option; 
}