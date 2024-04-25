#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int cnt = 0;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s == "For")cnt++;
        else cnt--;
    }
    if(cnt>0)cout<<"Yes";
    else cout<<"No";
    return 0;
}