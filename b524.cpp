#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        int ans = 0;
        queue<int> q;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'y') q.push(i);
        }
        for(int i = 0;i<s.size();i+=3){
            ans += max(i-q.front(),q.front()-i);
            q.pop();
        }
        cout<<ans<<endl;
    }
}
