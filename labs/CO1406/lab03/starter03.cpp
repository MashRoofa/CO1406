// lab03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

#define MAX 100


typedef struct movie {
    string title;
    unsigned short year;
    unsigned short rating;
};

typedef struct movieDatabase {
    movie movies[MAX];
    unsigned int count = 0;
};

int menu();
string printMovie(movie m);
void showMovies(movieDatabase& db);
void addMovie(movieDatabase& db, string title, unsigned short year, unsigned short rating);
void loadDatabase(movieDatabase& db);
unsigned int findMovie(movieDatabase& db, string key);
unsigned int findMovieMaxRating(movieDatabase& db);
void updateMovie(movieDatabase& db, string key, string title, unsigned short year, unsigned short rating);
void findMoviesByYear(movieDatabase& db, unsigned short year);
void deleteMovie(movieDatabase& db, string key);
void sortMovies(movieDatabase& db);
int compare(const void* a, const void* b);

int main()
{
    movieDatabase db;

    string key;
    string title;
    unsigned short year;
    unsigned short rating;

    int choice = -1;
    while ((choice = menu()) != 10) {
        switch (choice) {
        case 1:
            showMovies(db);
            break;

        case 2:
            cout << "Enter movie title to search: ";
            cin >> key;
            cout << "Position of " << key << findMovie(db, key) << endl;
            break;

        case 3:
            cout << "Enter new movie data {title year rating}: ";
            cin >> title >> year >> rating;
            addMovie(db, title, year, rating);
            break;

        case 4:
            cout << "Enter movie to delete: ";
            cin >> key;
            deleteMovie(db, key);
            break;

        case 5:
            cout << "Enter movie to update: ";
            cin >> key;
            cout << "Enter new movie data {title year rating}: ";
            cin >> title >> year >> rating;
            updateMovie(db, key, title, year, rating);
            break;

        case 6:
            cout << printMovie(db.movies[findMovieMaxRating(db)]);
            break;

        case 7:
            cout << "Enter year to search: ";
            cin >> year;
            findMoviesByYear(db, year);
            break;

        case 8:
            sortMovies(db);
            break;

        case 9:
            loadDatabase(db);
            break;

        default:
            cout << "\n\n!!!Invalid Choice!!!\n\n" << endl;
        }
        fflush(NULL);
    }
}

int menu() {
    cout << "+------------------------+" << endl;
    cout << "|        Main Menu       |" << endl;
    cout << "+------------------------+" << endl;
    cout << endl << endl;

    cout << "1. Show List of Movies" << endl;
    cout << "2. Search for a Movie" << endl;
    cout << "3. Add a Movie" << endl;
    cout << "4. Delete a Movie" << endl;
    cout << "5. Update a Movie" << endl;
    cout << "6. Find movie with max rating" << endl;
    cout << "7. Find movies of year" << endl;
    cout << "8. Sort movies by rating" << endl;
    cout << "9. Load Movies from File" << endl;
    cout << "10. Exit" << endl << endl;

    cout << "Enter choice: ";

    static int choice = -1;
    cin >> choice;

    return choice;
}

string printMovie(movie m) {
    return m.title + '\t' + std::to_string(m.year) + "\t" + std::to_string(m.rating) + "\n";
}

void showMovies(movieDatabase& db) {
    //check if the database is empty
    //if it is, print an empty message
    
    //if not, print all the movies {Title tab Year tab Rating), one in every line
    
}

void addMovie(movieDatabase& db, string title, unsigned short year, unsigned short rating) {
    //check if the database is full
    //if it is not, add the movie
    
    //else print that the Database is full
    
}

void loadDatabase(movieDatabase& db) {
    ifstream file("movies.csv");
    //declare appropriate string variables to store the strings read from the file
    
    //declare appropriate short variables to convert year and rating strings
   
    //reset the database counter
    
    //read and skip the first line
    

    while (file.good())
    {
        //read the title until the first comma
        
        //read the year until the second comma
        
        //read the rating until the end of the line
        
        //convert year and rating
        
        //call addMovie to add the movie read into the database
        
    }
    cout << endl << "File loaded succesfully" << endl;
}

unsigned int findMovie(movieDatabase& db, string key) {
    //search for a movie with a title equal to the key
    //if one is found, return the key
    //otherwise, return -1

}

unsigned int findMovieMaxRating(movieDatabase& db) {
    //search for the movie with a the maximum rating and return its position
    unsigned short maxRatingIndex = 0;

    for (int i = 1; i < db.count; i++)
        if (db.movies[i].rating > db.movies[maxRatingIndex].rating) maxRatingIndex = i;

    return maxRatingIndex;
}

void findMoviesByYear(movieDatabase& db, unsigned short year) {
    //search for all movies that were released in a specific year
    for (int i = 0; i < db.count; i++)
        if (db.movies[i].year == year)
            cout << printMovie(db.movies[i]);
}

void updateMovie(movieDatabase& db, string key, string newTitle, unsigned short newYear, unsigned short newRating) {
    //search for a movie with a title equal to the key using findMovie
    //if one is found, update its title, year and rating with the new data   
    unsigned int pos = -1;
    pos = findMovie(db, key);
    if (pos != -1) {
        db.movies[pos].title = newTitle;
        db.movies[pos].year = newYear;
        db.movies[pos].rating = newRating;
    }
    //otherwise, print that the selected movie was not found
    else {
        cout << "Movie " << key << " not found!" << endl;
    }

}

void deleteMovie(movieDatabase& db, string key) {
    unsigned int pos = -1;
    //find the position of the element you are trying to delete using findMovie
    pos = findMovie(db, key);
    //check if the position is found
    //if it is not found then print that the specific movie is not found (include the name of the movie)
    if (pos == -1) {
        cout << "Movie " << key << " not found!" << endl;
    }
    //if it is found then delete the movie from the database
    //it is important that the movie slot does not remain empty
    else {
        for (int i = pos; i < db.count; i++) db.movies[i] = db.movies[i + 1];
        db.count--;
    }

}

int compare(const void* a, const void* b)
{
    return (*(movie*)a).rating - (*(movie*)b).rating;
}

void sortMovies(movieDatabase& db) {
    //use quicksort (qsort) to sort the movie database
    qsort(db.movies, db.count, sizeof(movie), compare);
}

