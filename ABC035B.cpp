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
	string s;
	int t;
	cin>>s>>t;
	int cnt[2] = {};
	int q = 0;
	for(auto &i:s){
		if(i == '?')q++;
		else if(i == 'U')cnt[0]--;
		else if(i == 'D')cnt[0]++;
		else if(i == 'L')cnt[1]++;
		else if(i == 'R')cnt[1]--;
	}
	if(t == 1){
		cout<<abs(cnt[0])+abs(cnt[1])+q<<endl;
	}
	else{
		cnt[0] = abs(cnt[0]);cnt[1] = abs(cnt[1]);
		if(cnt[0]+cnt[1]>=q)cout<<cnt[0]+cnt[1]-q<<endl;
		else{
			if((q-cnt[0]-cnt[1])&1)cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
}

