#include <fstream>
#include <string>
#include <sstream>
ool cosikup(int x,int y,char(& b)[140][140],char next ){
    if(b[x][y]==next && next=='X'){
        next='M';
        if(y-1<0) return false;
        return cosikup(x,y-1,b,next);
    } 
    if(b[x][y]==next && next=='M'){
        next='A';
        if(y-1<0) return false;
        return cosikup(x,y-1,b,next);
    } 
    if(b[x][y]==next && next=='A'){
        next='S';
        if(y-1<0) return false;
        return cosikup(x,y-1,b,next);
    } 
    if(b[x][y]==next && next=='S'){
        return true;
    } 
    return false;
    
}
bool cosikdown(int x,int y,char(& b)[140][140],char next ){
    if(b[x][y]==next && next=='X'){
        next='M';
        if(y+1>139) return false;
        return cosikdown(x,y+1,b,next);
    } 
    if(b[x][y]==next && next=='M'){
        next='A';
        if(y+1>139) return false;
        return cosikdown(x,y+1,b,next);
    } 
    if(b[x][y]==next && next=='A'){
        next='S';
        if(y+1>139) return false;
        return cosikdown(x,y+1,b,next);
    } 
    if(b[x][y]==next && next=='S'){
        return true;
    } 
    return false;
    
}
bool cosikright(int x,int y,char(& b)[140][140],char next ){
    if(b[x][y]==next && next=='X'){
        next='M';
        if(x+1>139) return false;
        return cosikright(x+1,y,b,next);
    } 
    if(b[x][y]==next && next=='M'){
        next='A';
        if(x+1>139) return false;
        return cosikright(x+1,y,b,next);
    } 
    if(b[x][y]==next && next=='A'){
        next='S';
        if(x+1>139) return false;
        return cosikright(x+1,y,b,next);
    } 
    if(b[x][y]==next && next=='S'){
        return true;
    } 
    return false;
    
}
bool cosikleft(int x,int y,char(& b)[140][140],char next ){
    if(b[x][y]==next && next=='X'){
        next='M';
        if(x-1<0) return false;
        return cosikleft(x-1,y,b,next);
    } 
    if(b[x][y]==next && next=='M'){
        next='A';
        if(x-1<0) return false;
        return cosikleft(x-1,y,b,next);
    } 
    if(b[x][y]==next && next=='A'){
        next='S';
        if(x-1<0) return false;
        return cosikleft(x-1,y,b,next);
    } 
    if(b[x][y]==next && next=='S'){
        return true;
    } 
    return false;
    
}
bool cosikleftup(int x,int y,char(& b)[140][140],char next ){
    if(b[x][y]==next && next=='X'){
        next='M';
        if(x-1<0 || y-1<0) return false;
        return cosikleftup(x-1,y-1,b,next);
    } 
    if(b[x][y]==next && next=='M'){
        next='A';
        if(x-1<0 || y-1<0) return false;
        return cosikleftup(x-1,y-1,b,next);
    } 
    if(b[x][y]==next && next=='A'){
        next='S';
        if(x-1<0 || y-1<0) return false;
        return cosikleftup(x-1,y-1,b,next);
    } 
    if(b[x][y]==next && next=='S'){
        return true;
    } 
    return false;
    
}
bool cosikleftdown(int x,int y,char(& b)[140][140],char next ){
    if(b[x][y]==next && next=='X'){
        next='M';
        if(x-1<0 || y+1>139) return false;
        return cosikleftdown(x-1,y+1,b,next);
    } 
    if(b[x][y]==next && next=='M'){
        next='A';
        if(x-1<0 || y+1>139) return false;
        return cosikleftdown(x-1,y+1,b,next);
    } 
    if(b[x][y]==next && next=='A'){
        next='S';
       if(x-1<0 || y+1>139) return false;
        return cosikleftdown(x-1,y+1,b,next);
    } 
    if(b[x][y]==next && next=='S'){
        return true;
    } 
    return false;
    
}
bool cosikrightdown(int x,int y,char(& b)[140][140],char next ){
    if(b[x][y]==next && next=='X'){
        next='M';
        if(x+1>139 || y+1>139) return false;
        return cosikrightdown(x+1,y+1,b,next);
    } 
    if(b[x][y]==next && next=='M'){
        next='A';
        if(x+1>139 || y+1>139) return false;
        return cosikrightdown(x+1,y+1,b,next);
    } 
    if(b[x][y]==next && next=='A'){
        next='S';
       if(x+1>139 || y+1>139) return false;
        return cosikrightdown(x+1,y+1,b,next);
    } 
    if(b[x][y]==next && next=='S'){
        return true;
    } 
    return false;
    
}
bool cosikrightup(int x,int y,char(& b)[140][140],char next ){
    if(b[x][y]==next && next=='X'){
        next='M';
        if(x+1>139 || y-1<0) return false;
        return cosikrightup(x+1,y-1,b,next);
    } 
    if(b[x][y]==next && next=='M'){
        next='A';
        if(x+1>139 || y-1<0) return false;
        return cosikrightup(x+1,y-1,b,next);
    } 
    if(b[x][y]==next && next=='A'){
        next='S';
       if(x+1>139 || y-1<0) return false;
        return cosikrightup(x+1,y-1,b,next);
    } 
    if(b[x][y]==next && next=='S'){
        return true;
    } 
    return false;
    
}
bool xmas(int x,int y,char(& b)[140][140]){
    if(x-1<0 || x+1>139 ||y+1>139||y-1<0) return false;
    if (b[x-1][y-1]=='S' && b[x+1][y+1]=='M' && b[x+1][y-1]=='M' && b[x-1][y+1]=='S') return true; // SM
                                                                                                   // SM
    if (b[x-1][y-1]=='M' && b[x+1][y+1]=='S' && b[x+1][y-1]=='S' && b[x-1][y+1]=='M') return true;//MS 
                                                                                                  //MS
    if (b[x-1][y-1]=='M' && b[x+1][y+1]=='S' && b[x+1][y-1]=='M' && b[x-1][y+1]=='S') return true;//SS
                                                                                                  //MM
    if (b[x-1][y-1]=='S' && b[x+1][y+1]=='M' && b[x+1][y-1]=='S' && b[x-1][y+1]=='M') return true;//MM
     return false;                                                                                //SS
}
int main(){
    int sum=0;
    int com=0;
    char ch;
std::ifstream file("cos.txt");
char a[140][140];
int i=0,j=0;
while (file >> std::noskipws >> ch) {
    if(ch=='\n') {
        std::cout << ch; 
        j++;
        i=0;
        
    }
    else{
        a[i][j]=ch;
    i++; 
    std::cout << ch; 
    }// Or whatever
}
for(int k=0;k<140;k++){
    for(int l=0;l<140;l++){
        if(cosikup(l,k,a,'X'))sum++;
        if(cosikdown(l,k,a,'X'))sum++;
        if(cosikright(l,k,a,'X'))sum++;
        if(cosikleft(l,k,a,'X'))sum++;
        if(cosikleftup(l,k,a,'X'))sum++;
        if(cosikleftdown(l,k,a,'X'))sum++;
        if(cosikrightup(l,k,a,'X'))sum++;
        if(cosikrightdown(l,k,a,'X'))sum++;
        if(a[l][k]=='A' && xmas(l,k,a)) com++;
    }
}
std::cout<<std::endl<<sum<<std::endl<<com;
return 0;
}
