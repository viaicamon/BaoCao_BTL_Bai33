#include"Student.cpp"
#include"VECTOR.cpp"
#include"Ham_ngoai.cpp"
#ifndef __QL_Student__cpp__
#define __GL_Student__cpp__
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

class list_Student{
private:
	VECTOR<Student> ST;
public:
	list_Student(){}
	void input(str ten_file,int &tam){
		ifstream f(ten_file);
		if(f.fail()){
			cout<<"Loi doc file!";
			return;
			tam=0;
		}
		ll n;f>>n;f.ignore();
		for(ll i=0;i<n;i++){
			Student tam;
			f>>tam;
			ST.push_back(tam);
		}
		tam=1;
		f.close();
	}
	void add_Student(){
		Student s;
		cin>>s;
		add_Student(s);
	}
	void add_Student(Student add){
		ST.push_back(add);
	}
	void output(){
		cout<<"So luong hoc sinh: "<<ST.Size()<<endl;
		cout<<"|"<<left<<setw(20)<<"MHS"<<"|"<<setw(20)<<"Ho va ten"<<"|"<<setw(20)<<"Gioi tinh"<<"|"<<setw(10)<<"Tuoi"<<"|"<<setw(10)<<"D.Toan"<<"|"<<setw(10)<<"D.Ly"<<"|"<<setw(10)<<"D.Hoa"<<"|"<<setw(10)<<"D.TBinh"<<right<<"|"<<setw(10)<<"Xep loai"<<"|"<<endl;
		for(ll i=0;i<ST.Size();i++){
			cout<<ST[i]<<endl;
		}
	}
	void output(str Ten_file){
		ofstream f(Ten_file);
		f<<ST.Size()<<endl;
		f<<"|"<<left<<setw(20)<<"MHS"<<"|"<<setw(20)<<"Ho va ten"<<"|"<<setw(20)<<"Gioi tinh"<<"|"<<setw(10)<<"Tuoi"<<"|"<<setw(10)<<"D.Toan"<<"|"<<setw(10)<<"D.Ly"<<"|"<<setw(10)<<"D.Hoa"<<"|"<<setw(10)<<"D.TBinh"<<right<<"|"<<setw(10)<<"Xep loai"<<"|"<<endl;
		for(ll i=0;i<ST.Size();i++){
			f<<ST[i]<<endl;
		}	
		f.close();
	}
	void Update_information(){
		str s;cout<<"Nhap ma sinh vien can cap nhat: ";
		getline(cin,s);
		ll k=0;
		bool found=false;
		while(k<ST.Size()&&found==false){
			if(s==ST[k].get_MHS()){
				found=true;
			}else{
				k++;
			}
		}
		if(found){
			ST[k].input_or_set();
		}else{
			cout<<"Khong tim thay sinh vien ban muan cap nhat thong tin!\n";
		}
	}
	void remove_1_Student(){
		str s;
		getline(cin,s);
		ll k=0;
		bool found=false;
		while(k<ST.Size()&&found==false)
			if(s==ST[k].get_MHS())	found=true;
			else	k++;
		if(found){
			cout<<"Da xoa thanh cong hoc sinh ban vua nhap!\n";
			ST.erase(k);
		}else	cout<<"Khong tim thay sinh vien ban muan xoa!\n";
	}
	void find_Name(){
		str s;
		getline(cin,s);
		ll k=0;
		bool found=false;
		while(k<ST.Size()){
			if(s==ST[k].get_Name()){
				found=true;
				cout<<ST[k]<<endl;
			}
				k++;
		}
		if(!found)
			cout<<"Khong tim thay sinh vien ban muan tim!\n";
	}
	void sort_GPA(){
		ST.sort_1();
	}
	void sort_Name(){
		ST.sort_2();
	}
};
#endif
