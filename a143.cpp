#include <bits/stdc++.h>
using namespace std;

typedef long double ld;


int lcs(string a,string b){
    int n = a.size(),m = b.size();
    int ans = 0;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++){
        if(a[i-1] != b[j-1])dp[i][j] = 0;
        if(a[i-1] == b[j-1])dp[i][j] = dp[i-1][j-1]+1;
        ans = max(ans,dp[i][j]);
    }
    return ans;
}
bool cmp(pair<ld,int> a,pair<ld,int> b){
    if(abs(a.first-b.first)<=1e-7){
        return a.second<b.second;
    }
    else return a.first>b.first;
}
int main(){
    //string aa,bb;
    //cin>>aa>>bb;
    //cout<<lcs(aa,bb);
    //return 0;
    stringstream ss;
    string in;
    vector<string> allwords;
    getline(cin,in);
    ss<<in;
    while(ss>>in){
        allwords.push_back(in);
    }
    vector<pair<ld,int>> all;
    ss.clear();
    getline(cin,in);
    ss<<in;
    int k;
    ss>>k;
    bool flag = true;
    for(int i = 0;i<k;i++){
        getline(cin,in);
        ss.clear();
        ss<<in;
        int id;ss>>id;
        ld total = 0;
        while(ss>>in){
            ld tmp = 0;
            for(auto word:allwords){
                if(word == in){
                    tmp = 1.0;
                    break;
                }
                tmp = max(tmp,(ld)lcs(word,in)/word.size());
                if(abs(tmp -0)>= 1e-7)flag = false;
            }
            total += tmp;
        }
        all.push_back(make_pair((ld)round(total*100)/100.0,id));
    }
    sort(all.begin(),all.end(),cmp);
    //for(auto i:all)cout<<i.first<<' '<<i.second<<',';cout<<endl;
    if(flag){
        cout<<"FALSE";
        return 0;
    }
    for(auto i:all){
        cout<<i.second<<' ';
    }
}
/*
bbb bc
1
1 abc
asdf aaaaa
3
1 bce bbb
2 asd aaaa abcde
3 poipoi toitio
*/
