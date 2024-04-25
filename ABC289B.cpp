#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    int arr[n+1] = {};
    int con[n+1] = {};
    for(int i = 0;i<m;i++){
        int k;
        cin>>k;
        con[k] = 1;
    }
    vector<int> ans;
    for(int i = 1;i<=n;i++){
        while(i<=n&&con[i])i++;
        if(i>n)i = n;
        int p = i;
        // cout<<p<<endl;
        while(p>0&&!arr[p]){
            arr[p] = true;
            ans.push_back(p--);
        }
    }
    for(auto &i:ans)cout<<i<<' ';
}