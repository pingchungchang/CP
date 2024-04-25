#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	pii arr[m];
	for(auto &i:arr){
		i = {0,0};
		string s;
		cin>>s;
		if(s[0] == 'm')i.fs += 100;
		i.fs += stoi(s.substr(1,s.size()-1));
		i.fs--;
		cin>>s;
		if(s[0] == 'm')i.sc += 100;
		i.sc += stoi(s.substr(1,s.size()-1));
		i.sc--;
	}

	for(int i = 0;i<(1<<n);i++){
		bool flag = true;
		for(int j = 0;j<m;j++){
			int cnt = 0;
			int p = arr[j].fs%100;
			if((i&(1<<p))&&arr[j].fs/100)cnt++;
			else if((i&(1<<p)) == 0&&arr[j].fs/100 == 0)cnt++;
			p = arr[j].sc%100;
			if(i&(1<<p)&&arr[j].sc/100)cnt++;
			else if((i&(1<<p)) == 0&&arr[j].sc/100 == 0)cnt++;
			if(cnt == 0)flag = false;
		}
		if(flag){
			cout<<"GOOD\n";
			return;
		}
	}
	cout<<"BAD\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
