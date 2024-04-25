#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    map<int,int> odd;
    map<int,int>even;
    for(int i = 0;i<n;i+=2){
        if(!odd.count(v[i]))odd[v[i]] = 1;
        else odd[v[i]]++;
    }
    for(int i = 1;i<n;i+=2){
        if(!even.count(v[i]))even[v[i]] = 1;
        else even[v[i]]++;
    }
    vector<pair<int,int>> odds;
    vector<pair<int,int>> evens;
    for(auto it:odd){
        odds.push_back(make_pair(it.second,it.first));
    }
    for(auto it:even){
        evens.push_back(make_pair(it.second,it.first));
    }
    sort(odds.rbegin(),odds.rend());
    sort(evens.rbegin(),evens.rend());
    odds.push_back(make_pair(0,-1));
    evens.push_back(make_pair(0,-1));
    if(odds[0].second != evens[0].second){
        cout<<n-odds[0].first-evens[0].first;
    }
    else{
        cout<<n-max(odds[0].first+evens[1].first,evens[0].first+odds[1].first);
    }
}
