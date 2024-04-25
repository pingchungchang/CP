#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(30001,0);
    unordered_map<int,vector<int>> m;
    int biggest = 0;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        v[k]++;
        m[v[k]].push_back(k);
        biggest = max(v[k],biggest);
    }
    sort(m[biggest].begin(),m[biggest].end());
    for(int i = 0;i<m[biggest].size();i++){
        printf("%d %d\n",m[biggest][i],biggest);
    }
}