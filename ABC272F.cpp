#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

struct node{
	int r1,r2,r3;
	int id;
	node(){}
	node(int a,int b,int c,int d){
		r1 = a,r2 = b,r3 = c;
		id = d;
	}
};
const ll mxn = 4e5+10;
string s,t;
node rnk[mxn];
int n;
node buf[mxn];
vector<ll> re[mxn];
vector<node> v[mxn];
void bucket_sort(int d){
	for(int i = 0;i<n;i++){
		rnk[i].r2 = rnk[(i+d>=n?i+d-n:i+d)].r1;
		v[rnk[i].r2].push_back(rnk[i]);
	}
	for(int i = n;i<n*2;i++){
		rnk[i].r2 = rnk[(i+d>=n*2?i+d-n:i+d)].r1;
		v[rnk[i].r2].push_back(rnk[i]);
	}
	int p = 0;
	for(auto &i:v){
		for(auto &j:i){
			buf[p++] = j;
		}
		i.clear();
	}
	for(int i = 0;i<p;i++){
		v[buf[i].r1].push_back(buf[i]);
	}
	p = 0;
	node pre(-1,-1,-1,-1);
	for(auto &i:v){
		for(auto &j:i){
			if(j.r1 == pre.r1&&j.r2 == pre.r2)rnk[j.id].r1 = p;
			else{
				p++;
				rnk[j.id].r1 = p;
			}
		}
		i.clear();
	}
	return;
}
int main(){
	io
	cin>>n;
	cin>>s>>t;
	
	for(int i = 0;i<n;i++){
		rnk[i] = node(s[i]-'a',0,0,i);
	}
	for(int i = n;i<n*2;i++){
		rnk[i] = node(t[i-n]-'a',0,1,i);
	}
	for(ll i = 1;i<n;i<<=1){
		bucket_sort(i);
	}
	ll cnt = n;
	for(int i = 0;i<n*2;i++){
		re[rnk[i].r1].push_back(rnk[i].r3);
	}
	
	ll ans = 0;
	for(auto &i:re){
		for(auto &j:i){
			if(j == 1)cnt--;
			else ans += cnt;
//			cout<<j;
		}
	}
	cout<<ans;
}

