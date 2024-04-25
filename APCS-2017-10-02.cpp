#include <bits/stdc++.h>
using namespace std;

int main(){
    int now = 0;
    int ans= 0;
    int k;
    string s;
    cin>>k>>s;
    for(int i = 0;i<s.size();i++){
        int temp = 0;
        now = s[i]-'a'+1;
        for(int j = i;j<s.size();j++){
            if(temp%k==0&&temp!=0){
                now = -now;
            }
            if(now*(s[j]-'a'+1)>0){
                temp++;
            }
            else{
                temp = temp/k*k;
                ans = max(ans,temp);
                break;
            }
        }
    }
    if(ans==0&&k==1)ans=1;
    cout<<ans;
}