#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct node{
	int r;
	int g;
	int b;
	int num;
	node(){
		num = 0;
		r =0,g=0,b=0;
	}
};
int main(){
	int n;
	cin>>n;
	vector<int> allx;
	vector<int> ally;
	vector<vector<int>> req(n,vector<int>(7));
	for(int i = 0;i<n;i++){
		for(int j =0;j<7;j++){
			cin>>req[i][j];
//			if(j == 3)req[i][j]++;
			if(j == 0)allx.push_back(req[i][j]);
			if(j == 1)ally.push_back(req[i][j]);
			if(j == 2)allx.push_back(req[i][j]);
			if(j == 3)ally.push_back(req[i][j]);
		}
		if(req[i][0]>req[i][2])swap(req[i][0],req[i][2]);
		if(req[i][1]>req[i][3])swap(req[i][1],req[i][3]);
	}
	sort(allx.begin(),allx.end());
	allx.erase(unique(allx.begin(),allx.end()),allx.end());
	sort(ally.begin(),ally.end());
	ally.erase(unique(ally.begin(),ally.end()),ally.end());
	for(int i =0;i<n;i++){
		req[i][0] = lower_bound(allx.begin(),allx.end(),req[i][0])-allx.begin();
		req[i][2] = lower_bound(allx.begin(),allx.end(),req[i][2])-allx.begin();
		req[i][1] = lower_bound(ally.begin(),ally.end(),req[i][1])-ally.begin();
		req[i][3] = lower_bound(ally.begin(),ally.end(),req[i][3])-ally.begin();
	}
	sort(req.begin(),req.end());
	map<ll,int> mp;
	vector<vector<node>> v(allx.size(),vector<node>(ally.size(),node()));
	for(int i = 0;i<n;i++){
		int sx=req[i][0],sy=req[i][1],ex=req[i][2],ey=req[i][3];
		v[sx][sy].num++;
		v[sx][sy].r += req[i][4];
		v[sx][sy].g += req[i][5];
		v[sx][sy].b += req[i][6];
		v[sx][ey].num--;
		v[sx][ey].r -= req[i][4];
		v[sx][ey].g -= req[i][5];
		v[sx][ey].b -= req[i][6];
		v[ex][sy].num--;
		v[ex][sy].r -= req[i][4];
		v[ex][sy].g -= req[i][5];
		v[ex][sy].b -= req[i][6];
		v[ex][ey].num++;
		v[ex][ey].r += req[i][4];
		v[ex][ey].g += req[i][5];
		v[ex][ey].b += req[i][6];
	};
	pair<int,vector<int>> ans;
	for(int i = 1;i<allx.size();i++){
		node now;
		now.num=v[i-1][0].num;
		now.r = v[i-1][0].r;
		now.g = v[i-1][0].g;
		now.b = v[i-1][0].b;
//		cout<<now.num<<now.r<<now.g<<now.b<<endl;
		for(int j = 1;j<ally.size();j++){
			if(now.num != 0){
				int ar = ceil((now.r)/(double)now.num);
				int ag = ceil((now.g)/(double)now.num);
				int ab = ceil((now.b)/(double)now.num);
				ll hash = 1LL*1e6*ar+1LL*1e3*ag+ab;
				if(mp.count(hash) == 0){
					mp[hash] = (allx[i]-allx[i-1])*(ally[j]-ally[j-1]);
				}
				else mp[hash] += (allx[i]-allx[i-1])*(ally[j]-ally[j-1]);
				if(ans.first<mp[hash]){
					ans.first = mp[hash];
					ans.second = {ar,ag,ab};
				}				
			}
			now.num+= v[i-1][j].num;
			now.r += v[i-1][j].r;
			now.g += v[i-1][j].g;
			now.b += v[i-1][j].b;
		}
//		for(int j = 0;j<ally.size();j++)cout<<v[i-1][j].num<<' ';
//		cout<<endl;

		for(int j = 0;j<ally.size();j++){
			v[i][j].num+= v[i-1][j].num;
			v[i][j].r += v[i-1][j].r;
			v[i][j].b += v[i-1][j].b;
			v[i][j].g += v[i-1][j].g;
		}
	}
//	for(auto it = mp.begin();it != mp.end();it++){
//		cout<<it->first<<' '<<it->second<<'\n';
//	}
	for(int i =0;i<ans.second.size();i++)cout<<ans.second[i]<<' ';
}
