#include <iostream>
#include <string.h>
#include <cstdio>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
using namespace std;

int main(){
    char* s = new char(101);
    char a;
    char b;
    int fd = open("/home/chang/000.cpp/tmp.txt",O_CREAT|O_RDWR,0777);
    scanf("%s ",s);
    if(fd == -1){
        cout<<"fd fail";
        return 0;
    }
    if(strcmp(s,"writeNum") == 0){
        cout<<"gotinif\n";
        scanf("%c %c ",&a,&b);
        cout<<a<<b;
        int wr = write(fd,&a,sizeof(a));
        if(wr==-1){
            cout<<"write a fail";
            return 0;
        }
        wr = write(fd," ",sizeof(char));
        if(wr == -1){
            cout<<"write space fail";
            return 0;
        }
        wr = write(fd,&b,sizeof(b));
        if(wr == -1){
            cout<<"b fail";
            return 0;
        }
        cout<<"input";
        int ls = lseek(fd,0,SEEK_SET);
        if(ls == -1){
            cout<<"ls fail";
            return 0;
        }
        char* c = new char(10);
        int r = read(fd,c,10 * sizeof(char));
        if(r == -1){
            cout<<"reading fail";
            return 0;
        }
        for(int i =0;i<10;i++){
            cout<<c[i];
        }
        close(fd);
    }

    //else if(s == "readNum"){
//
   // }
}
