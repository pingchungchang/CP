#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 505;
ll arr[mxn];

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        s = s.substr(2,s.size()-2);
        arr[i] = stoll(s);
    }
    int ans = 0;
    for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)for(int k = 0;k<n;k++)if(arr[i]+arr[j] == arr[k])ans++;
    cout<<ans<<endl;
}