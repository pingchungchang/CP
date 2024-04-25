#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    while(cin>>a>>b){
        vector<int> v(26,0);
        string ans;
        for(int i = 0;i<a.size();i++){
            v[a[i]-'a']++;
        }
        for(int i = 0;i<b.size();i++){
            if(v[b[i]-'a']>0){
                ans += b[i];
                v[b[i]-'a']--;
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
}
