#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin>>s){
        int ans =0;
        for(int i =0;i<s.size();i++){
            if(s[i]>='a'){
                ans += s[i]-'a'+1;
            }
            else ans += s[i]-'A'+1;
        }
        ans = ans%17;
        if(ans<=2)cout<<"D\n";
        else if(ans<=5)cout<<"C\n";
        else if(ans<=9)cout<<"B\n";
        else if(ans<=12)cout<<"A\n";
        else cout<<"SA\n";
    }
}
