#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int main(){
    int n;
    cin>>n;
    map<string,int>mp;
    vector<string> a(n);
    vector<string> b(n);
    for(int i = 0;i<n;i++){
        cin>>a[i]>>b[i];
        if(!mp.count(a[i]))mp[a[i]] = 1;
        else mp[a[i]]++;
        if(!mp.count(b[i]))mp[b[i]] = 1;
        else mp[b[i]]++;
    }
    for(int i = 0;i<n;i++){
        if(mp[a[i]] != 1&&mp[b[i]] != 1&&a[i] != b[i]){
            cout<<"No";
            return 0;
        }
        else if(mp[a[i]]>2&&a[i] == b[i]){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}
