#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


const int mxn = 110;
int pre[mxn];
vector<int> paths[mxn];
void get(int id,int k){
	if(paths[id].empty()){
		while(k--){
			int c;
			cin>>c;
			paths[id].push_back(c);
		}
	}
	else{
		int c;
		while(k--)cin>>c;
	}
	return;
}
int main(){
	int n,m;
	cin>>n>>m;
	int now = 1;
	pre[1] = 1;
	string ss;
	while(cin>>ss){
		if(ss == "OK")return 0;
		assert(ss != "-1");
		get(now,stoi(ss));
		bool flag = false;
		for(auto nxt:paths[now]){
			if(!pre[nxt]){
				pre[nxt] = now;
				now = nxt;
				cout<<nxt<<endl;
				flag = true;
				break;
			}
		}
		if(!flag)now = pre[now],cout<<now<<endl;
	}
}
