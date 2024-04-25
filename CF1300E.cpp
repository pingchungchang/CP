#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define ld long double
#define pld pair<ld,ld>

struct point{
	ll x,y;
	point(){}
	point(ll a,ll b):x(a),y(b){}
	point operator+(point b)const{
		return point(x+b.x,y+b.y);
	}
	point operator-(point b)const{
		return point(x-b.x,y-b.y);
	}
	ll operator*(point b)const{
		return x*b.x+y*b.y;
	}
	ll operator^(point b)const{
		return x*b.y-y*b.x;
	}
	bool operator<(point b)const{
		return x == b.x?y<b.y:x<b.x;
	}
};

const ll mxn = 1e6+10;
ll arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	vector<pld> v;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		ll tmp;
		cin>>tmp;
		ll C = 1;
		ld sum = tmp;
		while(!v.empty()&&v.back().fs>=sum/C){
			sum += v.back().fs*v.back().sc;
			C+=v.back().sc;
			v.pop_back();
		}
		v.push_back({sum/C,C});
	}
	for(auto &i:v)while(i.sc--)cout<<fixed<<setprecision(10)<<i.fs<<'\n';
}
