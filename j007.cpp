
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
const ll mxn = 4e5+10;
pair<ll,pll> ans = {1e9,{1e9,1e9}};
int cnt[mxn];
vector<ll> all;
vector<pll> pos[mxn];//first:right,second:index
vector<pii> head[mxn],tail[mxn];
bool cmp(pll a,pll b){
	if(a.fs != b.fs)return a.fs<b.fs;
	else return a.sc>b.sc;
}
int main(){
	int n;
	cin>>n;
	for(int i= 0;i<n;i++){
		int m;
		cin>>m;
		pii tmp[m];
		for(int j = 0;j<m;j++){
			cin>>tmp[j].fs>>tmp[j].sc;
			all.push_back(tmp[j].fs);
			all.push_back(tmp[j].sc);
		}
		sort(tmp,tmp+m,cmp);
		int big = 1e9+10;
		for(int j = m-1;j>=0;j--){
			if(big<=tmp[j].sc)continue;
			pos[i].push_back(tmp[j]);
		}
		sort(_all(pos[i]));
	}
	sort(_all(all));
	all.erase(unique(_all(all)),all.end());
	for(auto &i:pos){
		for(auto &j:i){
			j.fs = lower_bound(_all(all),j.fs)-all.begin();
			j.sc = lower_bound(_all(all),j.sc)-all.begin();
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<pos[i].size();j++){
			int s = pos[i][j].fs,e = pos[i][j].sc;
			head[s].push_back({e,i});
			tail[e].push_back({s,i});
		}
	}
//	for(int i = 0;i<all.size();i++){
//		cout<<all[i]<<' ';
//		for(auto &j:tail[i]){
//			cout<<all[j.fs]<<' ';
//		}cout<<endl;
//	}
//	return 0;
	set<int> done;
	int p = 0;
	for(int i = 0;i<all.size();i++){
		if(p<i){
			p = i;
		}
		while(p<all.size()&&done.size() < n){
			for(auto &j:tail[p]){
				if(j.fs<i)continue;
				cnt[j.sc]++;
				done.insert(j.sc);
			}
//			cout<<all[i]<<' '<<(p>=0?all[p]:-1)<<":";
//			for(int k = 0;k<5;k++)cout<<cnt[k]<<',';cout<<endl;
			p++;
		}
//		cout<<all[i]<<' '<<all[p-1]<<endl;
		if(done.size()<n)break;
		ans = min(ans,{all[p-1]-all[i]+1,{all[i],all[p-1]}});
		if(p>i){
			for(auto &j:head[i]){
				if(j.fs<p){
					cnt[j.sc]--;
					if(!cnt[j.sc])done.erase(j.sc);
				}
			}
		}
//		for(int j = 0;j<5;j++)cout<<cnt[j]<<' ';cout<<','<<all[i]<<' '<<all[p-1]<<endl;
	}
	cout<<ans.sc.fs<<' '<<ans.sc.sc;
}
