#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

class movieFestival {
    private:
        int startTime = 0, endTime = 0, answer = 0;
        void readValues(vector<pair<int, int>>& movies);
        void sortingMovies(vector<pair<int, int>>& movies);
        int showAnswers(int answer);
        void maximumMovies(vector<pair<int, int>>& movies);
    public:
        void caller(vector<pair<int, int>>& movies);
};

void movieFestival::maximumMovies(vector<pair<int, int>>& movies) {
    int currentMovie = movies[0].first;
    for (int i = 1; i < movies.size(); i++) {
        if (movies[i].second >= currentMovie) {
            currentMovie = movies[i].first;
            answer++;
        }
    } 
}

inline void movieFestival::sortingMovies(vector<pair<int, int>>& movies) {
    sort(movies.begin(), movies.end());
}

void movieFestival::readValues(vector<pair<int, int>>& movies) {
    for (int i = 0; i < movies.size(); i++) {
        cin >> startTime >> endTime;
        movies[i] = make_pair(startTime, endTime);
    }
}

inline int movieFestival::showAnswers(int answer) { return answer; }

inline void movieFestival::caller(vector<pair<int, int>>& movies) {
    readValues(movies);
    sortingMovies(movies);
    maximumMovies(movies);
    cout << showAnswers(answer) << "\n";
}

int main() {
    movieFestival test;
    int amoutOfMovies = 0;

    cin >> amoutOfMovies;

    vector<pair<int, int>> numbers(amoutOfMovies);

    test.caller(numbers);
}
