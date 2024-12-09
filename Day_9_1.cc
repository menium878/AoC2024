#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>




#include <cctype>
bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

std::vector<std::string> swapDotsWithLastDigit(std::vector<std::string> &input) {
    int lastDigitIndex = -1; 
    for (int i = input.size() - 1; i >= 0; --i) {
        if (is_number(input[i])) {
            lastDigitIndex = i;
            break;
        }
    }

    if (lastDigitIndex == -1) return input; 

    
    for (int i = 0; i < input.size(); ++i) {
        if (i > lastDigitIndex) 
        break;

        if (input[i] == "." ) {
           
            std::swap(input[i], input[lastDigitIndex]);

           
            --lastDigitIndex;
            while (lastDigitIndex >= 0 && !is_number(input[lastDigitIndex])) {
                --lastDigitIndex;
            }
        }
    }

    return input;
}

int main() {
    

std::ifstream file("cos.txt"); 
char ch;
    std::string line;
while(std::getline(file,line)){
}
std::string first1;
std::vector<std::string> first;
int count=0;
for (size_t i = 0; i < line.size(); i++)
{
    if(i%2==0){
        for(size_t k =0;k<(line[i]- '0');k++)
        first.emplace_back(std::to_string(count));
        count++;
        continue;
    }
    for(size_t k =0;k<(line[i]- '0');k++)
    first.emplace_back(".");
}


std::vector<std::string> end= swapDotsWithLastDigit(first);
long long sum=0;
for(auto a:end)
std::cout<<a;
for (int i = 0; i < end.size(); i++)
{
    if(end[i]!=".")
    sum+=i*stoi(end[i]);
}
std::cout<<std::endl<<sum;


    file.close();
    return 0;

}
