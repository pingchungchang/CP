#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i =0;i<n;i++){
        int j;
        cin>>j;
        v.push_back(j);
    }
    int ans = 0;
    unordered_map<int,int> used;
    for(int i =0;i<n;i++){
        used[v[i]] = 1;
        if(used.count(v[i]-m) !=0) ans++;
        if(used.count(v[i]+m) !=0) ans++;
    }
    cout<<ans;
}
