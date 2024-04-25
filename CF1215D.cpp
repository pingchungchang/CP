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
	int n;
	cin>>n;
	cin>>s;
	int sum[2] = {};
	int cnt[2] = {};
	for(int i = 0;i<s.size();i++){
		if(s[i] == '?')cnt[i+i>=s.size()]++;
		else sum[i+i>=s.size()]+=s[i]-'0';
	}
	if(sum[0]<sum[1]){
		swap(sum[0],sum[1]);
		swap(cnt[0],cnt[1]);
	}
	int dif = cnt[1]-cnt[0];
	if(sum[0]-sum[1]==dif*9/2)cout<<"Bicarp";
	else cout<<"Monocarp";
	return 0;
}
