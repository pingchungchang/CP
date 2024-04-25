#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int n;
string s,ts;

void flip(int p){
	s[p] = (s[p] == '0'?'1':'0');
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	ts = s;
	for(int i = 0;i+2<n;i++){
		if(s[i] == '1'){
			flip(i);flip(i+1);flip(i+2);
		}
	}
	if(n != 1&&s.end()[-2] == '1'){
		flip(n-2);
		flip(n-1);
	}
	if(s.back() == '0'){
		cout<<"Yes";
		return 0;
	}
	s = ts;
	if(n!=1){
		flip(0);
		flip(1);
	}
	for(int i = 0;i+2<n;i++){
		if(s[i] == '1'){
			flip(i);flip(i+1);flip(i+2);
		}
	}
	if(n != 1&&s.end()[-2] == '1'){
		flip(n-2);
		flip(n-1);
	}
	if(s.back() == '0')cout<<"Yes";
	else cout<<"No";
}
