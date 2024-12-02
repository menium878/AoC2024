#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>
 #include <iostream>
 #include <vector>
#include <algorithm>

// I know its shit but did the job the ugliest way possible 
bool comp(std::string a, std::string b) {
    return stoi(a) > stoi(b);
}
bool comp1(std::string a, std::string b) {
    return stoi(a) < stoi(b);
}

bool hasDuplicates(const std::vector<std::string>& vec) {
    std::unordered_set<std::string> seen;
    for (const auto& str : vec) {
        if (seen.find(str) != seen.end()) {
            return true; 
        }
        seen.insert(str);
    }
    return false; 
}
int main(){
    std::ifstream file("cos.txt");
    int k=0;
    
    std::string line;
    std::string s;
    if (file.is_open()) {
       
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
            std::stringstream ss(line);
            std::vector<std::string> v; 
            while (getline(ss, s, ' ')) {
                v.push_back(s);}
            auto isValid = [&v]() {
        return std::adjacent_find(v.begin(), v.end(), [](const std::string& a, const std::string& b) {
            int numA = std::stoi(a);
            int numB = std::stoi(b);
            int diff = abs(numB - numA);
            return diff < 1 || diff > 3; 
        }) == v.end(); 
    };
            if((std::is_sorted(v.begin(),v.end(),comp1)||std::is_sorted(v.begin(),v.end(),comp))&& !hasDuplicates(v) && isValid()) k++;
            else{
                std::vector<std::string> temp;
                for(int i=0;i<v.size();i++){
                    temp=v;
                    auto isValid1 = [&temp]() {
        return std::adjacent_find(temp.begin(), temp.end(), [](const std::string& a, const std::string& b) {
            int numA = std::stoi(a);
            int numB = std::stoi(b);
            int diff = abs(numB - numA);
            return diff < 1 || diff > 3; 
        }) == temp.end();
                    };
                    temp.erase(temp.begin() + i);
                    if((std::is_sorted(temp.begin(),temp.end(),comp1)||std::is_sorted(temp.begin(),temp.end(),comp))&& !hasDuplicates(temp) && isValid1()){
                        k++;
                        std::cout<<"cleared"<<std::endl;
                        break;
                        }
                }
            }
            std::cout<<k<<std::endl;
            
            
        }

        
        file.close();
    }
    else{
        std::cout<<"brak";
    }
return 0;
}
