#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>

const int bliks=25;
long long countDigit(long long n) { return floor(log10(n) + 1); }
int main(){
    
    std::vector<long long> starting ={};
    
    for(int i=0;i<bliks;i++){
        std::vector<long long> buffer;
    for(auto a:starting){
        if(a==0) {
            buffer.emplace_back(1);
            continue;
            }
        if(countDigit(a)%2 ==0){
                std::string s=std::to_string(a);
                std::string half = s.substr(0, s.length()/2);
                std::string otherHalf = s.substr(s.length()/2);
                buffer.emplace_back(stoll(half));
                buffer.emplace_back(stoll(otherHalf));
                continue;
        }
        buffer.emplace_back(a*2024);

    }
    starting=buffer;
    
    }
    std::cout<<starting.size();
}
