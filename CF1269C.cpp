#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n,k;
inline bool check(string &s){
	for(int i = 0;i<k;i++){
		for(int j = i+k;j<n;j++){
			if(s[j] != s[j-k])return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>n>>k>>s;
	//string tmp = s;
	if(check(s)){
		cout<<s.size()<<'\n';
		cout<<s;
		return 0;
	}
	string ans = s;
	for(int i = k-1;i>=0;i--){
		if(s[i] != '9'){
			char c = s[i]+1;
			for(int j = 0;j<k;j++){
				if(j<i)for(int l = j+k;l<n;l+=k)s[l] = s[l-k];
				else for(int l = j;l<n;l+=k)s[l] = '0';
			}
			for(int j = i;j<n;j+=k)s[j] = c;
			break;
		}
		if(!i)s = string(n,'9');
	}
	for(int i = k;i<n;i++){
		if(ans[i] < ans[i-k]){
			char c = ans[i-k];
			for(int l = 0;l<k;l++){
				char big = ans[l];
				for(int j = l;j<i;j+=k)big = max(big,ans[j]);
				for(int j = l;j<n;j+=k)ans[j] = big;
			}
			s = min(s,ans);
			assert(s.size() == ans.size());
			break;
		}
	}
	//assert(check(s));
	//assert(max(tmp,s) == s);
	//if(!check(s))s = string(n,'9');
	cout<<s.size()<<'\n'<<s;
}
