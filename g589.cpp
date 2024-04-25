#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	vector<int> paths;
	int color;
	node(){
		color = 0;
	}
};
bool draw(vector<node> &v,int pos,int col){
	col = -col;
	bool returns = true;
	for(int i =0;i<v[pos].paths.size();i++){
		int nxt = v[pos].paths[i];
		if(v[nxt].color == 0){
			v[nxt].color = col;
			returns = returns&draw(v,nxt,col);
			continue;
		}
		else if(v[nxt].color != col)return false;
	}
	return returns;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<node> v(n,node());
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v[a].paths.push_back(b);
		v[b].paths.push_back(a);
	}
	int p,k;
	cin>>p>>k;
	vector<int> errors;
	for(int asd=1;asd<=p;asd++){
		vector<node> v2 = v;
		for(int i =0;i<k;i++){
			int a,b;
			cin>>a>>b;
			v2[a].paths.push_back(b);
			v2[b].paths.push_back(a);
		}
		bool ans = true;
		for(int i=0;i<n;i++){
			if(v2[i].color == 0){
				v2[i].color = -1;
				ans = ans&draw(v2,i,-1);
				if(ans == false)break;
			}
		}
//		for(int i =0;i<v2[0].paths.size();i++)cout<<v2[0].paths[i]<<' ';
//		cout<<endl;
		if(ans == false)errors.push_back(asd);
	}
	for(int i =0;i<errors.size();i++){
		cout<<errors[i]<<'\n';
	}
}

