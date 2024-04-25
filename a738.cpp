#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    while(cin>>m>>n){
        if(n>m){
            int a = n;
            n=m;
            m=a;
        }
        while(m>=1&&n>=1){
            m-=n*(m/n);
            int a= m;
            m=n;
            n=a;
        }
        cout<<max(m,n)<<endl;
        
    }
}