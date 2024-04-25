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
	int a,b,c;
	cin>>a>>b>>c;
	bool flag = false;
	if(a<b){
		flag = true;
		swap(a,b);
	}
	string s1 = string(a,'0'),s2 = string(b,'0');
	s2[0] = '1';
	for(int i = 0;i<=a-c;i++){
		s1[i] = '1';
	}
//	string s3 = s1.substr(s1.size()-c,c);
	if(flag)swap(s1,s2);
	cout<<s1<<' '<<s2<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

