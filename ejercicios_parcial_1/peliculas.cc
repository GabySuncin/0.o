#include <iostream> 
#include <string>

const int kMoviesArray = 10; 

struct Movie {
  std::string title; 
  int duration; 
  double rating; 
  std::string genre; 
};

//functions
void FillMovie(Movie *movies);
void FillMoviesArray (Movie movies[]); 
double Average (double sum, double size);
void AverageRatingByGenre (Movie movies[]);
void EditMovieRating(Movie movies[], std::string movieName);
void PrintMoviesArray(Movie movies[]);

int main () {
  Movie movies[kMoviesArray]; 
  int option; 

  do {
    std::cout << "\n-----Movie Tracker------" << std::endl; 
    std::cout << "1. Ingresar Datos de las Peliculas" << std::endl; 
    std::cout << "2. Calcular Calificacion Promedio" << std::endl; 
    std::cout << "3. Actualizar Calificacion" << std::endl; 
    std::cout << "4. Mostrar datos de peliculas" << std::endl; 
    std::cout << "5. Buscar una pelicula en especifico" << std::endl; 
    std::cout << "6. Salir" << std::endl; 
    std::cin >> option; 

    switch (option)
    {
    case 1:
      FillMoviesArray(movies);
      break;

    case 2: 
      AverageRatingByGenre (movies);
      break;
      
    case 3: {
      std::string movie; 
      std::cout << "Ingrese el nombre de la pelicula a la que desea cambiarle la calificacion: ";
      std::cin.ignore();
      getline(std::cin, movie);

      EditMovieRating(movies, movie);
      break; }

    case 4:
      PrintMoviesArray(movies);
      break;

    case 6:
      std::cout << "Saliendo del programa..." << std::endl; 
      break;
    
    default:
      break;
    }
  } while (option != 6);

  return 0; 
}

void FillMovie(Movie &movies) { 

  std::cout << "\nEscriba el titulo de la pelicula: "; 
  std::cin.ignore();
  getline (std::cin, movies.title);
  std::cout << "Escriba el genero de la pelicula (Drama, Accion, Romance, Ciencia Ficcion, Fantasia o Terror): "; 
  getline (std::cin, movies.genre);
  std::cout << "Escriba la duracion en minutos de la pelicula: ";
  std::cin >> movies.duration;
  std::cout << "xEscriba la calificacion que le da a la pelicula (0-10): ";
  std::cin >> movies.rating;


}
void FillMoviesArray(Movie movies[]) {
  for (int i = 0; i < kMoviesArray; i++) {
    std::cout << "Pelicula #" << i + 1 << " :"; 
    FillMovie(movies[i]);
  }
}

void PrintMoviesArray(Movie movies[]) {
  for (int i = 0; i < kMoviesArray; i++) {
    std::cout << "Pelicula #" << i + 1 << " : " <<  movies[i].title << " con una duracion de " << movies[i].duration << " min, del genero " << movies[i].genre << " y con una calificacion de " << movies[i].rating << std::endl; 
  }
}

void AverageRatingByGenre (Movie movies[]) {
  double sumMoviesAction = 0, sumMoviesDrama = 0, sumMoviesRomance = 0, sumMoviesScienceFiction = 0, sumMoviesFantasy = 0, sumMoviesHorror = 0, sumOthers = 0;
   double numMoviesAction = 0, numMoviesDrama = 0, numMoviesRomance = 0, numMoviesScienceFiction = 0, numMoviesFantasy = 0, numMoviesHorror = 0, numOthers = 0;
  double averageMoviesAction, averageMoviesDrama, averageMoviesRomance, averageMoviesScienceFiction, averageMoviesFantasy, averageMoviesHorror, averageOthers = 0; 
  for (int i = 0; i < kMoviesArray; i++) {
    if (movies[i].genre == "Accion") {
      sumMoviesAction = sumMoviesAction + movies[i].rating;
      numMoviesAction++; 
    } else if (movies[i].genre == "Drama") {
      sumMoviesDrama = sumMoviesDrama + movies[i].rating; 
      numMoviesDrama++;
    } else if (movies[i].genre == "Romance") {
      sumMoviesRomance = sumMoviesRomance + movies[i].rating;
      numMoviesRomance++;
    } else if (movies[i].genre == "Ciencia Ficcion") {
      sumMoviesScienceFiction = sumMoviesScienceFiction + movies[i].rating;
      numMoviesScienceFiction++;
    } else if (movies[i].genre == "Fantasia") {
      sumMoviesFantasy = sumMoviesFantasy + movies[i].rating;
      numMoviesFantasy++;
    } else if (movies[i].genre == "Terror") {
      sumMoviesHorror = sumMoviesHorror + movies[i].rating; 
      numMoviesHorror++; 
    } else {
      sumOthers = sumOthers + movies[i].rating; 
      numOthers++; 
    }
  }

  //Calculating Averages
  averageMoviesAction = Average(sumMoviesAction, numMoviesAction);
  averageMoviesDrama = Average(sumMoviesDrama, numMoviesDrama);
  averageMoviesRomance = Average(sumMoviesRomance, numMoviesRomance);
  averageMoviesScienceFiction = Average(sumMoviesScienceFiction, numMoviesScienceFiction);
  averageMoviesFantasy = Average(sumMoviesFantasy, numMoviesFantasy);
  averageMoviesHorror = Average(sumMoviesHorror, numMoviesHorror);
  averageOthers = Average(sumOthers, numOthers);

  std::cout << "Calificacion promedio de peliculas de DRAMA: " << averageMoviesDrama <<std::endl; 
  std::cout << "Calificacion promedio de peliculas de ACCION: " << averageMoviesAction <<std::endl;
  std::cout << "Calificacion promedio de peliculas de ROMANCE: " << averageMoviesRomance <<std::endl;
  std::cout << "Calificacion promedio de peliculas de CIENCIA FICCION: " << averageMoviesScienceFiction <<std::endl;
  std::cout << "Calificacion promedio de peliculas de FANTASIA: " << averageMoviesFantasy <<std::endl;
  std::cout << "Calificacion promedio de peliculas de TERROR: " << averageMoviesHorror <<std::endl;
  std::cout << "Calificacion promedio de peliculas de OTROS: " << averageOthers <<std::endl;

}


double Average(double sum, double size) {
  double average = sum/size; 
  return average; 
}

void EditMovieRating(Movie movies[], std::string movieName) {
  for(int i = 0; i < kMoviesArray; i++) {
    if (movies[i].title == movieName){
      std::cout << "Escriba la nueva calificacion de la pelicula: "; 
      std::cin >> movies[i].rating;
    }
  }
}