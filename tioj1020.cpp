#include <bits/stdc++.h>
using namespace std;
int n;
int cal;
vector<int> nowbiggest = {};
void findall(vector<int> &now,int ins){
	if(ins == n){
		cal++;
//		for(int i =0;i<now.size();i++)cout<<now[i]<<' ';
//		cout<<endl;
//		for(int i =0;i<nowbiggest.size();i++)cout<<nowbiggest[i]<<' ';
//		cout<<endl<<endl;
		if(nowbiggest.size()==0)nowbiggest = now;
		else{
			for(int i =0;i<now.size();i++){
				if(now[i]>nowbiggest[i]){
					nowbiggest = now;
					break;
				}
				else if(now[i]<nowbiggest[i]){
					break;
				}
			}
		}
		return;
	}
	ins++;
	for(int i =0;i<now.size()-1;i++){
		int tot = now[i]+now[i+1];
//		cout<<ins<<' '<<tot;
		if(ins%tot == 0){
			vector<int> k = now;
			k.insert(k.begin()+i+1,ins);
			findall(k,ins);
		}
	}
	return;
}
int main(){
	cin>>n;
	vector<int> root = {0,1};
	if(n == 1){
		cout<<"1\n0 1";		
		return 0;
	}
	findall(root,1);
	cout<<cal<<'\n';
	for(int i =0;i<nowbiggest.size();i++){
		cout<<nowbiggest[i];
		if(i != nowbiggest.size()-1)cout<<' ';
	}
}
