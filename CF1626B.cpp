#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	string s;
	cin>>s;
	for(int i = s.size()-1;i>=1;i--){
		int sum = (int)s[i]-'0'+s[i-1]-'0';
		if(to_string(sum).size() == 2){
			for(int j = 0;j<i-1;j++)cout<<s[j];cout<<sum;for(int j = i+1;j<s.size();j++)cout<<s[j];cout<<'\n';
			return;
		}
	}
	cout<<(int)s[0]-'0'+s[1]-'0';for(int i = 2;i<s.size();i++)cout<<s[i];cout<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}

