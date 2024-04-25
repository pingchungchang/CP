#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	string s;
	cin>>n>>s;
	deque<int> dq;
	char big = 'a';
	for(int i = n-1;i>=0;i--){
		if(s[i]>=big){
			dq.push_front(i);
			big = s[i];
		}
	}
	int pt = 0;
	//for(auto &i:dq)cout<<i<<',';cout<<'\n';
	while(pt<dq.size()&&s[dq[pt]] == s[dq[0]])pt++;
	vector<int> tmp;
	auto dq2 = dq;
	for(int i = pt;i<dq.size();i++){
		tmp.push_back(dq[i]);
	}
	for(auto &i:tmp)dq.push_front(i);
	string t = s;
	for(int i = 0;i<dq2.size();i++){
		s[dq2[i]] = t[dq[i]];
	}
	sort(t.begin(),t.end());
	if(t == s){
		cout<<dq2.size()-pt<<'\n';
	}
	else cout<<"-1\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
