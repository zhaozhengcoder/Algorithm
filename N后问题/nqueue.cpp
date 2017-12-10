#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>  

using namespace std;

//记录一下结果的个数
int times=0;

void print_res(vector<int> path ){
    times++;
    for (auto it =path.begin();it!=path.end();it++){
        cout<<*it<<"  ";
    }
    cout<<endl;
}

bool isHang(vector<int> path){
    set<int> path_set;

    for (auto it =path.begin();it!=path.end();it++){
        path_set.insert(*it);
    }

    if(path_set.size()==path.size()){
        return true;
    }
    else{
        return false;
    }
}

bool isXiexian(vector<int> path){
    for(int i=0;i<path.size()-1;i++){
        for(int j=i+1;j<path.size();j++){
            if(abs(path[i]-path[j])==abs(i-j) ){
                return false;
            }
        }
    }
    return true;
}

void dfs(int index,int n,vector<int> path){

    //找到结果 
    if(index==n){
        //判断结果的合法性

        if(isHang(path) && isXiexian(path)){
            print_res(path);
        }
        return ;
    }


    //进入下一层递归
    for(int i=0;i<n;i++){
        path[index]=i;
        dfs(index+1,n,path);
        path[index]=-1;
    }
}

void n_queen(int n){
    vector<int> path(n,-1);
    int index=0;
    for(int i=0;i<n;i++){
        path[index]=i;
        dfs(index+1,n,path);

        //清除上一次进入递归的状态
        path[index]=-1;
    }
}

int main(){
    const int n=8;
    n_queen(n);
    cout<<endl;
    cout<<"times : "<<times<<endl;
    return 0;
}