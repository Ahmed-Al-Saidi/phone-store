#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"mylib.h"
#include<iomanip>
using namespace std;
struct USER {
	string username,password,usertype,phonenumber;
	short activ;
};
void add(vector<USER>&us);
bool vaphone(const string&phone);
string serchpass = "";
string serchuse="";
string currentUser="";
void menu();
void loginUser(vector<string>&userlo);
void logoutUser(vector<string>&logou);
void story();
void ad();
void em();
void cl();
int main() {
	char welc[7]="welcom";
	cout<<"\t\t";
	for(int amn=0;amn<=6;amn++)
	{
		cout<<"\t";
		color(6);
	cout<<welc[amn];
	Sleep(4);
	}	
	vector<USER>us;
	vector<string>userlo;
	vector<string>logou;
	while(true) {
		
		color(3);
		cout<<"\n+++++++++++++++"<<endl;
		char welco[17]="+ 1. Add User +";
	for(int ammn=0;ammn<=14;ammn++)
	{
		color(3);
	cout<< welco[ammn];
	Sleep(20);
	}
		cout<<"\n+++++++++++++++"<<"\n"<<endl;
		color(2);
			cout<<"+++++++++++++++"<<endl;
					char waelco[17]="+ 2. Login    +";
	for(int ammmn=0;ammmn<=14;ammmn++)
	{
		color(2);
	cout<< waelco[ammmn];
	Sleep(20);
	}
//		cout<<"+ 2. Login    +"<<endl;
			cout<<"\n+++++++++++++++"<<"\n"<<endl;
			color(4);
				cout<<"+++++++++++++++++++"<<endl;
								char welmo[20]="+to exit enter any+";
	for(int ammmnn=0;ammmnn<=18;ammmnn++)
	{
		color(4);
	cout<< welmo[ammmnn];
	Sleep(20);
	}
//		cout<<"+ to exit enter any+"<<endl;
		cout<<"\n+++++++++++++++++++\n"<<endl;
										char wlemo[20]="enter number....:-";
	for(int aammmnn=0;aammmnn<=19;aammmnn++)
	{
	cout<< wlemo[aammmnn];
	Sleep(20);
	}
		
		int choice=chose();
		switch(choice) {

			case 1: {
				try {
					system("cls");
					color(3);
				add(us);
					break;
				} catch(const char*s) {
					cout<<" ----------------------------"<<endl;
					cout<<"| !! "<<s<<" !! |"<<endl;
					cout<<" ----------------------------"<<endl;
						
				}
					
				break;
			}
			case 2: {

				try {
					color(2);
					loginUser(userlo);

					break;
				} catch(const char*s) {
					cout<<" -------------------------------------------"<<endl;
					cout<<"| !! "<<s<<" !! |"<<endl;
					cout<<" -------------------------------------------"<<endl;
				}
				break;
			}
		
			
			default: {
				cout << "Exiting...\n";
			}
		}
	}
}	
bool vaphone(const string&phone) {
	for(int i=0; i<phone.length(); i++) {
		if(!isdigit(phone.at(i))) throw " Invalid number.... ";
	}
	if(phone.length()!=9) {
		if(phone.length()>9) throw " Number is long.... ";
		if(phone.length()<9) throw " Number is short.... ";
		return false;
	}
	string per=phone.substr(0,2);
	if(per=="77"||per=="73"||per=="71"||per=="78") {
		return true;
	}
	return false;

}
void add(vector<USER>&us) {
	USER use;
	vector<string>username;
	vector<string>check;
	ifstream ou("users.txt",ios::app);
	string line;
	bool foundus=false;
	while(getline(ou,line)) {
		username.push_back(line);
	}
	cout<<" Enter username : "<<endl;
	getline(cin,use.username);
	getline(cin,use.username);
	for(int i=0; i<username.size(); i++) {
		if(use.username==username[i]) {
			system("cls");
			color(6);
			cout<<" --------------------------------------------------"<<endl;
			cout<<"| !! Username was added. ( Enter new username ) !! |"<<endl;
			cout<<" --------------------------------------------------"<<endl;
			
			return;
		}
	}
	ou.close();
	cout<<" Enter password : "<<endl;
	getline(cin,use.password);
	cout<<" Enter your phon number : "<<endl;
	getline(cin,use.phonenumber);
	if(!vaphone(use.phonenumber)) {
		return;
	}
	cout<<" Type ( Admin / Employee / Client ) : "<<endl;
	getline(cin,use.usertype);
	ifstream ouu("users.txt");
	while(getline(ouu,line)) {
		check.push_back(line);
	}
	for(int y=0; y<username.size(); y++) {
		if(username[y]==check[y]&&use.usertype==check[y+2]) {
			if(use.usertype=="Admin") {
				system("cls");
				cout<<endl;
				cout<<"\t\t * * * * * * * * * * * * * * * * * * * * *"<<endl;
				cout<<"\t\t *  Admin was added , No add admin other * "<<endl;
				cout<<"\t\t * * * * * * * * * * * * * * * * * * * * *"<<endl;
				cout<<endl;
				return;
			}
		
		}
	}
	if(use.usertype!="Admin"&&use.usertype!="Employee"&&use.usertype!="Client") throw "  Invalid type....  ";
	use.activ=true;
	us.push_back(use);


	ofstream in("users.txt",ios::app);
	if(in.is_open()) {
		in<<use.username<<"\n"<<use.password<<"\n"<<use.phonenumber<<"\n"<<use.usertype<<"\n"<<use.activ<<"\n"<<"--------------------------------------------"<<endl;
		in.close();
	}
	system("cls");
	cout<<endl;
	cout<<"\t\t * * * * * * * * *"<<endl;
	cout<<"\t\t *  Users added  *"<<endl;
	cout<<"\t\t * * * * * * * * *"<<endl;
	cout<<endl;
}
void loginUser(vector<string>&userlo) {
	string username, password;
	vector<string>cost;
	vector<string>chec;
	ifstream ou("users.txt");
	string line,lines,liness;
	bool foundus=false;
	while(getline(ou,line)) {
		userlo.push_back(line);
	}
	ou.close();
	ifstream cos("cost.txt");
	while(getline(cos,lines)) {
		cost.push_back(lines);
	}
	cos.close();
	ifstream ch("login.txt");
	while(getline(ch,liness)) {
		chec.push_back(liness);
	}
	ch.close();
	getline(cin,username);
	cout << "Enter username : ";
	getline(cin,username);
	cout << "Enter password: ";
	getline(cin,password);

	/*for(int i=0; i<chec.size(); i++) {
		if(username==chec[i]&&password==chec[i+1]) {
			throw " Enter anther username or password ";
			return;
		}
	}*/
	ifstream user("users.txt");
	bool found = false;
	if (user.is_open()) {
		for(int us=0; us<userlo.size(); us++) {
			if(username==userlo[us]&&password==userlo[us+1]) {
				cout<<endl;
				cout<<"\t\t * * * * * * * * * * * * * * * * * "<<endl;
				cout<<"\t\t *  Login successful! Welcome,   * "<<endl;
				cout<<"\t\t * * * * * * * * * * * * * * * * * "<<endl;
				cout<<endl;
				ofstream log("login.txt");
				log<<username<<"\n"<<password<<"\n"<<"--------------------------------------------"<<endl;
				log.close();
				found=true;
				break;
			}
		}
		if(found==false) {
			throw "Error: Invalid username or password ";
		}
	}



	
	bool admin=false;
	bool employee =false;
	bool client=false;
	for(int j=0;j<userlo.size();j++){
		if(userlo[j]==username&&userlo[j+1]==password&&userlo[j+3]=="Client")
		{
		client=true;	
		}
		if(userlo[j]==username&&userlo[j+1]== password&&userlo[j+3]=="Admin")
		{
			admin=true;
		}
		if(userlo[j]==username&&userlo[j+1]==password&&userlo[j+3]=="Employee")
		{
			employee=true;
		}
		
	}
	if(admin==true){
      ad();
		
	}
	if (employee==true){
		em();
	}
	if(client==true){
		cl();
	}
}
void logoutUser(vector<string>&logou) {
	string username, password;
	ifstream logout("users.txt");
	string line;
	bool foundus=false;
	while(getline(logout,line)) {
		logou.push_back(line);
	}
	logout.close();
	getline(cin,username);
	cout << "Enter username : ";
	getline(cin,username);
	cout << "Enter password: ";
	getline(cin,password);
	bool found=false;
	for(int i=0; i<logou.size(); i++) {
		if(logou[i]==username&&logou[i+1]==password) {
			logou[i]="";
			logou[i+1]="";
			logou[i+2]="";
			found=true;
			break;
		}
	}
	if(found==false) {
		cout<<" ----------------------"<<endl;
		cout<<"| !! Not found user !! |"<<endl;
		cout<<" ----------------------"<<endl;
	}
	ofstream outfil("login.txt");
	for(int in=0; in<logou.size(); in++) {
		outfil<<logou[in]<<endl;
	}
	outfil.close();
	if(found==true) {
		cout<<endl;
		cout<<"\t\t * * * * * * * * * * * * * * * * "<<endl;
		cout<<"\t\t *  Successful dalete users,   * "<<endl;
		cout<<"\t\t * * * * * * * * * * * * * * * * "<<endl;
		cout<<" "<<endl;
	}
	return ;
}
void story(){
	int ci;
	cout<<"choies the phone"<<endl;
	cout<<"1-iphon9=300$\n"<<"2-iphon16=700$\n3-samsung s22 ultra 5G=800$\n4-samsung s9=100$\n 5-goto the employee\n6-exit\n";
	cin>>ci;
	switch(ci){
		case 1:{
			const double i9=300;
			double amo;
			cout<<"enter the amount\n";
			cin>>amo;
			
			if (amo==i9){
			
			cout<<"the total= "<<i9<<"$"<<endl;
			}
			if(amo>i9){
		
				cout<<"the total="<<i9<<"$"<<"\n----------"<<endl;
				cout<<"thes for you="<<amo-i9<<"$"<<endl;
				
			}
			if(amo<i9){
				cout<<"the amount is not full"<<endl;
			}
			break;
		}
			case 2:{
						const double i16=700;
			double amo;
			cout<<"enter the amount\n";
			cin>>amo;
			
			
			if (amo==i16){
			
			cout<<"the total= "<<i16<<"$"<<endl;
			}
			if(amo>i16){
		
				cout<<"the total="<<i16<<"$"<<"\n----------"<<endl;
				cout<<"thes for you="<<amo-i16<<"$"<<endl;
				
			}
			if(amo<i16){
				cout<<"the amount is not full"<<endl;
			}
			break;
		}
			case 3:{
							const double s22=800;
			double amo;
			cout<<"enter the amount\n";
			cin>>amo;
			
			
			if (amo==s22){
			
			cout<<"the total= "<<s22<<"$"<<endl;
			}
			if(amo>s22){
		
				cout<<"the total="<<s22<<"$"<<"\n----------"<<endl;
				cout<<"thes for you="<<amo-s22<<"$"<<endl;
				
			}
			if(amo<s22){
				cout<<"the amount is not full"<<endl;
			}
			break;
		}
			case 4:{
										const double s9=100;
			double amo;
			cout<<"enter the amount\n";
			cin>>amo;
			
			
			if (amo==s9){
			
			cout<<"the total= "<<s9<<"$"<<endl;
			}
			if(amo>s9){
		
				cout<<"the total="<<s9<<"$"<<"\n----------"<<endl;
				cout<<"thes for you="<<amo-s9<<"$"<<endl;
				
			}
			if(amo<s9){
				cout<<"the amount is not full"<<endl;}
			break;
		}
		case 5:{
			return em();
			break;
			
		} 
		default :{
			system ("cls");
			cout<<"see you soon"<<endl;
		}
		
		
	}
	}
	void ad(){
		
			vector<USER>us;
	      vector<string>userlo;
	       vector<string>logou;
       while(true){
       	
       
		int c;
		cout<<"*wellcom Admin*"<<endl;
		cout<<"you can add and log out the users"<<endl;
		cout<<"1-add\n2-log out the user\n3-exit"<<endl;
		cin>>c;
		switch(c){
			case 1: {
				try {
					add(us);
					break;
				} catch(const char*s) {
					cout<<" ----------------------------"<<endl;
					cout<<"| !! "<<s<<" !! |"<<endl;
					cout<<" ----------------------------"<<endl;
				}
				break;
		}
		case 2:{
				try {
					logoutUser(logou);

					break;
				} catch(const char*s) {
					cout<<" -------------------"<<endl;
					cout<<"| "<<s<<" |"<<endl;
					cout<<" -------------------"<<endl;
				}
				break;
		}
		case 3:{
			system("cls");
			return;
		}
		}
       }
	}
	void em(){
	
		int y;
		cout<<"Hello iam the Employee :-)\n"<<endl;
		cout<<"I can show our store for you and enter to it"<<endl;
			loop:
		cout<<"1-show the store amounts"<<endl;
		cout<<"2-enter to the store"<<endl;
		cout<<"3-exit"<<endl;
		cin>>y;
		switch(y){
			case 1:{
					system("cls");
				cout<<"------/minu/------"<<endl;
				cout<<"1-iphon9=300$\n"<<"2-iphon16=700$\n3-samsung s22 ultra 5G=800$\n4-samsung s9=100$\n------------\n";
			goto loop;
			
			}break;
			case 2:{
					system("cls");
					story();
				
				break;
			}
			case 3:{
				return;
			}break;
			default:{
				cout<<"not faond tray agin or enter number 3 to exit\n";
				goto loop;
			}
		}
	}
	void cl(){
		system("cls");
		int s;
		cout<<"welcom our client :-)\n";
		cout<<"1- show our amount\n";
		lop:
		cout<<"2-enter to our store\nor enter any number to exit\n";
		cin>>s;
		switch(s){
			case 1:{
						system("cls");
				cout<<"------/minu/------"<<endl;
				cout<<"1-iphon9=300$\n"<<"2-iphon16=700$\n3-samsung s22 ultra 5G=800$\n4-samsung s9=100$\n------------";
		          goto lop;
			}	break;	 
			case 2:{
				story();
			}break;
	default:{
		system ("cls");
	}
	}
	}
 
