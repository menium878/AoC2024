#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


int main() {
    

std::ifstream file("cos.txt"); 
char ch;
    std::string line;
while(std::getline(file,line)){
}
//std::cout<<line;
std::string first;
int count=0;
for (size_t i = 0; i < line.size(); i++)
{
    if(i%2==0){
        for(size_t k =0;k<(line[i]- '0');k++)
        first+=(std::to_string(count));
        count++;
        continue;
    }
    for(size_t k =0;k<(line[i]- '0');k++)
    first+=".";
}
file.close();
return 0;
}
