#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    unordered_map<string,int> m;
    while(getline(cin,s)){
        if(m.count(s)) cout<<"YES";
        else{
            m[s] = 1;
            cout<<"NO"
        }
        cout<<endl;
    }
}
