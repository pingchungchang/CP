#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fs first
#define sc second

struct point{
    ll x,y;
    point(){}
    point(ll a,ll b):x(a),y(b){}
    point operator+(point b){return point(x+b.x,y+b.y);}
    point operator-(point b){return (*this)+point(-b.x,-b.y);}
    ll operator^(point b){return x*b.y-y*b.x;}
    ll operator*(point b){return x*b.x+y*b.y;}
    bool operator<(point b)const{return x == b.x?y<b.y:x<b.x;}
};

const ll inf = 1e9+10;
vector<pair<point,int>> con;
int main(){
    int n;
    cin>>n;
    set<point> cc;
    for(int i = 0;i<n;i++){
        point tmp;
        cin>>tmp.x>>tmp.y;
        con.push_back({tmp,0});
        cc.insert(tmp);
    }
    pair<point,int> big = {point(-inf,-inf),-1},small = {point(inf,inf),inf};
    for(int i = 0;i<n;i++){
        big = max(big,make_pair(con[i].fs,i));
        small = min(small,make_pair(con[i].fs,i));
    }
    vector<pair<point,int>> up,down;
    bool flag = false;
    if(big.sc>small.sc)swap(big,small),flag = true;
    // cout<<big.fs.x<<' '<<big.fs.y<<','<<small.fs.x<<' '<<small.fs.y<<endl;
    for(int i = big.sc;i<=small.sc;i++)up.push_back(con[i]);
    for(int i = small.sc;i<n;i++)down.push_back(con[i]);
    for(int i = 0;i<=big.sc;i++)down.push_back(con[i]);
    if(flag)swap(up,down);
    int q;
    cin>>q;
    int req[q+1] = {};//0:in 1:on 2:out
    vector<pair<point,int>> ask;
    for(int i = 1;i<=q;i++){
        point tmp;
        cin>>tmp.x>>tmp.y;
        if(cc.find(tmp) != cc.end()){
            req[i] = 1;
        }
        else up.push_back({tmp,i}),down.push_back({tmp,i});
    }
    sort(up.rbegin(),up.rend());
    sort(down.begin(),down.end());
    con = up;
    vector<pair<point,int>> st;
    for(auto &now:con){
        if(now.sc != 0)ask.push_back(now);
        else{
            if(st.empty()){
                while(!ask.empty()){
                    req[ask.back().sc] = 2;
                    ask.pop_back();
                }
            }
            else{
                while(!ask.empty()){
                    auto tmp = ask.back();
                    ask.pop_back();
                    if(((now.fs-st.back().fs)^(tmp.fs-st.back().fs))<0)req[tmp.sc] = 2;
                    else if(((now.fs-st.back().fs)^(tmp.fs-st.back().fs))==0)req[tmp.sc] = 1;
                }
            }
            st.push_back(now);
        }
    }
    while(!ask.empty())req[ask.back().sc] = 2,ask.pop_back();
    st.clear();
    con = down;
    for(auto &now:con){
        if(now.sc != 0)ask.push_back(now);
        else{
            if(st.empty()){
                while(!ask.empty()){
                    req[ask.back().sc] = 2;
                    ask.pop_back();
                }
            }
            else{
                while(!ask.empty()){
                    auto tmp = ask.back();
                    ask.pop_back();
                    if(((now.fs-st.back().fs)^(tmp.fs-st.back().fs))<0)req[tmp.sc] = 2;
                    else if(((now.fs-st.back().fs)^(tmp.fs-st.back().fs))==0)req[tmp.sc] = 1;
                }
            }
            st.push_back(now);
        }
    }
    while(!ask.empty())req[ask.back().sc] = 2,ask.pop_back();
    for(int i = 1;i<=q;i++){
        if(req[i] == 1){
            cout<<"ON\n";
        }
        else if(req[i] == 2)cout<<"OUT\n";
        else cout<<"IN\n";
    }
    return 0;
}