#include <bits/stdc++.h>
using namespace std;
bool Compare(vector<int> v1,vector<int> v2){
    if(v1[0]!= v2[0]){
        return v1[0]>v2[0];
    }
    else return v1[1]>v2[1];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> segments;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        segments.push_back({a,b});
    }
    sort(segments,begin(),segments.end(),Compare);
    unordered_map<int,int> used;
    vector<pair<int,int>> nodes;

}
