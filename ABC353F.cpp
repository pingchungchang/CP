#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

ll K;

bool inbig(ll x,ll y){
	return (x/K+y/K)&1;
}

inline ll b2b(pll s,pll e){
	ll dx = abs(s.fs/K-e.fs/K),dy = abs(s.sc/K-e.sc/K);
	assert(inbig(s.fs,s.sc)&&inbig(e.fs,e.sc));
	if(dy>dx)swap(dx,dy);
	ll ans = 0;
	ans += dy*2;
	dx -= dy;
	assert(dx%2==0);
	if(dx)ans += min((dx/2)*(K+1),dx*2);
	return ans;
}

pll dir[] = {{0,1},{0,-1},{1,0},{-1,0}};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pll s,e;
	cin>>K>>s.fs>>s.sc>>e.fs>>e.sc;
	if(K == 1){
		cout<<abs(s.fs-e.fs)+abs(s.sc-e.sc)<<'\n';
		return 0;
	}
	s.fs += K*2,s.sc += K*2,e.fs += K*2,e.sc += K*2;
	if(inbig(s.fs,s.sc))swap(s,e);
	if(inbig(s.fs,s.sc)&&inbig(e.fs,e.sc)){
		cout<<b2b(s,e)<<'\n';
		return 0;
	}
	ll ans = 1e18;
	cerr<<s.fs<<' '<<s.sc<<' '<<e.fs<<' '<<e.sc<<endl<<endl;
	if(inbig(e.fs,e.sc)){
		ans = min(ans,b2b(pll(s.fs-K,s.sc),e)+s.fs%K+1);
		ans = min(ans,b2b(pll(s.fs+K,s.sc),e)+K-s.fs%K);
		ans = min(ans,b2b(pll(s.fs,s.sc-K),e)+s.sc%K+1);
		ans = min(ans,b2b(pll(s.fs,s.sc+K),e)+K-s.sc%K);
	}
	else{
		for(auto d1:dir){
			ll tval = 0;
			if(d1.fs == -1)tval += s.fs%K+1;
			else if(d1.fs == 1)tval += K-s.fs%K;
			else if(d1.sc == -1)tval += s.sc%K+1;
			else if(d1.sc == 1)tval += K-s.sc%K;
			for(auto d2:dir){
				ll tmp = tval;
				if(d2.fs == -1)tmp += e.fs%K+1;
				else if(d2.fs == 1)tmp += K-e.fs%K;
				else if(d2.sc == -1)tmp += e.sc%K+1;
				else if(d2.sc == 1)tmp += K-e.sc%K;
				cerr<<d1.fs<<' '<<d1.sc<<' '<<d2.fs<<' '<<d2.sc<<' '<<tmp<<endl;
				tmp += b2b(pll(s.fs+K*d1.fs,s.sc+K*d1.sc),pll(e.fs+K*d2.fs,e.sc+K*d2.sc));
				cerr<<tmp<<endl<<endl;
				ans = min(ans,tmp);
			}
		}
	}
	ans = min(ans,abs(s.fs-e.fs)+abs(s.sc-e.sc));
	cout<<ans<<'\n';
	return 0;
}
