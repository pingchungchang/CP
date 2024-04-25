#include <bits/stdc++.h>
using namespace std;
typedef struct player{
    string plays;
    int id;
    int place;
    int wins;

}player;

class Compare{
public:
    bool operator()(player a,player b){
        if(a.wins!=b.wins)return a.wins>b.wins;
        else return a.id<b.id;
    }
};
// G stands for rock, C stands for scissors, and P stands for paper
void fight(int i,player &a,player &b){
    if(a.plays[i] == b.plays[i]){
        return;
    }
    else{
        if(a.plays[i] == 'G'){
            if(b.plays[i] == 'C')a.wins++;
            else b.wins++;
        }
        else if(a.plays[i] == 'C'){
            if(b.plays[i] == 'G')b.wins++;
            else a.wins++;
        }
        else{
            if(b.plays[i] == 'G')a.wins++;
            else b.wins++;
        }
    }
    return;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<player> v(2*n);
    for(int i =0;i<2*n;i++){
        string s;
        cin>>s;
        v[i].plays = s;
        v[i].id = i+1;
        v[i].wins = 0;
    }
    for(int i =0;i<m;i++){
        for(int j =1;j<=n;j++){
            fight(i,v[j*2-1],v[j*2-2]);
        }
        //for(int i =0;i<2*n;i++)cout<<v[i].id<<' '<<v[i].wins<<'\n';
        //cout<<endl<<endl;
        sort(v.begin(),v.end(),Compare());
    }
    for(int i =0;i<2*n;i++)v[i].place = i+1;
    //sort(v.begin(),v.end(),C2());
    for(int i =0;i<2*n;i++){
        cout<<v[i].id<<'\n';//' '<<v[i].wins<<'\n';
    }
}


