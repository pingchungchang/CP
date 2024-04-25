#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int C = 0;
	ll ans = 0;
	for(auto &i:s){
		if(i == '0')ans = ans*10+C,C = 0;
		else C++;
	}
	cout<<ans*10+C;
}
