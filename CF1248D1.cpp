#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1010;
int pref[mxn];
int n;
string s;

tuple<int,int,int> calc(int p1,int p2){
	swap(s[p1],s[p2]);
	int re = 0;
	pref[0] = 0;
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1];
		if(s[i-1] == ')')pref[i]--;
		else pref[i] ++;
	}
	for(int i = n+1;i<=n*2;i++){
		pref[i] = pref[i-1];
		if(s[i-n-1] == ')')pref[i]--;
		else pref[i]++;
	}
	deque<int> dq;
	for(int i = 1;i<n;i++){
		while(!dq.empty()&&pref[dq.back()]>=pref[i])dq.pop_back();
		dq.push_back(i);
	}
	//for(auto &i:dq)cout<<i<<' ';cout<<endl;
	for(int i = n;i<n*2;i++){
		while(!dq.empty()&&i-dq.front()>=n)dq.pop_front();
		while(!dq.empty()&&pref[dq.back()]>=pref[i])dq.pop_back();
		dq.push_back(i);
		if(pref[i-n]<=pref[dq.front()])re++;
	}
	//cout<<t<<' '<<p1<<' '<<p2<<' '<<re<<":";for(int i = 0;i<=n*2;i++)cout<<pref[i]<<' ';cout<<endl;
	swap(s[p1],s[p2]);
	return make_tuple(re,p1,p2);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>s;
	int C = 0;
	for(auto &i:s)if(i == ')')C++;else C--;
	if(C){
		cout<<"0\n1 1";
		return 0;
	}
	auto ans = calc(0,0);
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(s[i] == s[j])continue;
			ans = max(ans,calc(i,j));
		}
	}
	cout<<get<0>(ans)<<'\n'<<get<1>(ans)+1<<' '<<get<2>(ans)+1;
}
