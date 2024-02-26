#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main(){

int a , i= 0;

string text ,old,password1,password2,pass,name, password0, age,user,word,word1;
string creds[2],cp[2];
cout<<"    Security system"<<endl;

cout<<"____________________________"<<endl;

    cout<<"|   1.Register    |"<<endl<<endl;
    cout<<"|   2.Login       |"<<endl;
    cout<<"|   3.Change password    |"<<endl;
    cout<<"|   4.End program    |"<<endl<<endl;         


do{
	cout<<endl<<endl;
	cout<<" Enter your choice :-";
	cin>>a;
	switch(a)
	{
		
		case 1:
			{
			cout<<"_______________________________";
			cout<<"-----------Register------------";
			cout<<"_______________________________"<<endl;
			cout<<" Please enter username:-"<<endl;
			cin>>name;
			cout<<" Please enter your age:-"<<endl;
			cin>>age;
			cout<<" Please neter password "<<endl;
			cin>>password0;
			
			ofstream of1;
			of1.open("file.text");
			if(of1.is_open()){
			of1<<name<<"\n";
			of1<<password0<<"\n";
			cout<<"Registration Successfully"<<endl;				
			}
			break;
		}
		
		case 2:{
			i=0;
			cout<<"_______________________________";
			cout<<"-----------Register------------";
			cout<<"_______________________________"<<endl;
			
			ifstream of2;
			of2.open("file.text");
			cout<<" Enter the your username"<<endl;
			cin>>user;
			cout<<" Enter the password"<<endl;
			cin>>pass;
			
			if(of2.is_open()){
				while(!of2.eof())
				{
					while(getline(of2,text)){
						istringstream iss(text);
						iss>>word;
						creds[i]= word;
						i++;
					}
					if (user==creds[0] && pass==creds[1]){
						cout<<"-----Login successful----";
						cout<<endl<<endl;
						cout<<"  Details  :--"<<endl;
						cout<<" Username:-"  + name<<endl;
						cout<<" Password:-"  + pass<<endl;
						cout<<"  Age:-"   + age<<endl;
					}
					else{
						cout<<endl<<endl;
						cout<<" Incorrect"<<endl;
						cout<<" |     1.Press 2 to login     |"<<endl;
						cout<<" |     2.Press 3 to change password   |"<<endl;
						break;
					}
				
				}
				
				
			}
			break;
		}
		case 3:
			{
				i=0;
				cout<<" ---------------------change Password------------------"<<endl;
				ifstream of0;
				of0.open("file.text");
				cout<<" Enter your old password:- "<<endl;
				cin>>old;
				if(of0.is_open()){
					while(of0.eof()){
						while(getline(of0,text)){
							istringstream iss(text);
							iss>>word1;
							cp[i]=word1;
							i++;
						}
						if(old==cp[1]){
							of0.close();
							
							ofstream of1;
							if(of0.is_open()){
								cout<<" Enter your New password"<<endl;
								cin>>password1;
								cout<<" Enter your password again"<<endl;
								cin>>password2;
								
								if(password1==password2){
									of1<<cp[0]<<"\n";
									of1<<password1;
									cout<<" Password change successfully"<<endl;
								}
								else{
									of1<<cp[0]<<"\n";
									of1<<old;
									cout<<" Password not matched"<<endl;
								}
							}
							
						}
						else{
							cout<<" Please enter a vaild Password"<<endl;
							break;
						}
					}
				}
				break;
				
			}
			case 4:{
				cout<<"________________Thankyou!_________________"<<endl;
				break;
			}
			default:
				cout<<" Enter the vaild choice:-";
	
     	}
   }
   while(a!=4);
   return 0;	
}
