#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include<unordered_map>

int main() {
    
std::ifstream file("cos.txt"); 

    
char a[50][50];
int i=0,j=0;
char ch;
std::unordered_map<char, std::vector<std::pair<int, int>>> lol;
std::vector<std::pair<int,int>> all_A;
std::vector<std::pair<int,int>> all_0;
std::vector<char> ace;
while (file >> std::noskipws >> ch) {
    if(ch=='\n') {
        std::cout << ch; 
        j++;
        i=0;
        
    }
    else{
        if(ch!='.'){
        lol[ch].emplace_back((int)i,(int)j);
        ace.emplace_back(ch);
        }
        a[i][j]=ch;
        
    i++; 
    std::cout << ch; 
    }
}
int cosik=0;

for(auto tro:lol)
{
   
    for(int x=0;x<tro.second.size();x++){
        for(int z=0;z<tro.second.size();z++){
            if(x==z) continue;
            bool boo=false;
            int raz=1;
            while (true)
            {
                
        
            int dx=(tro.second[x].first-tro.second[z].first)*raz;
            int dy=(tro.second[x].second-tro.second[z].second)*raz;
            raz++;
            if((tro.second[x].first+dx) <0 || (tro.second[x].first+dx)>49|| (tro.second[x].second+dy) <0 || (tro.second[x].first+dx)>49 ||(tro.second[x].second+dy)>49 || (tro.second[x].first+dx) <0 || (tro.second[x].second+dy) <0 ||(tro.second[x].second+dy)>49) 
            {
                
            break;
            
            }
            a[tro.second[x].first+dx][tro.second[x].second+dy]='#';
            
            }
        }
    }
}

   
    std::cout<<'\n';
    for(int k=0;k<50;k++){
        for(int p=0;p<50;p++){
            if(a[p][k]=='#' || std::find(ace.begin(), ace.end(), a[p][k])!= ace.end()) cosik++;   
            std::cout<<a[p][k];
        }
        std::cout<<'\n';
    }
    std::cout<<cosik;
    //<12;
    file.close();
    



    
    
    
    
}
