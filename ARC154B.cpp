#include <bits/stdc++.h>
using namespace std;

int n;
string a,b;
bool f(int x){
    for(auto &i:b){
        if(x != n&&i == a[x])x++;
    }
    if(x == n)return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>a>>b;
    int l = 0,r = n;
    int cnt[26] = {};
    for(auto &i:a)cnt[i-'a']++;
    for(auto &i:b)cnt[i-'a']--;
    for(auto &i:cnt)if(i != 0){
        cout<<-1;
        return 0;
    }
    while(l != r){
        int mid = (l+r)>>1;
        if(f(mid))r = mid;
        else l = mid+1;
    }
    cout<<l;
}