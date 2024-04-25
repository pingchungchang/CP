#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

int ask(int a,int b){
	cout<<"? "<<a<<' '<<b<<endl;
	int k;
	cin>>k;
	return k;
}
bool flag = true;
void solve(){
	int n;
	cin>>n;
	if(n == -1){
		flag = false;
		return;
	}
	vector<vector<int>> v(2);
	int now = 0,pre = 1;
	for(int i = 1;i<=(1<<n);i++)v[now].push_back(i);
	while(v[now].size() %4 == 0){
//		cout<<v[now].size()<<endl;
		v[pre].clear();
		for(int j = 0;j<v[now].size();j+=4){
			int k = ask(v[now][j+1],v[now][j+2]);
			if(k == 0){
				if(ask(v[now][j],v[now][j+3]) == 1){
					v[pre].push_back(v[now][j]);
				}
				else{
					v[pre].push_back(v[now][j+3]);
				}
			}
			else if(k == 1){
				if(ask(v[now][j+1],v[now][j+3]) == 1){
					v[pre].push_back(v[now][j+1]);
				}
				else v[pre].push_back(v[now][j+3]);
			}
			else{
				if(ask(v[now][j],v[now][j+2]) == 1){
					v[pre].push_back(v[now][j]);
				}
				else v[pre].push_back(v[now][j+2]);
			}
		}
		swap(pre,now);
	}
	if(v[now].size() != 1){
		if(ask(v[now][0],v[now][1]) == 1)v[pre] = {v[now][0]};
		else v[pre] = {v[now][1]};
		swap(pre,now);
	}
	cout<<"! "<<v[now][0]<<endl;
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--&&flag)solve();
}

