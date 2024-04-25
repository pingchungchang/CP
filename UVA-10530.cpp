#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    string num;
    int b = 10;
    int l = 0;
    while(getline(cin,num)){
        if(num == "0")return 0;
        int n = stoi(num);
        string s;
        getline(cin,s);
        if(s == "right on"){
            if(l<=n&&n<=b)printf("Stan may be honest\n");
            else{
                printf("Stan is dishonest\n");
            }
            b = 10;
            l = 1;
        }
        else if(s == "too high"){
            b = min(n-1,b);
        }
        else{
            l = max(l,n+1);
        }
    }
}