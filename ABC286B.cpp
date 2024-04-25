#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    vector<int> change;
    for(int i = 1;i<n;i++){
        if(s[i-1] == 'n'&&s[i] == 'a')change.push_back(i-1);
    }
    for(int i = change.size()-1;i>=0;i--){
        s = s.substr(0,change[i]+1)+"y"+s.substr(change[i]+1,s.size()-change[i]-1);
    }
    cout<<s;
}