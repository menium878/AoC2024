#include <fstream>
#include <string>
#include <regex>
 #include <iostream>
int main(){
    std::ifstream file("cos.txt");
    int k=0;
    
    std::string line;
    std::string s;
    int a=0;
    bool b=true;
    if (file.is_open()) {
       
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
            
        std::cout << std::endl;

            std::regex exp("mul\\(([0-9]+),([0-9]+)\\)|do\\(\\)|don't\\(\\)");
    std::smatch res;
    

    std::string::const_iterator searchStart( line.cbegin() );
    while ( regex_search( searchStart, line.cend(), res, exp ) )
    {
        std::cout << ( searchStart == line.cbegin() ? "" : " " ) << res[0]; 
        if(res[0]=="do()")  {
            b=true;
            searchStart = res.suffix().first;
            continue;
        }
        if(res[0]=="don't()")  {
            b=false;
            searchStart = res.suffix().first;
            continue;
        }
        if(b)a+=stoi(res[1])*stoi(res[2]);
        searchStart = res.suffix().first;
    }
    std::cout << std::endl;
        }

        std::cout<<a;
        file.close();
    }
    else{
        std::cout<<"brak";
    }
return 0;
}
