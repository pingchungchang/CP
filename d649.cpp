#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)){
        string s;
        if(n == 0)return 0;
        for(int i =0;i<n;i++){
            s = s+"_";
        }
        for(int i = n-1;i>=0;i--){
            s[i] = '+';
            cout<<s<<'\n';
        }
    }
}