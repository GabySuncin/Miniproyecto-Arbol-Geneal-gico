#include <iostream>
#include <string>
#include <set> 

struct FamilyMemembers {
std::string name; 
int age;
std::set <FamilyMemembers> children; 

//Compara por edad
bool operator<(const FamilyMemembers& other) const {
        return name < other.name;
    }
};

//Main Functions
void InsertMember(std::set <FamilyMemembers>& tree);
void InsertChildren(std::set <FamilyMemembers>& tree);
FamilyMemembers FindMember (std::set<FamilyMemembers>& tree, std::string name);
//Auxiliar Functions
void MainMenu (int &option);
void SubMenuInsertMember(int &option);
void AskMember (std::string &member);


int main (int argc, char *argv[]) {
  int option; 
  std::set <FamilyMemembers> FamilyTree;

  do {
  
    MainMenu(option);

  switch (option) {
  case 1: {
    int subOption; 
     SubMenuInsertMember(subOption);
     switch (subOption)
     {
     case 1:
      InsertMember(FamilyTree);
      break;

      case 2:
      InsertChildren(FamilyTree);
      break;

     default:
     std::cout << "Ha ingresado una opcion de menu incorrecta..." <<std::endl; 
      break;
     }

    break;}

  case 2: 
    break;

  case 3: {
    std::string memberName; 
     AskMember(memberName);
    FamilyMemembers memberFound = FindMember(FamilyTree, memberName);
    std::cout << "-----Miembro Encontrado -----" <<std::endl; 
    std::cout << "Nombre: " << memberFound.name <<std::endl; 
    std::cout << "Edad: " << memberFound.age <<std::endl; 
    break;}
  
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

void InsertMember(std::set <FamilyMemembers>& tree) {
  if (tree.empty()){
    FamilyMemembers oldestMember;
    std::cout << "\nIngrese el nombre del miembro mas longevo de tu arbol familiar: ";
    std::cin.ignore();
    getline(std::cin, oldestMember.name);
    std::cout << "Ingrese la edad del miembro familiar: "; 
    std::cin >> oldestMember.age; 
    tree.insert(oldestMember);

    return;
  }

  FamilyMemembers member; 
  std::cout << "\nIngrese el nombre del miembro familiar: ";
  std::cin.ignore();
  getline(std::cin, member.name);
  std::cout << "Ingrese la edad del miembro familiar: ";
  std::cin >> member.age;
  tree.insert(member);
}

void InsertChildren(std::set <FamilyMemembers>& tree) {
if (tree.empty()){
    std::cout << "\nEl Arbol esta vacio. Se necesitan agregar miembros familiares al arbol para poder agregar hijos." <<std::endl;
    return;
  }
std::string parentName; 
std::cout << "Ingrese el nombre del pariente del hijo/a:" <<std::endl;
std::cin.ignore();
getline(std::cin, parentName);

FamilyMemembers parent = FindMember(tree,parentName);


FamilyMemembers child;
std::cout << "\nIngrese el nombre del hijo/a: ";
  std::cin.ignore();
  getline(std::cin, child.name);
  std::cout << "Ingrese la edad del hijo/a: ";
  std::cin >> child.age; 

  parent.children.insert(child);

  tree.insert(child);
}

FamilyMemembers FindMember(std::set <FamilyMemembers>& tree, std::string name) {
  for(FamilyMemembers member : tree) {
    if (member.name == name) {
      return member; 
    }
  }
  std::cout << "\nNo se encontro el miembro buscado. " <<std::endl; 
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

void SubMenuInsertMember(int &option) {
  std::cout << "\nEscriba el numero de opcion segun lo que desea realizar: " <<std::endl; 
    std::cout << "1. Insertar un miembro familiar " <<std::endl; 
    std::cout << "2. Insertar un hijo de un miembro familiar " <<std::endl;
    std::cout << "Ingrese una opcion: ";
    std::cin >> option;
}

void AskMember (std::string &member) {
  std::cout << "Ingrese el nombre del miembro familiar que desea buscar: ";
    std::cin.ignore(); 
    getline(std::cin, member);
}
