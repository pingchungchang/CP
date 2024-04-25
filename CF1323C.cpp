#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	string s;
	cin>>n>>s;
	int cnt = 0;
	for(auto &i:s){
		if(i == ')')cnt--;
		else cnt++;
	}
	if(cnt != 0){
		cout<<-1;
		return 0;
	}
	vector<int> tl,tr;
	for(int i = 0;i<n;i++){
		if(s[i] == ')')tr.push_back(i);
		else tl.push_back(i);
	}
	int ans = n;
	for(int i = 0;i<tr.size();i++){
		if(tl[i]<tr[i])ans-=2;
	}
	cout<<ans;
}
