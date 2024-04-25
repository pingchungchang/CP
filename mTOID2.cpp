#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	pair<int,int> b = make_pair(-1,-99);
	vector<pair<int,int>> bigs(n);
	for(int i =0;i<n;i++){
		cin>>v[i];
		bigs[i] =b;
		if(v[i]>b.first){
			b.second = b.first;
			b.first = v[i];
		}
		else if(b.second<v[i]){
			b.second = v[i];
		}
	}
	vector<pair<int,int>> pref(n,make_pair(0,0));
	pref[0] = make_pair(1,1);
	for(int i = 1;i<n;i++){
		if(bigs[i].first<v[i]){
			pref[i].first = 1;
		}
		if(bigs[i].second<v[i]){
			pref[i].second = 1;
		}
		pref[i].first += pref[i-1].first;
		pref[i].second += pref[i-1].second;
	}
	
	int ans = 0;
	int s = 0;
	int e = 0;
	int nb = -99;
	for(auto i:pref){
		cout<<i.first<<' '<<i.second<<'\n';
	}
	
	for(int i = 0;i<n;i++){
		e = i;
		cout<<s<<' '<<e<<' '<<ans<<' '<<nb<<'\n';
		if(nb == bigs[i].second){
			nb = bigs[i].first;
			int tmp = 0;
			if(e != 0)tmp += pref[e-1].second;
			if(s >= 1)tmp -= pref[s-1].second;
			tmp += pref[n-1].first;
			if(e != 0)tmp -= pref[e-1].first;
			if(s >= 1)tmp += pref[s-1].first;
			ans = max(ans,tmp);
			s=i;
			e=i;
		}
		if(i == n-1){
			nb = bigs[i].first;
			int tmp = 0;
			if(e != 0)tmp += pref[e-1].second;
			if(s >= 1)tmp -= pref[s-1].second;
			tmp += pref[n-1].first;
			if(e != 0)tmp -= pref[e-1].first;
			if(s >= 1)tmp += pref[s-1].first;
			ans = max(ans,tmp);
			s=i;
			e=i;			
		}
	}
	cout<<ans<<'\n';
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

/*
4
5
1500 1900 1700 1850 2000
5
1 2 3 4 5
1
999999
5
1 3 2 5 4
*/
