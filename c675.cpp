#include <bits/stdc++.h>
using namespace std;

int main(){
    char c;
    string s;
    vector<char> words = {'0','1','2','3','5','6','7','8','9'};
    while(cin>>c>>s){
        if(c == 'F'){
            int nines = 1;
            int ans = 0;
            for(int i = s.size()-1;i>=0;i--){
                if(s[i]>'4')s[i]--;
                ans +=(s[i]-'0')*nines;
                nines *=9;
            }
            cout<<ans<<endl;
        }
        else{
            string ans;
            int n = stoi(s);
            while(n>0){
                ans = words[n%9]+ans;
                n /= 9;
            }
            cout<<ans<<endl;
        }
    }
}