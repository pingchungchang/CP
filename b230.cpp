#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int,int> m;
    for(int i =1;i<65;i++){
        for(int j = i+1;j<65;j++){
            for(int k = j+1;k<65;k++){
                m[i*j+j*k+i*k] = 1;
            }
        }
    }
    int x;
    cin>>x;
    int n = 0;
    while(x>=1){
            n++;
        if(m.count(n) ==0){
            x--;
        }
    }
    printf("%d",n);
}