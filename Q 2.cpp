#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Student{
	char name[15];
	int age;
};
int main(){
	fstream f;
	f.open("xyz.dat",ios::out|ios::in|ios::trunc);
	int size;
	cin>>size;
	Student *s=new Student[size];
	for(int i=0;i<size;i++){
		cin.ignore();
		cout<<"Enter name : ";
		cin.getline(s[i].name,15);
		cout<<"Enter age : ";
		cin>>s[i].age;	
	}
	f.write((const char*)s,sizeof(Student));
	int i,n;
	f.seekg(0,ios::beg);
	i=f.tellg();
	f.seekg(0,ios::end);
	n=f.tellg();
	cout<<n;
	Student* p=new Student[n];
	f.read((char*)p,sizeof(Student));
	for(int i=0;i<n;i++){
		cout<<p[i].name<<"\t"<<p[i].age<<endl;
	}
}
