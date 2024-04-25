#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<queue<int>> v(1+n);
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		v[k].push(i);
	}
	int now = -1;
	vector<int> ans;
	while(!v[0].empty()){
		int k = -1;
		int tmp = now;
		for(int i = 0;i<=n;i++){
			while(!v[i].empty()&&v[i].front()<=now){
				v[i].pop();
			}
			if(v[i].empty())break;
			else{
				tmp = max(tmp,v[i].front());
				v[i].pop();
			}
			k++;
		}
		now = tmp;
		if(k != -1)ans.push_back(k+1);
	}
	for(int i = 0;i<=n;i++){
//		cout<<i<<' '<<v[i].front()<<endl;
		while(!v[i].empty()&&v[i].front()<=now)v[i].pop();
		while(!v[i].empty()){
			v[i].pop();
			ans.push_back(0);
		}
	}
	cout<<ans.size()<<'\n';
	for(int i = 0;i<ans.size();i++)cout<<ans[i]<<' ';
	cout<<'\n';//<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i =0;i<t;i++)solve();
}
