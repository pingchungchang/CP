#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;
int pi[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	n = s.size();
	if(n == 1){
		cout<<string(k,s[0]);
		return 0;
	}
	if(s[0] == s[1])pi[1] = 1;
	for(int i = 2;i<n;i++){
		int now = i-1;
		while(now>0&&s[pi[now]] != s[i])now = pi[now]-1;
		//cout<<i<<":"<<now<<endl;
		now = max(0,now);
		if(s[pi[now]] == s[i])pi[i] = pi[now]+1;
		else pi[now] = 0;
	}
	//for(int i = 0;i<n;i++)cout<<pi[i]<<' ';cout<<endl;
	int p = n;
	for(int i = 1;i<n;i++){
		if(s[pi[i-1]] < s[i]){
			p = i-pi[i-1];
			break;
		}
	}
	for(int i = 0;i<n;i++)cout<<pi[i]<<' ';cout<<endl;
	s = s.substr(0,p);
	while(s.size()<k)s += s;
	cout<<s.substr(0,k);
	return 0;
}

