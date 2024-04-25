#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n = 0;
    cin>>s;
    int now = 0;
    int alpha = 1;
    for(int i =s.size()-1;i>=0;i--){
        if(s[i]-'0'>=0&&s[i]-'9'<=0)continue;
        else if(n == 0){
            string k = s.substr(i+1,s.size()-i-1);
            n = stoi(k);
        }
        now += alpha *(s[i]-'A'+1);
        alpha *= 26;
    }
    cout<<now*n;
}