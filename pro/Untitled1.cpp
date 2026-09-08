#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <array>
using namespace std;
struct r{
	int f;
	char h;
};

int *m(int *ptr)
{
	int y;
for(y=0;y<3;y++){

	cout<<ptr[y]<<endl;
}
return ptr+1;
}
int main(){
 
array<int,10>g{4,5,6,7,66,8,99,44,36};
//cout<<sizeof(size_t)<<endl;
//cout<<sizeof(g)<<endl; 
sort(g.begin(),g.end());
bool ah = binary_search(g.begin(),g.end(),66);
if (ah==0)
cout<<" not found "<<endl;
if (ah==1)
cout<<" found "<<endl;
for(auto fff:g)
cout<<fff<<endl;

 int b=9,n=1; 
int *p,*pp;                   
p= &b;
pp=&b;
cout<<&p<<endl;

cout<<*p<<endl;
cout<<&pp<<endl;
cout<<*pp<<endl;

*p=*p+*pp;

cout<<*p<<endl;


int *ptr=new int[5];
ptr[0]=12;
ptr[1]=99;
ptr[2]=55;
cout<<*m(ptr);
}
