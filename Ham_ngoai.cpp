#include<bits/stdc++.h>
#ifndef __Ham_ngoai__cpp__
#define __Ham_ngoai__cpp__

using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

class Ham_ngoai{
public:
// Cac ham bool 
bool KT_KT(char s){
	if(s>=65&&s<=90)		return true;
	else if(s>=97&&s<=122)	return true;
	else if(s==32)			return true;
	else if(s>=48&&s<=57)	return true;
	return false;
}
bool KT_Chuoi(str s){
	for(ll i=0;i<s.length();i++)
		if(!KT_KT(s[i]))
			return false;
	return true;
}
bool KT_Diem(db a){
	return (a>10||a<0)?false:true;
}
// Cac ham db
db D_TBinh(db a,db b,db c){ return (a+b+c)/3; }
// Cac ham str
str Hoc_luc(db d){
	if(d>=8)			return "Gioi";
	else if(d<8&&d>=7)	return "Kha";
	else if(d<7&&d>=5)	return "Trung Binh";
	else if(d<5)		return "Yeu";
}
str all_upper(str s){
	for(ll i=0;i<s.length();i++)
		if(s[i]<=122&&s[i]>=97)
			s[i]=s[i]-32;
	return s;
}
str all_lower(str s){
	for(ll i=0;i<s.length();i++)
		if(s[i]<=90&&s[i]>=65)
			s[i]=s[i]+32;
	return s;
}
str Hoa_dau(str s){
	if(s[0]>=97&&s[0]<=122)		s[0]=s[0]-32;
	for(ll i=0;i<s.length()-1;i++)
		if(s[i]==' ')
			if(s[i+1]>=97&&s[i+1]<=122)
				s[i+1]=s[i+1]-32;
	return s;
}
str Hoa_dau_2(str s){
	for(ll i=0;i<s.length()-1;i++)
		if(s[i]!=' ')
			if(s[i+1]>=65&&s[i+1]<=90)
				s[i+1]=s[i+1]+32;
	return s;
}
str Ten(str s){
	ll k=s.length();
	bool found=false;
	while(k>=0 && found == false){
		if(s[k]==' ')	found=true;	
		else k--;
	}
	return s.substr(k+1,s.length());
}
// Ham input
str input_MHS(){
	str s;
	cout<<"Ma hoc sinh: ";getline(cin,s);
	while(!KT_Chuoi(s)){
		cout<<"Vui long nhap MHS khong co ki tu dac biet!\nVui long nhap lai: ";
		getline(cin,s);
	}return s;
}
str input_name(){
	str s;
	cout<<"Ho va ten: ";
	getline(cin,s);
	while(!KT_Chuoi(s)){
		cout<<"Vui long nhap ho ten khong Ki tu dac biet!\nVui long nhap lai: ";
		getline(cin,s);
	}
	s=Hoa_dau(Hoa_dau_2(s));
	return s;
}
str input_Gender(){
	str s;
	cout<<"Gioi tinh: ";getline(cin,s);
	while(all_lower(s)!="nam"&&all_lower(s)!="nu"){
		cout<<"Chi co 2 kieu gioi tinh(nam,nu): ";
		getline(cin,s);
	}
	s=Hoa_dau_2(s);
	s=Hoa_dau(s);
	return s;
}
int input_age(){
	ll age;
	cout<<"Tuoi: ";cin>>age;cin.ignore();
	while(age<7||age>60){
		cout<<"Vui long nhap lai tuoi!\nVui long nhap: ";
		cin>>age;cin.ignore();
	}return age;
}
db input_Diem(str s){
	db diem;
	cout<<"Mon "<<s<<": ";cin>>diem;cin.ignore();
	while(!KT_Diem(diem)){
		cout<<"Vui long nhap lai diem mon "<<s<<": ";
		cin>>diem;cin.ignore();
	}
	return diem;
}

// Ham sap xep

template<class T>
void quickSort_1(T *a,ll l,ll r){
	T q=a[(l+r)/2];
	ll i=l,j=r;
	while(i<j){
		while(a[i]>q)	i++;
		while(q>a[j])	j--;
		if(i<=j){
			T tam=a[i];
			a[i]=a[j];a[j]=tam;
			i++;j--;
		}
	}
	if(i<r)	quickSort_1(a,i,r);
	if(j>l)	quickSort_1(a,l,j);
}
template<class T>
void quickSort_2(T *a,ll l,ll r){
	T q=a[(l+r)/2];
	ll i=l,j=r;
	while(i<j){
		while(a[i]<q)	i++;
		while(q<a[j])	j--;
		if(i<=j){
			T tam=a[i];
			a[i]=a[j];a[j]=tam;
			i++;j--;
		}
	}
	if(i<r)	quickSort_2(a,i,r);
	if(j>l)	quickSort_2(a,l,j);
}
};
#endif
