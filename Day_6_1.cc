#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>

enum Direction {
    right,
    down,
    left,
    up
};
void move(std::pair<int, int>& position, Direction dir) {
    switch (dir) {
        case right:
            position.second += 1; 
            break;
        case left:
            position.second -= 1; 
            break;
        case down:
            position.first += 1; 
            break;
        case up:
            position.first -= 1; 
            break;
        default:
            std::cerr << "Invalid direction\n";
    }
}
void change_direction(Direction& dir) {
    dir = static_cast<Direction>((dir + 1) % 4);
}
int count_x(const std::vector<std::vector<char>>& charGrid) {
    int count = 0;
    for (const auto& row : charGrid) {
        for (const auto& ch : row) {
            if (ch == 'X') {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int sum = 0;
    int sum1 =0;
    
    std::vector<std::vector<char>> charGrid;


    std::ifstream file("cos.txt"); 
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

  
    std::string line;
    while (std::getline(file, line)) {
        
        std::vector<char> row;

        for (char c : line) {
            row.push_back(c);
        }

       
        charGrid.push_back(row);
    }

    file.close();

    // Display the 2D vector content
    std::cout << "File loaded into 2D vector:" << std::endl;
    for (const auto& row : charGrid) {
        for (char c : row) {
            std::cout << c; 
        }
        std::cout << std::endl; 
    }
    std::cout<<charGrid[0][4];
    std::pair<int,int> current_possition;
    char target = '^';
    for (size_t row = 0; row < charGrid.size(); ++row) {
       
        auto it = std::find(charGrid[row].begin(), charGrid[row].end(), target);

        if (it != charGrid[row].end()) {
          
            size_t col = std::distance(charGrid[row].begin(), it);

            std::cout << "Found '" << target << "' at row " << row << ", column " << col << std::endl;
            current_possition ={row,col};
            break; 
        }
    }
    std::pair<int,int> starting_possition=current_possition;
    Direction dirstr = up;
    std::pair<int,int> next_possition;
    Direction dir = up;
    bool after=false;
    
    while(true){
        next_possition=current_possition;
        if(charGrid[current_possition.first][current_possition.second]!='^') 
            charGrid[current_possition.first][current_possition.second]='X';
        else charGrid[current_possition.first][current_possition.second]='.';
        
        move(next_possition,dir);
        if(next_possition.first<0 || next_possition.first>129 || next_possition.second<0 || next_possition.second>129) 
        break;
        if(charGrid[next_possition.first][next_possition.second]=='#'){
            change_direction(dir);
            continue;
        }
        
        //if (starting_possition==current_possition && dir==up && after){
            //break;
        //}
        //sum++;
        move(current_possition,dir);
        //after=true;
        
     }
    
    
    
    

    
    int xCount = count_x(charGrid);
    std::cout<<'\n';
    std::cout<<xCount+1;
    std::cout<<'\n';
      for (const auto& row : charGrid) {
        for (char c : row) {
            std::cout << c; 
        }
        std::cout << std::endl; 
    }
    return 0;
}
