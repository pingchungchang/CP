#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define pld pair<ld,ld>
#define ld long double

string in;
stringstream ss;
bool flag = false;

ld cross(pld a,pld b){
	return a.fs*b.sc-a.sc*b.fs>=0?1:-1;
}

pld dist(pld a,pld b){
	return {b.fs-a.fs,b.sc-a.sc};
}

inline bool inter(pld a,pld b,pld c,pld d){
	if(cross(dist(a,d),dist(a,b))*cross(dist(a,b),dist(a,c))>0&&
			cross(dist(c,a),dist(c,d))*cross(dist(c,d),dist(c,b))>0
			)return true;
	return false;
}

void solve(){
	if(in.empty())return;
	if(flag)cout<<'\n';
	flag = true;
	ss = stringstream(in);
	vector<pair<ld,ld>> v;
	ld x,y;
	string ix,iy;
	while(ss>>ix>>iy){
		x = stold(ix),y = stold(iy);
		v.push_back({x,y});
	}
	assert(v.size()>=3);
	pld now;
	getline(cin,in);
	ss = stringstream(in);
	ss>>now.fs>>now.sc;
	pld far = {now.fs,1e9};
	v.push_back(v[0]);
	int cnt = 0;
	for(int i = 1;i<v.size();i++){
		if(inter(now,far,v[i-1],v[i]))cnt++;
	}
	if(cnt&1)cout<<"Hit him";
	else cout<<"Stop";
	return;
}

int main(){
	while(getline(cin,in))solve();
}

