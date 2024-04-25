#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define ll long long
#define tlll tuple<ld,ld,ld>
#define ld long double
#define pld pair<ld,ld>

struct Pt{
	ll x,y;
	Pt(ll xx = 0,ll yy = 0):x(xx),y(yy){}
	Pt operator+(Pt b)const{return Pt(x+b.x,y+b.y);}
	Pt operator-(Pt b)const{return Pt(x-b.x,y-b.y);}
	ll operator*(Pt b)const{return x*b.x+y*b.y;}
	ll operator^(Pt b)const{return x*b.y-y*b.x;}
	bool operator<(Pt b)const{return x==b.x?y<b.y:x<b.x;}
};

pld solve_eq(tlll a,tlll b){//solves ax+by = c
	auto [a1,b1,c1] = a;
	auto [a2,b2,c2] = b;
	ld d = a1*b2-b1*a2;
	ld dx = c1*b2-c2*b1;
	ld dy = a1*c2-a2*c1;
	return pld(dx/d,dy/d);
}

ld len(pld d){
	return sqrt(d.fs*d.fs+d.sc*d.sc);
}

pld dir[3][3];
ld theta[3];
vector<pld> lines[3];

void solve(){
	for(int i = 0;i<3;i++){
		lines[i].clear();
	}
	pld arr[3];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			dir[i][j] = pld(arr[j].fs-arr[i].fs,arr[j].sc-arr[i].sc);
		}
	}
	for(int i = 0;i<3;i++){
		vector<pld> v;
		for(int j = 0;j<3;j++){
			if(j == i)continue;
			v.push_back(dir[i][j]);
		}
		theta[i] = (v[0].fs*v[1].fs+v[0].sc*v[1].sc)/(len(v[0])*len(v[1]));
		theta[i] = acos(theta[i]);
	}
	for(int i = 0;i<3;i++){
		pld now = dir[i][(i+1)%3];
		ld t = theta[i]/3;
		ld c = cos(t),s = sin(t);
		lines[i].push_back(pld(now.fs*c-now.sc*s,now.fs*s+now.sc*c));
		now = lines[i].back();
		lines[i].push_back(pld(now.fs*c-now.sc*s,now.fs*s+now.sc*c));
		now = lines[i].back();
		lines[i].push_back(pld(now.fs*c-now.sc*s,now.fs*s+now.sc*c));
	}
	pld ans[3];
	for(int i = 0;i<3;i++){
		int nx = (i+1)%3,pre = (i+2)%3;

	auto [a,b] = solve_eq(tlll(lines[nx][0].fs,-lines[pre][1].fs,arr[pre].fs-arr[nx].fs),tlll(lines[nx][0].sc,-lines[pre][1].sc,arr[pre].sc-arr[nx].sc));
	ans[i].fs = arr[nx].fs+a*lines[nx][0].fs;
	ans[i].sc = arr[nx].sc+a*lines[nx][0].sc;

	}
	for(auto &i:ans)cout<<fixed<<setprecision(10)<<i.fs<<' '<<i.sc<<' ';
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}

