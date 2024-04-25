#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = 0;
    vector<string> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
        for(int j= 1;j<v[i].size();j++){
            if(v[i].substr(j-1,2) == "AB")ans++;
        }
    }
    vector<int> type(3,0);
    for(auto i:v){
        if(*i.begin() == 'B'&&*i.rbegin() == 'A')type[2]++;
        else if(*i.begin() == 'B')type[1]++;
        else if(*i.rbegin() == 'A')type[0]++;
    }
    //0:...A;  1: B....,  2: B...A
    if(type[1] != 0&&type[0] != 0){
        ans += min(type[0],type[1])+type[2];
    }
    else{
        ans += max(0,type[2]-1+(type[0]!= 0||type[1] != 0?1:0));
    }
    cout<<ans;
}
