//
// Created by facuh on 8/5/25.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

void swap(int &a,int &b);

int main(){
    int x,y;
    x = 55; y = -22;
    cout <<"\n x = "<<x;
    cout <<"\n y = "<<y;
    cout <<"\n tamaño entero = "<<sizeof(int);
    int *px,*py;
    px = &x; py = &y;
    cout <<"\n px = "<<px;
    cout <<"\n py = "<<py;
    cout <<"\n *px = "<<*px;
    cout <<"\n *py = "<<*py;
    *px=7; cout<<"\n *px = "<<*px<<" x ="<<x;
    py=px; cout<<"\n *py = "<<*py<<" y="<<y;
    swap(x,y);
    cout <<"\n x = "<<x;
    cout <<"\n y = "<<y;
}
//pasaje por referencia
void swap(int &a,int &b){
    int c;
    cout<<"\n a = "<<a<<" b = "<<b;
    c=a; a=b; b=c;
    cout<<"\n a = "<<a<<" b = "<<b;
}
/*
 *pasaje por puntero
void swap(int *a,int *b){
    int c;
    cout<<"\n a = "<<*a<<" b = "<<*b;
    c=*a; *a=*b; *b=c;
    cout<<"\n a = "<<*a<<" b = "<<*b;
}
*/
/*
//intercambio de valores en caso int
void swap(int a,int b){
    int c;
    cout<<"\n a = "<<a<<" b = "<<b;
    c=a; a=b; b=c;
    cout<<"\n a = "<<a<<" b = "<<b;
}
*/