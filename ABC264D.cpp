#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	string s = "atcoder";
	map<char,int> mp;
	for(int i = 0;i<s.size();i++)mp[s[i]] = i;
	cin>>s;
	vector<int> v(s.size());
	for(int i= 0;i<s.size();i++)v[i] = mp[s[i]];
	int cnt =0;
	int n = s.size();
	for(int i = 0;i<n-1;i++){
		for(int j = 0;j<n-1;j++){
			if(v[j]>v[j+1]){
				cnt++;
				swap(v[j],v[j+1]);
			}
		}
	}
	cout<<cnt;
}

