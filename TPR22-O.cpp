#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		v[i]--;
	}
	vector<int> goneto(n,0);
	int gp = 0;
	for(int i = 0;i<n;i++){
		if(goneto[i] == 0){
			gp++;
			int now = i;
			while(goneto[now] == 0){
				goneto[now] = 1;
				now = v[now];
			}
		}
	}
	if(k>n){
		cout<<-1;
		return 0;
	}
	cout<<abs(gp-k);
}

