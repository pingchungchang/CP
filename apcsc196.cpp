#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	string s;
	cin>>s;
	int cnt[30] = {};
	pii ans= make_pair(-1,1e9);
	int n = s.size();
	int r = 0;
	set<char> st;
	for(char c = 'a';c<='z';c++)st.insert(c);
	for(int i = 0;i<n;i++){
		while(!st.empty()&&r<n){
			cnt[s[r]-'a']++;
			st.erase(s[r]);
			r++;
		}
		if(st.empty()&&ans.sc-ans.fs>r-i)ans = make_pair(i,r);
		cnt[s[i]-'a']--;
		if(cnt[s[i]-'a'] == 0)st.insert(s[i]);
	}
	if(ans.fs == -1)cout<<"QQ\n";
	else cout<<s.substr(ans.fs,ans.sc-ans.fs);
}

