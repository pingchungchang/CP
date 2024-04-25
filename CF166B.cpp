#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

struct point{
	ll x,y;
	bool col;
	point(){}
	point(ll a,ll b):x(a),y(b){}
	point operator+(point b){return point(x+b.x,y+b.y);}
	point operator-(point b){return (*this)+point(-b.x,-b.y);}
	ll operator*(point b){return x*b.x+y*b.y;}
	ll operator^(point b){return x*b.y-y*b.x;}
	bool operator<(point b)const{return x == b.x?y<b.y:x<b.x;}
};

void solve(){
	int n;
	cin>>n;
	vector<point> v;
	for(int i = 0;i<n;i++){
		point tmp;
		cin>>tmp.x>>tmp.y;
		tmp.col = 0;
		v.push_back(tmp);
	}
	int m;
	cin>>m;
	for(int i = 0;i<m;i++){
		point tmp;
		cin>>tmp.x>>tmp.y;
		tmp.col = 1;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	vector<point> up,down;
	for(auto &i:v){
		while(up.size()>=2&&((i-up.back())^(up[up.size()-2]-up.back()))>0)up.pop_back();
		up.push_back(i);
	}
	reverse(v.begin(),v.end());
	for(auto &i:v){
		while(down.size()>=2&&((i-down.back())^(down[down.size()-2]-down.back()))>0)down.pop_back();
		down.push_back(i);
	}
	bool flag = false;
	for(auto &i:up)flag |= i.col;
	for(auto &i:down)flag |= i.col;
	cout<<(flag?"NO":"YES");
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
