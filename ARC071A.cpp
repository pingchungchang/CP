#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    vector<int> chars(30,INT_MAX);
    for(int i = 0;i<n;i++){
        vector<int> all(30,0);
        for(auto c:v[i]){
            all[c-'a']++;
        }
        for(int j = 0;j<30;j++){
            chars[j] = min(chars[j],all[j]);
        }
    }
    string s;
    for(int i = 0;i<30;i++){
        for(int j = 0;j<chars[i];j++)s+= (char)('a'+i);
    }
    cout<<s;
}
