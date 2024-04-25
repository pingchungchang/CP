#include <bits/stdc++.h>
using namespace std;


bool cmp(string a,string b){
    return a.size()<b.size();
}
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    string s;
    cin>>s;
    int n = s.size();
    string tmp;
    vector<string> v;
    vector<string> odd;
    vector<string> even;
    int acnt = a+c+d,bcnt = b+c+d;
    for(auto i:s)(i== 'A'?acnt--:bcnt--);
    if(acnt != 0||bcnt != 0){
        cout<<"NO\n";
        return;
    }
    for(int i = 0;i<n;i++){
        if(tmp.empty()||tmp.back() != s[i])tmp += s[i];
        else{
            if(tmp.size()%2 == 0)even.push_back(tmp);
            else if(tmp.size()>1)odd.push_back(tmp);
            tmp = string(1,s[i]);
        }
    }
    if(!tmp.empty()&&tmp.size()>1){
        if(tmp.size()%2 == 1)odd.push_back(tmp);
        else even.push_back(tmp);
    }
    sort(even.begin(),even.end(),cmp);

    for(auto now:even){
        //cout<<now<<endl;
        if(now[0] == 'A'){
            if(c>=now.size()/2)c-= now.size()/2;
            else{
                int tmp = now.size()-c*2-1;
                c = 0;
                d -= tmp/2;
            }
        }
        else{
            if(d>=now.size()/2)d -= now.size()/2;
            else{
                int tmp = now.size()-d*2-1;
                d = 0;
                c -= tmp/2;
            }
        }
        if(c<0)c = 0;
        if(d<0)d = 0;
    }
    for(auto now:odd){
        //cout<<now<<endl;
        if(now[0] == 'A'){
            if(now.size()/2<=c){
                c -= now.size()/2;
            }
            else{
                int tmp = now.size()-c*2;
                c = 0;
                d -= tmp/2;
            }
        }
        else{
            if(now.size()/2<=d){
                d -= now.size()/2;
            }
            else{
                int tmp = now.size()-d*2;
                d = 0;
                c -= tmp/2;
            }
        }
        if(c<0)c = 0;
        if(d<0)d = 0;
    }
    if(c <= 0&&d <= 0)cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
