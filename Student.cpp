#include"VECTOR.cpp"
#include<fstream>
#include"Ham_ngoai.cpp"
#ifndef __Student__cpp__
#define __Student__cpp__


class Student{
private:
	str MHS;		// MHS: Ma hoc sinh
	str Name;		// Name: Ho va ten
	str Gender;		// Gender: Gioi tinh
	str CSCT;		// CSCT: Xep loai
	int age;			// age: Tuoi
	db DT,DL,DH,D_TB;// D_TB: Diem trung binh = (DT+DL+DH)/3
public:
	Student(){}
	void input_or_set(){
		Ham_ngoai dp;
		this->MHS	=	dp.input_MHS();
		this->Name	=	dp.input_name();
		this->Gender=	dp.input_Gender();
		this->age	=	dp.input_age();
		this->DT	=	dp.input_Diem("Toan");
		this->DL	=	dp.input_Diem("Ly");
		this->DH	=	dp.input_Diem("Hoa");
		this->D_TB	=	dp.D_TBinh(DT,DL,DH);
		this->CSCT	=	dp.Hoc_luc(D_TB);
	}
	str &get_MHS(){
		return this->MHS;
	}
	str &get_Name(){
		return this->Name;
	}
	str get_Ten(){
		Ham_ngoai dp;
		return dp.Ten(this->get_Name());
	}
	db &get_DTB(){
		return this->D_TB;
	}
	bool operator<(Student w){
		if(get_Name()==w.get_Name()){
			return get_MHS()<w.get_MHS();
		}else if(get_Ten()==w.get_Ten()){
			return get_Name()<w.get_Name();
		}else{
			return get_Ten()<w.get_Ten();
		}		
	}
	bool operator>(Student w){
		if(get_DTB()==w.get_DTB()){
			if(get_Name()==w.get_Name()){
				return get_MHS()>w.get_MHS();
			}else if(get_Ten()==w.get_Ten()){
				return get_Name()>w.get_Name();
			}else return get_Ten()>w.get_Ten();
		}else{
			return this->D_TB>w.D_TB;
		}		
	}
	friend istream &operator>>(istream &f,Student &w){
		Ham_ngoai dp;
		w.MHS=dp.input_MHS();
		w.Name=dp.input_name();
		w.Gender=dp.input_Gender();
		w.age=dp.input_age();
		w.DT=dp.input_Diem("Toan");
		w.DL=dp.input_Diem("Ly");
		w.DH=dp.input_Diem("Hoa");
		w.D_TB=dp.D_TBinh(w.DT,w.DL,w.DH);
		w.CSCT=dp.Hoc_luc(w.D_TB);
		return f;
	}
	friend ostream &operator<<(ostream &f,Student &w){
		f<<"|"<<fixed<<setprecision(2)<<left<<setw(20)<<w.MHS<<"|"<<setw(20)<<w.Name<<"|"<<setw(20)<<w.Gender<<"|"<<setw(10)<<w.age<<"|"<<setw(10)<<w.DT<<"|"<<setw(10)<<w.DL<<"|"<<setw(10)<<w.DH<<"|"<<setw(10)<<w.D_TB<<"|"<<right<<setw(10)<<w.CSCT<<"|";
		return f;
	}
	friend ifstream&operator>>(ifstream&f,Student &w){
		getline(f,w.MHS);
		getline(f,w.Name);
		getline(f,w.Gender);
		f>>w.age;
		f>>w.DT>>w.DL>>w.DH>>w.D_TB;f.ignore();
		getline(f,w.CSCT);
		return f;
	}
	friend ofstream&operator<<(ofstream&f,Student &w){
		f<<"|"<<fixed<<setprecision(2)<<left<<setw(20)<<w.MHS<<"|"<<setw(20)<<w.Name<<"|"<<setw(20)<<w.Gender<<"|"<<setw(10)<<w.age<<"|"<<setw(10)<<w.DT<<"|"<<setw(10)<<w.DL<<"|"<<setw(10)<<w.DH<<"|"<<setw(10)<<w.D_TB<<"|"<<right<<setw(10)<<w.CSCT<<"|";
		return f;
	}
};
#endif
