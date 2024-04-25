#include <bits/stdc++.h>
using namespace std;

int main(){
    int h1,m1,h2,m2;
    cin>>h1>>m1>>h2>>m2;
    if(m1>m2){
        h2--;
        m2+=60;
    }
    if(h2-h1 == -1){
        h2+=24;
    }
    else if(h2-h1==-24){
        h2+= 24;
    }
    cout<<h2-h1<<' '<<m2-m1;
}