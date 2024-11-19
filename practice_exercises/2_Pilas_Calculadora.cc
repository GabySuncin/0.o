#include <iostream>
#include <stack>
#include <string>

int main (int argc, char *argv[]) {
  int optionMenu; 
  double value; 
  char operators; 

  std::stack<double> valuesStack; 

  do {
  std::cout << "\n-----CALCULATOR----- "<< std::endl; 
  std::cout << "1. Agregar un valor" << std::endl; 
  std::cout << "2. Operar valores" << std::endl; 
  std::cout << "3. Obtener resultado de la ultima operacion que se realizo" <<std::endl;
  std::cout << "4. Salir" <<std::endl; 
  std::cout << "Ingrese una opcion: "; 
  std::cin >> optionMenu;

  switch (optionMenu)
  {
  case 1:
    std::cout << "Ingrese un valor: "; 
    std::cin >> value;

    break;
  
  default:
    break;
  } 
  } while (optionMenu != 4);
  
  return 0; 
}

void SaveValues(std::stack<double> &values,double value) {
  values.push(value);
}