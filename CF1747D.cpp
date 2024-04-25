#include <bits/stdc++.h>
using namespace std;


map<int,vector<int>> mp[2];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    int arr[n+1] = {};
    long long total[n+1];
    total[0] = 0;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        total[i] = total[i-1]+arr[i];
        arr[i] ^= arr[i-1];
        mp[i&1][arr[i]].push_back(i);
    }
    // for(int i = 0;i<=n;i++)cout<<arr[i]<<' ';cout<<endl;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(arr[b]^arr[a-1]){
            cout<<"-1\n";
            continue;
        }
        else if(total[b] == total[a-1]){
            cout<<"0\n";
            continue;
        }
        else if((b-a+1)&1){
            cout<<"1\n";
            continue;
        }
        else if((arr[a]^arr[a-1]) == 0||(arr[b]^arr[b-1]) == 0){
            cout<<"1\n";
            continue;
        }
        else{
            bool flag = false;
            int pos = upper_bound(mp[a&1][arr[a-1]].begin(),mp[a&1][arr[a-1]].end(),a)-mp[a&1][arr[a-1]].begin();
            // cout<<mp[(a+1)&1][arr[a-1]][pos]<<','<<endl;
            if(pos != mp[a&1][arr[a-1]].size()&&mp[a&1][arr[a-1]][pos]<=b)flag = true;
        pos = upper_bound(mp[(b+1)&1][arr[b]].begin(),mp[(b+1)&1][arr[b]].end(),b)-mp[(b+1)&1][arr[b]].begin();
            pos--;
            if(pos>=0&&mp[(b+1)&1][arr[b]][pos] >= a)flag = true;
            if(flag){
                cout<<"2\n";
                continue;
            }
            else cout<<"-1\n";
            continue;
        }
    }
}