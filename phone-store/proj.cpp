#include<iostream>
#include <fstream>
#include<string>
#include<vector>
using namespace std;
int main(){
	 string arr[3];
	ofstream o("users.txt");
	for(int a=0;a<3;a++){
	cin>>arr[a];
	}
	for(int a=0;a<3;a++){
		o<<arr[a]<<endl;
	}
		o.close();
	vector<string>lins;
	string lin;
	ifstream in("users.txt");
	while(getline(in,lin)){
		lins.push_back(lin);
	}
	in.close();
	string x,y;
		getline(cin,x);
	cout<<"pleas entr the name"<<endl;
	getline(cin,x);
	cout<<"enter new name"<<endl;
	getline(cin,y);
	bool f=false;
	for(int i=0;i<lins.size();i++){
		if(lins[i]==x){
			lins[i]=y;
			f=true;
			break;
		}
		
	}
	if(f==false){
			cout<<"not found\n";
		}
		
	ofstream out("users.txt");
	for(int c=0;c<lins.size();c++){
		out<<lins[c]<<endl;
	}
	out.close();
}

