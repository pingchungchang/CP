#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> v(n+2,0);
    for(int i = 0;i<n;i++){
        int val = 0;
        if(s[i] == 'A')val = 1;
        else if(s[i] == 'B')val = 2;
        else if(s[i] == 'C')val = 4;
        v[i]|=val;
        v[i+1]|=val;
        v[i+2]|=val;
    }
    for(int i = 1;i<=n;i++){
        if(v[i] == 7){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
