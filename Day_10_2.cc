#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
const int MAX_SIZE=52;
bool trail(char (&b)[MAX_SIZE][MAX_SIZE], int x, int y, char next, int &count)
{
    if(x<0||x>MAX_SIZE-1|| y<0|| y>MAX_SIZE-1) return false;
    if(b[x][y]!=next) return false;
    char c = b[x][y];
    if(b[x][y]==next && next=='9'){
        count++;
        return true;
    }

    trail(b, x - 1, y, next + 1, count);
    trail(b, x + 1, y, next + 1, count);
    trail(b, x, y - 1, next + 1, count);
    trail(b, x, y + 1, next + 1, count);

    return false;
}

int main()
{

    std::ifstream file("cos.txt");
    char ch;
    char a[MAX_SIZE][MAX_SIZE];
    int i = 0, j = 0,sum=0;
    while (file >> std::noskipws >> ch)
    {
        if (ch == '\n')
        {
            std::cout << ch;
            j++;
            i = 0;
        }
        else
        {
            a[i][j] = ch;
            i++;
            std::cout << ch;
        }
    }


    for (int k = 0; k < MAX_SIZE; k++)
    {
        for (int l = 0; l < MAX_SIZE; l++)
        {
            int traill=0;
            if(a[l][k]=='0'){
                trail(a,l,k,'0',traill);
                
                sum+=traill;
            }
        }
    }
    std::cout<<'\n'<<sum;
    file.close();
    return 0;
}
