#include <bits/stdc++.h>
using namespace std;

#define ll long long

int f(int tar){
    int re = 0;
    while(tar%3 == 0){
        re++;
        tar/=3;
    }
    while(tar%2 == 0){
        re++;
        tar /=2;
    }
    if(tar != 1)return -1;
    return re;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int G = arr[0];
    for(auto &i:arr)G = __gcd(G,i);
    int cnt = 0;
    for(auto &i:arr){
        if(f(i/G) != -1){
            cnt += f(i/G);
        }
        else{
            cout<<-1;
            return 0;
        }
    }
    cout<<cnt;
}