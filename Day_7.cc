#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>



bool req(unsigned long long wynik, std::vector<int> &a,char symbol,int i,unsigned long long sum,bool &bierz){
    if(wynik == sum && a.size()== i) {
    bierz=true;
    
    return true;
    }
    if(a.size()==i || wynik< sum) return false;

    if (symbol=='+') sum+=a[i];
    if(symbol == '*') sum*=a[i];
    if(symbol == '|') sum = std::stoll(std::to_string(sum)+std::to_string(a[i]));
    i++;
    req(wynik,a,'+',i,sum,bierz);
    req(wynik,a,'*',i,sum,bierz);
    req(wynik,a,'|',i,sum,bierz);
}



int main() {
    
unsigned long long calkowita=0;
std::ifstream file("cos.txt"); 
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file!" << std::endl;
        return 1;
    }

    
    unsigned long long b;
    std::vector<int> c;

    
    std::string line;
    while (std::getline(file, line)) {
      
        c.clear();
        b=0;

        
        std::istringstream iss(line);

       
        char colon;
        iss >> b >> colon;

        if (colon != ':') {
            std::cerr << "Error: Line format is incorrect!" << std::endl;
            continue;
        }

    
        int value;
        while (iss >> value) {
            c.push_back(value);
        }
        bool bierz = false;
        
        
        req(b,c,'+',0,0,bierz);
        req(b,c,'*',0,0,bierz);
        req(b,c,'|',0,0,bierz);
        if (bierz)  calkowita+=b;
        
    }

    file.close();
    

    std::cout<<calkowita;
}
