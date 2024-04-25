#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> multiply(vector<vector<long long>> v1,vector<vector<long long>> v2){
    vector<vector<long long>> ans(2,vector<long long>(2,0));
    ans[0][0] = (v1[0][0]*v2[0][0]+v1[0][1]*v2[1][0])%100000007;
    ans[0][1] = (v1[0][0]*v2[1][0]+v1[0][1]*v2[1][1])%100000007;
    ans[1][0] = (v1[1][0]*v2[0][0]+v1[1][1]*v2[1][0])%100000007;
    ans[1][1] = (v1[1][0]*v2[1][0]+v1[1][1]*v2[1][1])%100000007;
    return ans;
}

int main(){
    int m,f,c;
    while(cin>>m>>f>>c){
        vector<vector<long long>> unit = {{1,1},{1,0}};
        vector<vector<long long>> ans = {{1,0},{0,1}};
        while(c != 0){
            if(c&1){
                ans = multiply(unit,ans);
            }
            unit = multiply(unit,unit);
            c = c>>1;
        }
        cout<<(f*(ans[0][0]+ans[1][0])+m*(ans[0][1]+ans[1][1]))%100000007<<endl;
    }
}
