#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
}; 


template <class T>
bool compare(T p1, T p2){
    if(p1.score != p2.score){
        if(p1.score < p2.score)
            return true;
        else
            return false;
    } else {
        if(p1.name > p2.name)
            return true;
        else
            return false;
    }
}

void swap(std::vector<Player> &a, int idx){
    Player temp = a.at(idx);
    a.at(idx) = a.at(idx+1);
    a.at(idx+1) = temp;
    return;
}


void bSort(std::vector<Player> &a, int n) {
    for (int i = 0; i < n; i++) { 
        // Track number of elements swapped during a single array traversal
        int numberOfSwaps = 0;

        for (int j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order            
            if ( compare(a[j], a[j+1]) ){
                swap(a, j);
                numberOfSwaps++;
            }
        }

        // If no elements were swapped during a traversal, array is sorted
        if (numberOfSwaps == 0) {
            break;
        }
    }
    return;
}

vector<Player> comparator(vector<Player> players) { 
    bSort(players, players.size());
    return players;
}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}
