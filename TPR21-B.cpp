#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a<b)swap(a,b);
    while(b != 0){
        a %= b;
        swap(a,b);
    }
    return a;
}
int main(){
    int a,b;
    cin>>a>>b;
    for(int i = 2;i<= max(a,b);i++){
        if(a%i == b%i){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}
