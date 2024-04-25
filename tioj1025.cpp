#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;

void solve(vector<int> arr,queue<int> q){
    if(!q.empty()){
        int now = q.front();
        q.pop();
        int used[10]={0};
        for(int i = now%9;i<81;i+=9){
            used[arr[i]] = 1;
        }
        for(int i = (now/9)*9;i<(now/9)*9+9;i++){
            used[arr[i]] = 1;
        }
        for(int j = now%9/3*3;j<now%9/3*3+3;j++){
            for(int i = (now/27)*27;i<(now/27)*27+27;i+=9){
                used[arr[i+j]] = 1;
            }
        }
        for(int i = 1;i<10;i++){
            if(used[i] ==0){
                arr[now] = i;
                solve(arr,q);
            }
        }
        return;
    }
    else ans.push_back(arr);
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr(81,0);
    queue<int> q;
    for(int i =0;i<81;i++){
        int k;
        cin>>k;
        if(k == 0)q.push(i);
        arr[i] = k;
    }
    solve(arr,q);
    for(int i =0;i<ans.size();i++){
        for(int j =0;j<9;j++){
            for(int k =0;k<9;k++){
                cout<<ans[i][9*j+k];
                if(k != 8)cout<<' ';
            }
            if(j != 8)cout<<'\n';
        }
        cout<<"\n\n";
    }
    cout<<"there are a total of "<<ans.size()<<" solution(s).";
}