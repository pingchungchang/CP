#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    for(int i = 0;i<n;i++){
        char c;
        cin>>c;
        if(s.empty()||s.back() != c)s+=c;
    }
    cout<<s.size();
}