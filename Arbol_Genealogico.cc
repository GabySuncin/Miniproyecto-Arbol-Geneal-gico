#include <iostream>
#include <string>

struct FamilyMemembers {
  std::string name;
  int age;
};

struct Node {
  FamilyMemembers familyMember;
  Node* child1;
  Node* child2;
};

// Main Functions
Node* InsertMember(Node* oldestMember, FamilyMemembers member,
                   std::string relationship);
void PrintTree(Node* root, int level);
// Auxiliar Functions
void MainMenu(int& option);
void AskMember(FamilyMemembers& member);

int main(int argc, char* argv[]) {
  int option;
  Node* Root = nullptr;

  do {
    MainMenu(option);

    switch (option) {
      case 1: {
        FamilyMemembers member;
        AskMember(member);
        std::string relationship;
        std::cout << "Especifique la relación ('madre' , 'padre' , 'hijo'): ";
        std::cin >> relationship;
        Root = InsertMember(Root, member, relationship);
        break;
      }

      case 2: {
        int levels = 0;
        std::cout << "\n--------Arbol Genealogico--------" << std::endl
                  << std::endl;
        PrintTree(Root, levels);
        break;
      }

      case 3:
        std::cout << "\nSaliendo del Programa..." << std::endl;
        break;

      default:
        std::cout << "Ha ingresado una opcion de menu incorrecta" << std::endl;
        break;
    }
  } while (option != 3);

  return 0;
}

Node* InsertMember(Node* OldestMember, FamilyMemembers newMember,
                   std::string relationship) {
  // Si esta vacio el arbol, el primer nodo que se crea es el raiz, siendo este
  // el miembro mas longevo
  if (OldestMember == nullptr) {
    Node* newNode = new Node();
    newNode->familyMember = newMember;
    newNode->child1 = nullptr;
    newNode->child2 = nullptr;
    std::cout << "\nSe ha creado el nodo raiz correctamente (abuelo/a)"
              << std::endl;
    return newNode;
  }

  // Segun la relacion recibida en los parametros, creamos ya sea a la madre o
  // al padre.
  if (relationship == "madre") {
    if (OldestMember->child1 == nullptr) {
      OldestMember->child1 = new Node();
      OldestMember->child1->familyMember = newMember;
      OldestMember->child1->child1 = nullptr;
      OldestMember->child1->child2 = nullptr;
      std::cout << "\nSe ha agregado la madre correctamente";
    } else {
      std::cout << "\nLa madre ya está registrada.";
    }
  } else if (relationship == "padre") {
    if (OldestMember->child2 == nullptr) {
      OldestMember->child2 = new Node();
      OldestMember->child2->familyMember = newMember;
      OldestMember->child2->child1 = nullptr;
      OldestMember->child2->child2 = nullptr;
      std::cout << "\nSe ha agregado al padre correctamente.";
    } else {
      std::cout << "\nEl padre ya está registrado.";
    }  // Mientras que si es un hijo, primero necesitamos saber de quien es, si
       // de la madre o del padre, al ya saberlo, se ubica al hijo
       // correspondientemente al padre o a la madre.
  } else if (relationship == "hijo") {
    if (OldestMember->child1 == nullptr && OldestMember->child2 == nullptr) {
      std::cout << "\nNo existe ni madre, ni padre. Debes agregar a una madre "
                   "o padre antes de agregar hijos."
                << std::endl;
      return OldestMember;
    }

    std::string parentRole;
    std::cout
        << "\n¿A quién deseas agregar el hijo/a? Escribe 'madre' o 'padre': ";
    std::cin.ignore();
    getline(std::cin, parentRole);

    Node* parentNode = nullptr;
    if (parentRole == "madre" && OldestMember->child1 != nullptr) {
      parentNode = OldestMember->child1;
    } else if (parentRole == "padre" && OldestMember->child2 != nullptr) {
      parentNode = OldestMember->child2;
    } else {
      std::cout << "\nEl Rol que se escribio no es valido o no existe. "
                << std::endl;
      return OldestMember;
    }

    if (parentNode->child1 == nullptr) {
      parentNode->child1 = new Node();
      parentNode->child1->familyMember = newMember;
      parentNode->child1->child1 = nullptr;
      parentNode->child1->child2 = nullptr;
      std::cout << "\nHijo agregado correctamente." << std::endl;
    } else if (parentNode->child2 == nullptr) {
      parentNode->child2 = new Node();
      parentNode->child2->familyMember = newMember;
      parentNode->child2->child1 = nullptr;
      parentNode->child2->child2 = nullptr;
      std::cout << "\nSegundo hijo agregado correctamente." << std::endl;
    } else {
      std::cout << "\nEl padre o madre seleccionado ya tiene dos hijos."
                << std::endl;
    }

  } else {
    std::cout << "Ha ingresado una opcion valida. Diferente de 'madre , "
                 "'padre' o 'hijo'. "
              << std::endl;
  }

  return OldestMember;
}

void PrintTree(Node* root, int level) {
  if (root == nullptr) {
    std::cout << "\nNo existe ni siquiera el nodo raiz." << std::endl;
    return;
  }

  std::cout << std::string(level * 4, ' ') << root->familyMember.name << " ("
            << root->familyMember.age << ")" << std::endl;
  // Imprime a la Madre con 4 espacios, para mostrar esa jerarquia a partir del
  // nodo raiz
  if (root->child1 != nullptr) {
    std::cout << std::string(level + 4, ' ')
              << "└ Madre: " << root->child1->familyMember.name << " ("
              << root->child1->familyMember.age << ")" << std::endl;
    // Muestra ambos hijos de la madre (si hay) con 8 espacios para que se vea
    // la forma jerargica
    if (root->child1->child1 != nullptr) {
      std::cout << std::string(level + 8, ' ')
                << root->child1->child1->familyMember.name << " ("
                << root->child1->child1->familyMember.age << ")" << std::endl;
    }
    if (root->child1->child2 != nullptr) {
      std::cout << std::string(level + 8, ' ')
                << root->child1->child2->familyMember.name << " ("
                << root->child1->child2->familyMember.age << ")" << std::endl;
    }
  }
  // Se hace con el padre, lo mismo que con la madre.
  if (root->child2 != nullptr) {
    std::cout << std::string(level + 4, ' ')
              << "└ Padre: " << root->child2->familyMember.name << " ("
              << root->child2->familyMember.age << " años)" << std::endl;

    if (root->child2->child1 != nullptr) {
      std::cout << std::string(level + 8, ' ')
                << root->child2->child1->familyMember.name << " ("
                << root->child2->child1->familyMember.age << " años)"
                << std::endl;
    }
    if (root->child2->child2 != nullptr) {
      std::cout << std::string(level + 8, ' ')
                << root->child2->child2->familyMember.name << " ("
                << root->child2->child2->familyMember.age << " años)"
                << std::endl;
    }
  }
}

void MainMenu(int& option) {
  std::cout << std::endl << "\n-------FAMILY TREE-------" << std::endl;
  std::cout << "1. Insertar miembros de la familia" << std::endl;
  std::cout << "2. Imprimir arbol completo" << std::endl;
  std::cout << "3. Salir" << std::endl;
  std::cout << "Ingrese una opcion: ";
  std::cin >> option;
}

void AskMember(FamilyMemembers& member) {
  std::cout << "\nIngrese el nombre del miembro familiar: ";
  std::cin.ignore();
  getline(std::cin, member.name);
  std::cout << "Ingrese la edad del miembro familiar: ";
  std::cin >> member.age;
}
