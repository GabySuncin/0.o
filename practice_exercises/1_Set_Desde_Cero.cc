#include <iostream>
#include <string>

struct Person {
  int id; 
  std::string name; 
};

struct Node {
  Person person; 
  Node* left;
  Node* right; 
};

//Main Functions
Node* Insert(Node* root, Person newPerson);
Node* Search (Node* root, int id);
void PrintSet(Node* root);
Node* DeletePerson (Node* root, int id);

//Auxiliar Functions
Person AskData ();
void MainMenu (int &option);
Node* FindMin(Node* node);

int main () {
  int option; 
  Node* root = nullptr;

  do {
   MainMenu(option);

  switch (option)
  {
  case 1: {
    Person person = AskData();//Preguntamos la Data
    root = Insert(root, person); //Actualizamos la raiz, debido a que en la funcion le hemos hecho modificaciones. 
    break;}
  
  case 2:{
    Person person = AskData(); //Preguntamos siempre la Data
    Node *personFinded = Search(root, person.id); 
    // Accedemos al contenido con un puntero ya que la funcion de Search, retorna un nodo. 
    std:: cout << "\nID: " << personFinded->person.id << "Nombre de la persona: " << personFinded->person.name << std::endl;

    break;}

  case 3:{
    Person person = AskData();
    root = DeletePerson (root, person.id); 
    break;}

  case 4:
    PrintSet(root);
    break;

  case 5:
    std::cout << "Saliendo del programa...." <<std::endl; 
    break;
  
  default:
  std::cout << "Ha ingresado una opcion incorrecta de menu" <<std::endl; 
    break;
  }
  } while (option!=5);

  return 0;
}

void MainMenu (int &option) {
  std::cout << "\n-------Sistema de Ordenar Numeros-------" << std::endl;
  std::cout << "1. Insertar una persona al arbol" << std::endl;
  std::cout << "2. Buscar una persona segun su posicion" << std::endl; 
  std::cout << "3. Eliminar a una persona" << std::endl; 
  std::cout << "4. Mostrar Set" << std::endl; 
  std::cout << "5.Salir" <<std::endl; 
  std::cout << "Ingrese una opcion: ";
  std::cin >> option; 
}

Node* Insert(Node* root, Person newPerson) {
  if (root == nullptr) { 
    Node* newNode = new Node();
    newNode->person = newPerson;
    newNode->left = nullptr; 
    newNode->right = nullptr;
    return newNode;
    //Si esta vacia creamos un nuevo nodo y asignamos que sus hijos izquierdo y derecho no hay nada y retornamos el nuevo nodo, que en el main es el valor que le damos a la raiz. 
  }

  if (newPerson.id < root->person.id) {  
    root->left = Insert(root->left, newPerson);
    //Si el id de la persona es mejor a la de la raiz, la inserta a la izquierda, llamando a la funcion.
  } else {
    root->right = Insert(root->right, newPerson);
    //Lo mismo en este caso, solo que a la derecha llamando a la funcion recursivamente. 
  }

  return root; //Retornamos la raiz, porque la hemos modificado y ya en el main, le damos sus valores correspondientes. 
}

Node* Search (Node* root, int id) {
  if (root == nullptr) { //Verificamos que no este vacia
  return root;
  }

  if (root->person.id == id) { //Comparamos para ver si el id de la raiz es el mismo, y asi encontramos ya a la persona. 
    std::cout << "\nSe ha encontrado correctamente a la persona\n" <<std::endl;
    return root; //Retormamos la raiz porque ahi es donde esta la persona que encontramos
  }

  if (id < root->person.id) {  
    return Search(root->left, id);
    // Verificamos si el ID es menor, y si si es mejor, entonces nos tenemos que dirigir al hijo izquierdo, llamando la funcion pero ahora con el hijo izquierdo.
  } else { 
    return Search(root->right, id);
    // Sino es menor, ni igual, entonces tiene que ser menor y llamamos la funcion de nuevo pero ahora con el hijo derecho que son los mas grandes.
  }
 
 //Se va realizando esto hasta que el filtro de igual funcione y lo encuentre. 
}

void PrintSet(Node* root){ //Se esta mostrando en formato Preorden
  if (root != nullptr) { //Se mantiene mostrando mientras el root que es el que se esta moviendo, no este vacio, osea, recorre todo el arbol
    std::cout << std::endl;
    std::cout << "ID de la persona: " << root->person.id << ", Nombre de la persona: " << root->person.name <<std::endl; //Imprime primero la raiz

    PrintSet(root->left); // Luego imprime el izquierdo
    PrintSet(root->right); //Luego imprime el derecho
}
}

Person AskData () { //Funcion para reducir codigo que solo pregunta los datos de la persona
  Person data;
  std::cout << "Ingrese la posicion de la persona en el arbol: ";
  std::cin >> data.id;

  std::cout << "Ingrese el nombre de la persona: "; 
  std::cin.ignore();
  getline(std::cin, data.name);

  return data;
}

Node* FindMin(Node* node) { 
  while (node->left != nullptr) {
    node = node->left;
    // Se encarga de encontrar la cola del arbol se podria decir, la hoja mas pequeña o solita
  }

  return node;
}

Node* DeletePerson (Node* root, int id) { //Borramos usando como parametro numeros
  if (root == nullptr) { //Si la raiz esta vacia solo la retornamos
    return root; 
  }

  if (id < root->person.id) { //Encuentra primero si el id es menor que el de la raiz, lo cual significa, que es el hijo izquierdo de la raiz
    root->left = DeletePerson(root->left, id); //Manda a llamar a la funcion nuevamente pero ahora con el hijo de la izquierda
  } else if (id > root->person.id) { //Lo mismo que el anterior, solo que en este caso si es mayor, el id, esta en sus hijos de la derecha. 
    root->right = DeletePerson(root->right, id); // Manda a llamar la funcion nuevamente pero ahora con el hijo de la derecha. 
    //De esta forma se mantiene filtrando. 
  } else {
    if (root->left == nullptr && root->right == nullptr) { // Si ambos hijos de la raiz estan vacios, entonces la que tenemos que borrar es la raiz y le asignamos nullptr para que no quede al aire. 
      delete root; 
      root = nullptr; 
    } else if (root->left == nullptr) { // Si el hijo de la izquierda esta vacio, entonces indica que la raiz ahora sera el hijo de la derecha. 
      Node* temp = root; 
      root = root->right; 
      delete temp; 
    } else if (root->right == nullptr) {// Si el hijo de la derecha esta vacio, entonces indica que la raiz ahora sera el hijo de la izquierda. 
      Node* temp = root;
      root = root->left;
      delete temp; 
    } else {
      Node* temp = FindMin(root->right); // Si ni el hijo izquierdo o derecho estan vacios, significa que no hemos llegado al final del arbol y mandamos a llamar la funcion para encontrar la hojita mas pequeña.
      root->person = temp->person;//Comparamos que la informacion de root sea igual y haya pasado los filtros bien.
      root->right = DeletePerson(root->right, temp->person.id); //Mandamos a llamar a la funcion otra vez para que en alguno de los filtros ya encuentre un hijo que tenga null y pueda borrarse.
    }
  }

  std::cout << "\nSe ha eliminado correctamente a la persona " <<std::endl; 

  return root; //Devolvemos la raiz actualizada
}