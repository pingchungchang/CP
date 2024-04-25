#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct bot{
	int id;
	bool stop;
	pair<int,int> pos
	pair<int,int> dir;
	bot(){
		stop = false;
		pos = make_pair(-1,-1);
		id = -1;
		dir = make_pair(-1,-1);
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<bot> v(m);
	for(int i = 0;i<m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		bot tmp;
		tmp.id = a;
		if(d == 1)tmp.dir = make_pair(0,-1);
		else if(d == 2)tmp.dir = make_pair(1,-1);
		else if(d == 3)tmp.dir = make_pair(1,0);
		else if(d == 4)tmp.dir = make_pair(1,1);
		else if(d == 5)tmp.dir = make_pair(0,1);
		else if(d == 6)tmp.dir = make_pair(-1,1);
		else if(d == 7)tmp.fir = make_pair(-1,0);
		else tmp.dir = make_pair(-1,-1);
		tmp.pos = make_pair(b,c);
		v[i] = tmp;
	}
	int mv = 0;
	int t = 0;
	while(mv != (1<<n)-1){
		map<tuple<int,int>,vector<int>> mp;
		for(auto now:v){
			int nowpos = make_tuple(now.pos.fs,now.pos.sc);
			mp[nowpos].push_back(now.id);
			if(now.pos.fs != 1&&now.pos.sc !=1&&now.pos.sc != n&&now.pos.fs !=n &&(mv&(1<<(now.id-1)))== 0){
				now.pos.fs += now.dir.fs;
				now.pos.sc += now.dir.sc;
			}
		}
		for(auto it:mp){
			if(mp.sc.size() != 1){
				
			}
		}
	}
}

