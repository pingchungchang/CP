#include <bits/stdc++.h>
using namespace std;

int highbit(int n){
    for(int i = 30;i>=0;i--){
        if((n&(1<<i))!= 0)return i;
    }
}
int main(){
    int n;
    cin>>n;
    int ans = 0;
    vector<int> v;
    while((1<<(highbit(n)+1))-1 != n){
        if(ans %2 == 0){
            v.push_back(highbit(n)+1);
            n = (n^((1<<(highbit(n)+1))-1));
        }
        else{
            n++;
        }
        ans++;
    }
    cout<<ans<<'\n';
    for(auto i:v)cout<<i<<' ';
}
