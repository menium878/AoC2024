#include <fstream>
#include <iostream>
#include <vector>
#include <set>

const int MAX_SIZE = 52;


void exploreTrail(char (&b)[MAX_SIZE][MAX_SIZE], int x, int y, char next, std::set<std::pair<int, int>> &reachable9, bool (&visited)[MAX_SIZE][MAX_SIZE]) {
    
    if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE) return;         
    if (visited[x][y]) return;                                            
    if (b[x][y] != next) return;                                          

   
    if (b[x][y] == '9') {
        reachable9.insert({x, y});
        return;
    }

   
    visited[x][y] = true;

   
    exploreTrail(b, x - 1, y, next + 1, reachable9, visited); // Up
    exploreTrail(b, x + 1, y, next + 1, reachable9, visited); // Down
    exploreTrail(b, x, y - 1, next + 1, reachable9, visited); // Left
    exploreTrail(b, x, y + 1, next + 1, reachable9, visited); // Right

   
    visited[x][y] = false;
}

int main() {
    std::ifstream file("cos.txt");
    if (!file) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }

    char ch;
    char a[MAX_SIZE][MAX_SIZE] = {{0}};
    int i = 0, j = 0;

    
    while (file >> std::noskipws >> ch) {
        if (ch == '\n') {
            j++;
            i = 0;
        } else {
            a[i][j] = ch;
            i++;
        }
    }
    file.close();

    int totalScore = 0;

    
    for (int k = 0; k < MAX_SIZE; k++) {
        for (int l = 0; l < MAX_SIZE; l++) {
            if (a[l][k] == '0') {
                
                std::set<std::pair<int, int>> reachable9; 
                bool visited[MAX_SIZE][MAX_SIZE] = {{false}};

                exploreTrail(a, l, k, '0', reachable9, visited);

               
                totalScore += reachable9.size();
            }
        }
    }

    std::cout << "Total Score: " << totalScore << std::endl;
    return 0;
}
