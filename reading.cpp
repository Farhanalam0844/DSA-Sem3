#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Student{
	string name;
	int age;
};
int main(){
	fstream f;
	int SIZE;
	cout<<"Enter number of students : ";
	cin>>SIZE;
	Student* s=new Student[SIZE];
	f.open("abc.dat",ios::out|ios::in|ios::binary | ios::trunc);
	if(f.is_open()){
		for(int i=0;i<SIZE;i++){
		cout<<"Enter name and age : \n";
		cin.ignore();
		getline(cin,s[i].name);
		cin>>s[i].age;
		
	}	
		f.write((const char*)s,sizeof(Student));
	}
	else{
		cout<<"File could not be opened \n";
	}
	f.seekg(0,ios::beg);
	int i;
	for(i=0;i<SIZE;i++){
		cout<<sizeof(s[i])<<endl;
		f.read((char*)s,sizeof(s[i]));
		cout<<s[i].name<<"\t"<<s[i].age<<endl;
	}
}
