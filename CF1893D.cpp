#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
priority_queue<tlll,vector<tlll>,less<tlll>> pq;
int n,m;
map<ll,ll> col;
pll arr[mxn];
vector<int> ans[mxn];
vector<pll> v;

void solve(){
	for(int i = 0;i<=n;i++)ans[i].clear();
	col.clear();v.clear();
	while(!pq.empty())pq.pop();
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		ll k;
		cin>>k;
		col[k]++;
	}
	for(int i = 1;i<=m;i++)cin>>arr[i].fs,ans[i] = vector<int>(arr[i].fs);
	for(int i = 1;i<=m;i++)cin>>arr[i].sc;
	for(int i = 1;i<=m;i++){
		ll pt = 0;
		int pre = arr[i].fs;
		int h = 0;
		while(arr[i].fs>=arr[i].sc){
			pq.push(make_tuple(arr[i].sc,h,i));
			h += arr[i].sc;
			arr[i].fs -= arr[i].sc;
		}
		if(arr[i].fs)pq.push(make_tuple(arr[i].fs,h,i));
		arr[i].fs = pre;
	}

	for(auto &i:col)v.push_back({i.sc,i.fs});
	sort(v.rbegin(),v.rend());

	for(auto &i:v){
		vector<tlll> tmp;
		//cout<<i.fs<<' '<<i.sc<<":"<<endl;
		if(i.fs>pq.size()){
			cout<<"-1\n\n";
			return;
		}
		while(i.fs--){
			auto now = pq.top();
			pq.pop();
			ans[get<2>(now)][get<1>(now)] = i.sc;
			get<0>(now)--;
			get<1>(now)++;
			tmp.push_back(now);
		}
		for(auto &j:tmp){
			if(get<0>(j))pq.push(j);
		}
	}

	for(int i = 1;i<=m;i++){
		reverse(ans[i].begin(),ans[i].end());
		//cout<<i<<":";
		map<int,int> pre;
		for(int j = 0;j<arr[i].fs%arr[i].sc;j++)pre[ans[i][j]] = j;
		for(int j = arr[i].fs%arr[i].sc;j<arr[i].fs;j+=arr[i].sc){
			int r = min(arr[i].sc+j,arr[i].fs);
			vector<int> rest;
			for(int l = j;l<r;l++){
				rest.push_back(ans[i][l]);
			}
			assert(rest.size() == r-j);
			vector<int> mv;
			vector<int> no;
			for(auto &l:rest){
				if(pre.find(l) == pre.end())mv.push_back(l);
				else{
					ans[i][pre[l]+arr[i].sc] = l;
					no.push_back(pre[l]+arr[i].sc);
				}
			}
			assert(mv.size()+no.size() == r-j);
			assert(mv.size()+no.size() == rest.size());
			//reverse(mv.begin(),mv.end());
			sort(no.rbegin(),no.rend());
			//cout<<i<<":"<<j<<" "<<no.size()<<' '<<mv.size()<<":";for(auto &l:no)cout<<l<<' ';cout<<endl;
			for(int l = j;l<r;l++){
				if(!no.empty()&&l == no.back()){
					no.pop_back();
					continue;
				}
				assert(!mv.empty());
				ans[i][l] = mv.back();
				mv.pop_back();
			}
			//cout<<j<<','<<r<<endl;
			pre.clear();
			for(int l = j;l<r;l++)pre[ans[i][l]] = l;
		}
	}

	for(int i = 1;i<=m;i++){
		for(auto &j:ans[i])cout<<j<<' ';cout<<'\n';
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
