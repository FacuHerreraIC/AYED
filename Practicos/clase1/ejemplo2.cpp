//
// Created by facuh on 8/5/25.
//
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    int *px,*py;
    int v[5]={23,1,-8,14,7};
    px=&v[0]; py=v;
    for(int i=0;i<5;i++){
      //situaciones equivalentes a llamar punteros en C++
      cout<<endl<<px[i]<<" "<<*(px+i)<<" "<<*(v+i)<<" "<<*py++;
    }
    cout <<"\n px = "<<px;
    cout <<"\n py = "<<v;
    cout <<"\n *px = "<<*px;
    cout <<"\n *py = "<<*py;

}