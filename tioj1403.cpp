#include <bits/stdc++.h>
using namespace std;

#define tlll tuple<ll,ll,ll>
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define ld long double

const int mxn = 250010;
const int big = 10000;
ll speed[mxn],dist[mxn];

auto cmp = [](pll a,pll b){
	ll ta = (dist[a.sc]-dist[a.fs])*(speed[b.fs]-speed[b.sc]);
	ll tb = (dist[b.sc]-dist[b.fs])*(speed[a.fs]-speed[a.sc]);
	if(ta == tb){
		auto tta = ((ld)(dist[a.sc]-dist[a.fs]))/(speed[a.fs]-speed[a.sc])*speed[a.fs]+dist[a.fs];
		auto ttb = ((ld)(dist[b.sc]-dist[b.fs]))/(speed[b.fs]-speed[b.sc])*speed[b.fs]+dist[b.fs];
		//cout<<fixed<<setprecision(10)<<a.fs<<' '<<a.sc<<":"<<speed[a.fs]<<' '<<speed[a.sc]<<';'<<b.fs<<','<<b.sc<<':'<<ttb<<endl;
		return ((ld)(dist[a.sc]-dist[a.fs]))/(speed[a.fs]-speed[a.sc])*speed[a.fs]+dist[a.fs]<
			((ld)(dist[b.sc]-dist[b.fs]))/(speed[b.fs]-speed[b.sc])*speed[b.fs]+dist[b.fs];
	}
	else return ta<tb;
	//dist[a.sc]-dist[a.fs])/speed[a.fs]-speed[a.sc]*speed[a.fs]+dist[a.fs];
	//dist[b.sc]-dist[b.fs])/speed[b.fs]-speed[b.sc]*speed[b.fs]+dist[b.fs];
};

priority_queue<pll,vector<pll>,decltype(cmp)> pq(cmp);
deque<int> dq[110];
ll cnt[110];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		cin>>dist[i]>>speed[i];
		for(int j = speed[i]+1;j<=100;j++)ans += cnt[j];
		for(int j = speed[i]+1;j<=100;j++){
			for(auto &k:dq[j]){
				if(pq.size()<big){
					pq.push({k,i});
				}
				else if(cmp(pq.top(),make_pair(k,j)))break;
				else pq.push({k,i});
			}
			while(pq.size()>big)pq.pop();
		}
		cnt[speed[i]]++;
		dq[speed[i]].push_front(i);
	}
	vector<pll> v;
	while(!pq.empty())v.push_back(pq.top()),pq.pop();
	reverse(v.begin(),v.end());
	assert(ans<1000000);
	cout<<ans%1000000<<'\n';
	for(int i = 0;i<min((int)v.size(),big);i++)cout<<v[i].fs<<' '<<v[i].sc<<'\n';
	return 0;
	for(int i = 0;i<v.size();i++){
		for(int j = 0;j<v.size();j++){
			if(i == j)cout<<"-"<<' ';
			else cout<<cmp(v[i],v[j])<<' ';
		}
		cout<<endl;
	}
}
