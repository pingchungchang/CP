#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sig = 0;
    vector<string> s = {"","1"};
    for(int i = 0;i<43;i++){
        string k = s[i+1]+"*";
        string next;
        int c = 0;
        char now = k[0];
        for(int j = 0;j<k.size();j++){
            if(k[j] == now)c++;
            else{
                next += to_string(c);
                next += now;
                now = k[j];
                c = 1;
            }
        }
        s.push_back(next);
    }
    while(cin>>n){
        if(n == 0)return 0;
        if(sig != 0)cout<<'\n';
        else sig = 1;
        // cout<<s[n];
        cout<<s[n].size()<<' '<<fixed<<setprecision(6)<<(double)s[n-1].size()/(double)s[n].size();

    }
}