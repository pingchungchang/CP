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
	string s;
	cin>>s;
	for(int i = 0;i<s.size();){
		if(s[i] == '.')cout<<0,i++;
		else if(s.substr(i,2) == "-.")cout<<1,i+=2;
		else cout<<2,i+=2;
	}
	return 0;
}
