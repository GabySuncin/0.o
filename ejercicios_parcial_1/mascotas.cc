#include <iostream>
#include <string>

struct Pet {
  std::string name; 
  int age; 
  std::string vaccinated; 
};

//functions
void AddPets(Pet *pets, int size);
void PrintPets(Pet *pets, int size);
void CountPets(Pet *pets, int size);

int main (int argc, char *argv[]) { 
  int arraySize = 0; 
  std::cout << "Ingrese el tamaño de su arreglo de mascotas: "; 
  std::cin >> arraySize; 
  Pet petsArray[arraySize];
  int option = 0; 

  do {
    std::cout << "\n-----Sistema de Registro de Mascotas-----" <<std::endl; 
    std::cout << "1. Ingresar Datos de las Mascotas" <<std::endl; 
    std::cout << "2. Mostrar todos los registros" <<std::endl;
    std::cout << "3. Editar Estado de Vacunacion" <<std::endl;
    std::cout << "4. Filtrar Mascotas por Estado de Vacunacion" <<std::endl;
    std::cout << "5. Contar Mascotas por Estado de Vacunacion" <<std::endl;
    std::cout << "6. Buscar Mascota por Nombre" <<std::endl;
    std::cout << "7. Salir" <<std::endl;
    std::cout << "Ingrese una opcion:";
    std::cin >> option; 

    switch (option) {
    case 1:
      AddPets(petsArray, arraySize);
      break;

    case 2:
      PrintPets(petsArray, arraySize);
      break;

    case 5:
      CountPets(petsArray,arraySize);
      break; 
    
    default:
      break;
    }
  } while (option != 7);
  return 0; 
}

void AddPets(Pet *pets, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << "\nMascota #" << i + 1 << ": " <<std::endl; 
    std::cout << "Ingrese el nombre de la mascota: ";
    std::cin.ignore();
    getline(std::cin, pets[i].name);
    std::cout << "Estado de vacunacion de la mascota (Vacunada o No Vacunada): ";
    getline(std::cin, pets[i].vaccinated);
    std::cout << "Ingrese la edad de la mascota (en años): ";
    std::cin >> pets[i].age;
    
  }
}

void PrintPets(Pet *pets, int size) {
  std::cout << std::endl; 
  for (int i = 0; i < size; i++) {
    std::cout << "Mascota #" << i + 1 << ": " << pets[i].name << ", con " << pets[i].age << " y esta " << pets[i].vaccinated <<std::endl;
  }
}

void CountPets(Pet *pets, int size) {
  int vaccinatedPets = 0, nonVaccinatedPets = 0; 
  for (int i = 0; i < size; i++) {
    if (pets[i].vaccinated == "Vacunada"){
      vaccinatedPets++; 
    } else if (pets[i].vaccinated == "No Vacunada") {
      nonVaccinatedPets++; 
    }
  }

  std::cout << "\nMascotas Vacunadas: " << vaccinatedPets <<std::endl; 
  std::cout << "Mascotas No Vacunadas: " << nonVaccinatedPets <<std::endl; 
}