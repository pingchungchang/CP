#include <bits/stdc++.h>
using namespace std;


int arr[8][8];

int dfs(int x,vector<int> now){
    x += arr[now.size()-1][now.back()];
    int ans = 0;
    if(now.size() == 8){
        return x;
    }
    for(int i = 0;i<8;i++){
        bool flag = true;
        for(int j = 0;j<now.size();j++){
            if(now[j] == i||abs(now[j]-i) == abs((int)now.size()-j))flag = false;
        }
        if(flag == true){
            now.push_back(i);
            ans = max(ans,dfs(x,now));
            now.pop_back();
        }
    }
    return ans;
}
void solve(){
    for(int i = 0;i<8;i++)for(int j = 0;j<8;j++)cin>>arr[i][j];
    int ans = 0;
    for(int i = 0;i<8;i++)ans = max(ans,dfs(0,{i}));
    cout<<right<<setw(5)<<ans;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
        if(i != t-1)cout<<'\n';
    }
}
/*
73 68 61 19 25 67 27 97
94 79 35 51 63 33 71 44
92 80 23 34 10 24 68 59
24 76 49 10 47 19 96 39
89 28 96 45 79 84 4 19
3 97 72 62 2 40 26 66
99 98 11 80 43 75 77 46
85 28 27 17 27 75 57 67

574 vs 587
*/
