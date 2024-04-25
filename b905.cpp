#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int now = 1;
    for(int i = 1;i<=n;i++){
        now *= i;
        while(now%10 == 0){
            now /=10;
        }
        now = now%100;
        cout<<i<<": "<<now%10<<endl;

    }
}
