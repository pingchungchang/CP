#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,sse4")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll inf = 1e18;
const int mxn = 2e5+10;
int N,Q;


array<int,30> seg[mxn*2];
ll pref[30][mxn];

void modify(int p,int bit,int v){
	for(seg[p+=N][bit] = v;p>1;p>>=1){
		seg[p>>1][bit] = min(seg[p][bit],seg[p^1][bit]);
	}
	return;
}

array<int,30> getval(int s,int e){
	array<int,30> re;fill(re.begin(),re.end(),(int)2e9);
	for(s += N,e+=N;s<e;s>>=1,e>>=1){
		if(s&1){
			for(int i = 0;i<30;i++){
				re[i] = min(re[i],seg[s][i]);
			}
			s++;
		}
		if(e&1){
			e--;
			for(int i = 0;i<30;i++){
				re[i] = min(re[i],seg[e][i]);
			}
		}
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:seg)fill(i.begin(),i.end(),(int)2e9);
	cin>>N>>Q;
	for(int i = 1;i<=N;i++){
		int p;
		cin>>p;
		pref[__lg(p)][i] = p;
		modify(i,__lg(p),p);
	}
	for(int i = 0;i<30;i++){
		for(int j = 1;j<=N;j++){
			pref[i][j] += pref[i][j-1];
		}
	}
	while(Q--){
		int s,e;
		cin>>s>>e;
		ll sum = 0;
		auto re = getval(s,e+1);
		for(int i = 0;i<30;i++){
			if(sum+1>=re[i])sum += pref[i][e]-pref[i][s-1];
		}
		cout<<sum+1<<'\n';
	}
	return 0;
}
