#include <bits/stdc++.h>
using namespace std;
typedef struct time{
    int year;
    int month;
    char event[40];
    char city[40];
}time;
class Compare{
public:
    bool operator()(time a,time b){
        if(a.year != b.year)return a.year>b.year;
        else return a.month>b.month;
    }
};
int main(){
    int sm,sd,sum;
    scanf("%d/%d %d",&sm,&sd,&sum);
    char s[40];
    unordered_map<char[40],int> cityincomes;
    vector<char[40]> cities; 
    while(scanf("%s",s)){
        if(strcmp(s,"----") == 0)break;
        cities.push_back(s);
        int income;
        scanf("%d",&income);
        cityincomes[s] = income;
    }
    int x,y;
    scanf("%d %d",&x,&y);
    vector<time> events;
    char c[40];
    while(scanf("%d/%d %s %s",&sm,&sd,c,s)){
        if(strcmp(s,"----") == 0)break;
        time tmp;
        tmp.month = sd;
        tmp.year = sm;
        memcpy(tmp.event,s,sizeof(s));
        memcpy(tmp.city,c,sizeof(c));
        events.push_back(tmp);
    }
    int fy,fm;
    scanf("%d %d",&fy,&fm);
    sort(events.begin(),events.end(),Compare);
    int ny = events[0].year,nm = events[0].month;
    for(int i =0;i<events.size();i++){
        time now = events[i];
        if(now.year>=fy&&now.month>fm)break;
        if(now.year!=ny||now.month != nm){
            for(int j =0;j<cities.size();j++){
                // adding fee
            }
        }
    }
}