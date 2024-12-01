 #include <vector>
#include <algorithm>
 #include <iostream>
int main(){
std::vector<int> kot ={}; #left side input
std::vector<int> ala ={}; #right side
std::cout<<ala.size();
std::cout<<" "<<kot.size();
std::sort(ala.begin(),ala.end());
std::sort(kot.begin(),kot.end());
int odleglosc = 0;
for(int i=0;i<kot.size();i++){
    odleglosc+=::abs(ala[i]-kot[i]);
}

std::cout<<"\n";
std::cout<<odleglosc;
std::cout<<"\n";
int cood = 0;
for (int i=0;i<kot.size();i++){
    cood += kot[i]*(std::count(ala.begin(),ala.end(),kot[i]));
}
std::cout<<cood;
return 0;
}
