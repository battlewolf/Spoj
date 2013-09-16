#include<iostream>
using namespace std;int M[101][101],t,l,i,j;main(){cin>>t;while(t--){cin>>l;for(i=0;i<l;i++){for(j=0;j<=i;j++)cin>>M[i][j];}for(i=l-2;i>=0;i--){for(j=0;j<=i;j++)M[i][j]=M[i][j]+max(M[i+1][j],M[i+1][j+1]);}cout<<endl<<M[0][0];}}
