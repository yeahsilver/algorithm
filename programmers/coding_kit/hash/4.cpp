#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_multimap<string, pair<int, int> > map;

    for(int i = 0; i < genres.size(); i++) {
        map.insert(make_pair(genres[i], make_pair(plays[i], i)));
    }

    for(auto& genre: map) {
        cout << genre.first << '\t' << genre.second.first << '\t' << genre.second.second << '\n';
    }
    
    return answer;
}

int main(void) {
    vector<string> genres;
    genres.push_back("classic");
    genres.push_back("pop");
    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("pop");

    vector<int> plays;
    plays.push_back(500);
    plays.push_back(600);
    plays.push_back(150);
    plays.push_back(800);
    plays.push_back(2500);

    vector<int> result = solution(genres, plays);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\t';
    }
}