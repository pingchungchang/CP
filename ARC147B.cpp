#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i = 1;i<=n;i++)cin>>arr[i];
    vector<pii> ans;
    vector<int> odev,evod;
    for(int i = 1;i<=n;i++){
        if(abs(i-arr[i])&1){
            if(arr[i]&1)odev.push_back(arr[i]);
            else evod.push_back(arr[i]);
        }
    }
    for(int i = 0;i<odev.size();i++){
        int p1 = 0;int p2 = 0;
        for(int j = 1;j<=n;j++){
            if(arr[j] == odev[i]){
                p1 = j;
            }
            else if(arr[j] == evod[i])p2 = j;
        }
        while(abs(p1-p2) != 1){
            if(p1>p2)swap(p1,p2);
            swap(arr[p2],arr[p2-2]);
            ans.push_back({2,p2-2});
            p2 -= 2;
        }
        if(p1>p2)swap(p1,p2);
        swap(arr[p1],arr[p2]);
        ans.push_back({1,p1});
    }
    // for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<endl;
    for(int i = 2;i<=n;i+=2){
        for(int j = 4;j<=n;j+=2){
            if(arr[j]<arr[j-2]){
                ans.push_back({2,j-2});
                swap(arr[j],arr[j-2]);
            }
        }
    }
    for(int i = 1;i<=n;i+=2)for(int j = 3;j<=n;j+=2){
        if(arr[j]<arr[j-2]){
            swap(arr[j],arr[j-2]);
            ans.push_back({2,j-2});
        }
    }
    cout<<ans.size()<<'\n';
    for(auto &i:ans){
        cout<<(char)('A'+i.fs-1)<<' '<<i.sc<<'\n';
    }
}