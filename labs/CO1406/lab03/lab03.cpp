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

int main()
{
    movieDatabase db;
    
    string key;
    string title;
    unsigned short year;
    unsigned short rating;

    int choice = -1;
    while ( (choice = menu()) != 10) {
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

int compare(const void* a, const void* b)
{
    return (*(movie*)a).rating - (*(movie*)b).rating;
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
    cout << "10. Exit" << endl<<endl;

    cout << "Enter choice: " ;

    static int choice = -1;
    cin >> choice;

    return choice;
}

string printMovie(movie m) {
    return m.title + '\t' + std::to_string(m.year) + "\t" + std::to_string(m.rating) + "\n";
}

void showMovies(movieDatabase& db) {
    if (db.count == 0) {
        cout << "Database empty!" << endl;
    }
    else {
        cout << "+------------------------+" << endl;
        cout << "|     Movie Database     |" << endl;
        cout << "+------------------------+" << endl;
        cout << endl << endl;

        cout << "Title\tYear\tRating\n";
        for (int i = 0; i < db.count; i++) {
            cout << printMovie(db.movies[i]);
        }
    }
}

void addMovie(movieDatabase& db, string title, unsigned short year, unsigned short rating) {
    db.movies[db.count].title = title;
    db.movies[db.count].year = year;
    db.movies[db.count].rating = rating;
    db.count++;
}

unsigned int findMovie(movieDatabase& db, string key) {
    for(int i=0; i<db.count; i++)
        if (db.movies[i].title == key) return i;
     
    return -1;
}

unsigned int findMovieMaxRating(movieDatabase& db) {
    unsigned short maxRatingIndex = 0;

    for (int i = 1; i < db.count; i++)
        if (db.movies[i].rating > db.movies[maxRatingIndex].rating) maxRatingIndex = i;

    return maxRatingIndex;
}

void findMoviesByYear(movieDatabase& db, unsigned short year) {
    for (int i = 0; i < db.count; i++)
        if (db.movies[i].year == year)
            cout << printMovie(db.movies[i]);
}

void updateMovie(movieDatabase& db, string key, string title, unsigned short year, unsigned short rating) {
    unsigned int pos = -1;
    pos = findMovie(db, key);
    if (pos != -1) {
        db.movies[pos].title = title;
        db.movies[pos].year = year;
        db.movies[pos].rating = rating;
    }
    else {
        cout << "Movie " << key << " not found!" << endl;
    }
        
}

void deleteMovie(movieDatabase& db, string key) {
    unsigned int pos = -1;
    pos = findMovie(db, key);
    if (pos != -1) {
        for (int i = pos; i < db.count; i++) db.movies[i] = db.movies[i + 1];
        db.count--;
    }
    else {
        cout << "Movie " << key << " not found!" << endl;
    }

}

void sortMovies(movieDatabase& db) {
    qsort(db.movies, db.count, sizeof(movie), compare);
}

void loadDatabase(movieDatabase& db) {
    ifstream file("movies.csv"); 
    string title;
    string yearString;
    string ratingString;

    unsigned short year;
    unsigned char rating;
    
    //reset the database
    db.count = 0;
    //skip the first line
    getline(file, title);

    while (file.good())
    {
        getline(file, title, ','); 
        getline(file, yearString, ',');
        getline(file, ratingString, '\n');

        year = stoi(yearString);
        rating = stoi(ratingString);

        addMovie(db, title, year, rating); 
    }
    cout << endl << "File loaded succesfully" << endl;
}
