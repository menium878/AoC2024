#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>


#include <cctype>
bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}


std::vector<std::string> swapDotsWithLastDigit(std::vector<std::string> &input) {
    std::unordered_map<std::string, size_t> counts;
    for (auto v : input){
    if(v==".")continue;
    ++counts[v];
    }
    
    int lastDigitIndex = -1; 
    do 
    {
        int i = 0;
         int zlicz=0;
    
    
    for (int z = input.size() - 1; z >= 0; --z) {
        if (is_number(input[z]) &&  counts[input[z]]!=0) {
            lastDigitIndex = z;
            break;
        }
    }

    int internalcount =counts[input[lastDigitIndex]];
    std::string thenumber=input[lastDigitIndex];
    int j;
    do 
    {
        zlicz=0;
        for (i; i < input.size(); ++i){
        if(input[i]==".")break;
    }
    j=i;
    for (i; i < input.size(); ++i){
        if(input[i]=="."){
            zlicz++;
            continue;
        }
        break;
    }
     if(lastDigitIndex-(internalcount-1)<i) 
         goto kot;
    }while((internalcount>zlicz));
    
    for(j;j<i;j++){
        if(internalcount==0) break;
        input[j] =thenumber;
        input[lastDigitIndex-(internalcount-1)] =".";
        internalcount--;
    }

    kot:
    counts.erase(thenumber);
    if(thenumber=="1") break;
    }while(true);
    


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
