#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2020;
pll brr[mxn];
pair<pll,ll> arr[mxn];
int n,m;
vector<pair<ll,pll>> ev;
int match[mxn];
int cnt[mxn];
int sum = 0;

inline void add(int k){
	if(!cnt[k])sum++;
	cnt[k]++;
	return;
}
inline void del(int k){
	cnt[k]--;
	if(!cnt[k])sum--;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>arr[i].fs.fs>>arr[i].fs.sc>>arr[i].sc;
	for(int i = 1;i<=m;i++)cin>>brr[i].fs>>brr[i].sc;
	for(int i = 1;i<=m;i++){
		vector<pll> v;
		for(int j = 1;j<=n;j++){
			ll d = max(abs(arr[i].fs.fs-brr[j].fs),abs(arr[i].fs.sc-brr[j].sc));
			v.push_back(make_pair(d,j));
		}
		sort(v.begin(),v.end(),[](pll a,pll b){return a.fs == b.fs?arr[a.fs].sc>arr[b.fs].sc:a.fs<b.fs;});
		ll big = 0;
		for(auto &j:v){
			if(big>=arr[j.sc].sc)continue;
			else ev.push_back(make_pair(j.fs,make_pair(i,j.sc)));
			big = arr[j.sc].sc;
		}
	}
	sort(ev.begin(),ev.end());
	int t = 0;
	int ans = 0;
	for(auto &i:ev){
		int a = i.sc.fs,b = i.sc.sc;
		if(match[a]){
			del(match[a]);
		}
		add(match[a] = b);
		if(t != i.fs){
			ans = max(ans,sum);
		}
		t = i.fs;
	}
	ans = max(ans,sum);
	cout<<ans;
}
