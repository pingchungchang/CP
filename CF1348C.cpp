#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	int cnt[26] = {};
	set<char> st;
	string s;
	cin>>s;
	for(auto &i:s)cnt[i-'a']++,st.insert(i);
	sort(s.begin(),s.end());
	if(st.size()>2){
		string ans;
		ans += s[0];
		for(int i = k;i<n;i++)ans += s[i];
		for(int i = 1;i<k;i++)ans = max(ans,string(1,s[i]));
		cout<<ans<<'\n';
	}
	else{
		if(st.size() == 2){
			auto ta = *st.begin();
			if(cnt[ta-'a'] == k){
				string ans;ans += ta;
				ans += string((cnt[*st.rbegin()-'a']+k-1)/k,*st.rbegin());
				cout<<ans<<'\n';
			}
			else if(cnt[ta-'a']>=k){
				string ans(cnt[ta-'a']-(k-1),ta);
				ans += string(cnt[*st.rbegin()-'a'],*st.rbegin());
				cout<<ans<<'\n';
			}
			else{
				cout<<*st.rbegin()<<'\n';
			}
		}
		else cout<<string((cnt[*st.begin()-'a']+k-1)/k,*st.begin())<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
