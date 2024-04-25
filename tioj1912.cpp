#include <bits/stdc++.h>
using namespace std;


int calc(int a,int b){
    a += b;
    while(a>=10){
        int ta = 0;
        while(a){
            ta += a%10;
            a/=10;
        }
        a = ta;
    }
    return a;
}
int main(){
    int n,r;
    cin>>n>>r;
    string s;
    cin>>s;
    vector<string> ans;
    int t = 0;
    for(auto &i:s)t += i-'0';
    while(t>=10){
        int tt = 0;
        while(t){
            tt += t%10;
            t/=10;
        }
        t = tt;
    }
    for(int i = 0;i<=9;i++){
        if(calc(i,t) == r){
            for(int j = 0;j<s.size();j++){
                ans.push_back(s.substr(0,j)+string(1,'0'+i)+s.substr(j,s.size()-j));
            }
            ans.push_back(s+string(1,'0'+i));
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(int i =1;i<ans.size()-1;i++)cout<<ans[i]<<'\n';
}