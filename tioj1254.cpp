#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

struct point{
	int x,y;
	point(int a,int b):x(a),y(b){}
	point(){
		x = y = 0;
	}
	point operator+(point b)const{
		return point(x+b.x,y+b.y);
	}
	point operator-(point b)const{
		return *this+point(-b.x,-b.y);
	}
	int operator*(point b)const{
		return x*b.x+y*b.y;
	}
	int operator^(point b)const{
		return x*b.y-y*b.x;
	}
	bool operator<(point b)const{
		return x == b.x?y<b.y:x<b.x;
	}
};

int n,m;

void solve(){
	if(!n&&!m)exit(0);
	vector<point> v;
	for(int i = 0;i<m;i++){
		point tmp;
		cin>>tmp.x>>tmp.y;
		v.push_back(tmp);
	}
	vector<point> up,down;
	sort(v.begin(),v.end());
	for(auto &i:v){
		while(up.size()>=2&&((up[up.size()-2]-up.back())^(i-up.back()))<0)up.pop_back();
		up.push_back(i);
	}
	reverse(v.begin(),v.end());
	for(auto &i:v){
		while(down.size()>=2&&((down[down.size()-2]-down.back())^(i-down.back()))<0)down.pop_back();
		down.push_back(i);
	}
	for(auto &i:down)up.push_back(i);
	int ans = 0;
	for(int i = 0;i<up.size();i++){
		for(int j = i+1;j<up.size();j++){
			point tmp = up[i]-up[j];
			ans = max(tmp.x*tmp.x+tmp.y*tmp.y,ans);
		}
	}
	int l = 0,r = 2023;
	while(l != r){
		int mid = (l+r)>>1;
		if(mid*mid*4>=ans)r = mid;
		else l = mid+1;
	}
	cout<<l<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n>>m)solve();
}
