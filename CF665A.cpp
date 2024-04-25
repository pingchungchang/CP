#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,ta,b,tb;
	cin>>a>>ta>>b>>tb;
	string s;
	cin>>s;
	int st = stoi(s.substr(0,2))*60+stoi(s.substr(3,2));
	int ed = st+ta;
	int ans = 0;
	for(int i = 300;i<=60*23+59;i+=b){
		int s = i,e = i+tb;
		if(e == st||s == ed)continue;
		//cout<<i<<endl;
		if(st<=s&&ed<=s)continue;
		if(st>=e&&ed>=e)continue;
		ans++;
	}
	cout<<ans;
}
