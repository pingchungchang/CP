#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

int ask(int k){
	cout<<"? "<<k<<endl;
	int re;
	cin>>re;
	return re;
}
bool flag = true;
bool cmp(pii a,pii b){
	return a.sc<b.sc;
}
void solve(){
	set<int> done;
	vector<vector<pii>> cycles;
	int x = 0;
	int n;
	cin>>n;
	if(n == 0){
		flag = false;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(done.find(i) != done.end())continue;
		cycles.push_back({});
		int now = ask(i);
		while(done.find(now) == done.end()){
			done.insert(now);
			cycles.back().push_back(make_pair(now,x));
			x++;
			now = ask(i);
		}
		x++;
	}
//	for(auto i:cycles){
//		for(auto j:i)cout<<j.fs<<' '<<j.sc<<',';cout<<endl;
//	}
	vector<int> ans(n+1,-1);
	for(auto &i:cycles){
		vector<int> all;
		for(auto &j:i){
			all.push_back(j.fs);
			j.sc = j.sc%i.size();
			if(j.sc == 0)j.sc = i.size();
		}
		sort(i.begin(),i.end(),cmp);
		i.push_back(i[0]);
		for(int j= 0;j<i.size()-1;j++){
			ans[i[j].fs] = i[j+1].fs;
		}
	}
	cout<<"! ";for(int j = 1;j<=n;j++)cout<<ans[j]<<' ';cout<<endl;
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--&&flag)solve();
}

