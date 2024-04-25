#include <bits/stdc++.h>
using namespace std;
//failed
string s;
int n;
bool f(int now){
    vector<int> v(s.size()+1,0);
    int tmp =0;
    for(int i = 0;i<=n-now;i++){
        tmp += v[i];
        if(s[i] == '1'&&tmp%2 == 0){
            v[i]++;
            tmp++;
            v[i+now]--;
        }
        else if(v[i] == '0'&&tmp%2 == 1){
            v[i]++;
            tmp++;
            v[i+now]--;
        }
    }
    cout<<now<<'\n';
    for(auto i:v)cout<<i<<' ';
    cout<<endl;
    tmp = 0;
    for(int i = 0;i<n;i++){
        tmp += v[i];
        if(s[i] == '0'&&tmp%2 == 1)return false;
        else if(v[i] =='1'&&tmp%2 == 0)return false;
    }
    return true;
}
int main(){
    cin>>s;
    n = s.size();
    int l = 1,r = s.size();
    while(l != r){
        int mid = (l+r+1)/2;
        if(f(mid))l = mid;
        else r = mid-1;
    }
    cout<<l;
}
