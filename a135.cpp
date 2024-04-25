#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

vector<string>all;
list<vector<string>> lst;
int k;

bool match(vector<string> cp){
    k = cp.size();
    for(int a= 0;a<3;a++)for(int b = 0;b<=3-k;b++){
        bool flag = true;
        for(int c = 0;c<k;c++)for(int d = 0;d<2;d++){
            if(all[3*a+b+c][d] != cp[c][d]&&cp[c][d] != '?')flag = false;
        }
        if(flag){
            return true;
        }
    }
    return false;
}
int main(){
    string s1 = "BPY";
    string s2 = "CST";
    for(auto i:s1){
        for(auto j:s2){
            all.push_back(string(1,i)+j);
        }
    }
    sort(all.begin(),all.end());
    int n;
    cin>>n;
    vector<vector<string>> cp;
    for(int i = 0;i<n;i++){
        cin>>k;
        vector<string>tmp;
        for(int j = 0;j<k;j++){
            char a,b;
            cin>>a>>b;
            tmp.push_back(string(1,a)+b);
        }
        cp.push_back(tmp);
    }
    sort(cp.begin(),cp.end());
    cp.erase(unique(cp.begin(),cp.end()),cp.end());

    int ans = 0;
    bool flag = true;
    for(auto it:cp){
        flag = flag &&(match(it));
    }
    if(flag)ans++;
    while(next_permutation(all.begin(),all.end())){
        flag = true;
        for(auto i:cp)flag = flag&&match(i);
        if(flag)ans++;
    }
    cout<<ans;
}
