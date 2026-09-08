#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void log_out();
void refile ();

int main() {

	refile ();
}
void log_out(){
	
	cout<<"enter the name"<<endl;
	cin>>;
	cout<<"enter the pasword"<<endl;
	cin>>;
}

void refile () {
	ifstream in("pro.txt",ios::app);
	string con;
	if(!in.is_open()) {
		cerr<<"erorr in open file"<<endl;
		return ;
	}
	string name;
	string newname;
	cout<<"enter name\n";
	cin>>name;
	cout<<"enter new name\n";
	cin>>newname;
	string line;
	while(getline(in,line)) {
		size_t po=0;
		while((po=line.find(name,po))!=string::npos) {
			line.replace(po,name.length(),newname);
			po+=newname.length();
		}
		con+=line+"\n";
	}
	in.close();
	ofstream out("pro.txt",ios::app);
	if(!out.is_open()) {
		cout<<"erorr in out fil\n";
		return ;
	}
	out<<con;
	out.close();
}

