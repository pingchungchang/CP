#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(int i =0;i<t;i++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans = -1;
        for(int j =1;j<n&&ans == -1;j++){
            if(s[j-1]-'a'+s[j]-'b'==0)ans = j;
        }
        if(ans ==-1)cout<<"-1 -1\n";
        else cout<<ans<<' '<<ans+1<<'\n';

    }
}
