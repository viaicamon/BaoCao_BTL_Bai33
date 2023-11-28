#include"QL_Student.cpp"
#include<conio.h>
#ifndef ___run___cpp__
#define ___run___cpp__
class Application{
private:
	list_Student a;
public:
	Application(){}
	int menu(){
		int n;		
		cout<<"Vui long thuc hien cac thao tac sau: \n";
		cout<<"1. Doc danh sach file!\n";
		cout<<"2. Them mot hoc sinh!\n";
		cout<<"3. Cap nhat thong tin hoc sinh!\n";
		cout<<"4. Xoa thi sinh!\n";
		cout<<"5. Tim kiem thi sinh theo ten!\n";
		cout<<"6. Sap xep thi sinh theo diem trung binh!\n";
		cout<<"7. Sap xep thi sinh theo ten!\n";
		cout<<"8. In danh sach ra man hinh!\n";
		cout<<"9. Luu danh sach vao file!\n";
		cout<<"0. Thoat!\n";
		cout<<"Lua chon cua ban: ";cin>>n;cin.ignore();		
		return n;
	}
	//	Ham chon
	int chon_1(){
		int chon;
		cout<<"1. Su dung file co san \"pupil.txt\".\n";
		cout<<"2. Su dung file cua ban!\n";
		cout<<"Chon phim bat ki de thoat!\n";
		cout<<"Vui long chon: ";cin>>chon;
		return chon;
	}
	int chon_2(){
		int chon;
		cout<<"1. Them mot sinh vien moi vao danh sach!\n";
		cout<<"2. Them mot danh sach sinh vien!\n";
		cout<<"Chon phim bat ki de thoat!\n";
		cout<<"Vui long chon: ";cin>>chon;
		return chon;
	}
	int chon_9(){
		int chon;
		cout<<"1. Luu du lieu vao file mac dinh \"pupil.txt\"!\n";
		cout<<"2. Luu them du lieu vao file mac dinh \"pupil.txt\"!\n";
		cout<<"3. Luu du lieu vao file ban muan!\n";
		cout<<"Chon phim bat ki de thoat!\n";
		cout<<"Vui long chon: ";cin>>chon;
		return chon;
	}
	void run(){
		int chon,check=0;
		do{
			do{
				chon=menu();
			}while(chon>9||chon<0);	
			switch(chon){
				case 1:{//	Doc file
					int tam=0,tmp=chon_1();
					if(tmp==1){
						a.input("pupil.txt",tam);
					}else if(tmp==2){
						cin.ignore();
						str s;		
						cout<<"Vui long nhap ten file: ";getline(cin,s);
						a.input(s,tam);
					}
					if(tam==1){
						check=1;
					}
					break;
				}
				case 2:{//	Them 1 hs
					int tmp=chon_2();
					if(tmp==1){
						cin.ignore();
						a.add_Student();
					}else if(tmp==2){
						ll r;cout<<"Nhap so luong sinh vien ban muan them: ";cin>>r;cin.ignore();
						for(ll i=0;i<r;i++){
							cout<<"Nhap thong tin sinh vien thu "<<i+1<<" can them: \n";
							a.add_Student();
						}
					}
					
					check=1;
					break;
				}
				case 3:{//	cap nhat thong tin hoc sinh
					if(check==1)	a.Update_information();
					else 			cout<<"Khong co du lieu!\n";
					break;
				}
				case 4:{//	Xoa 1 thi sinh
					a.remove_1_Student();
					break;
				}
				case 5:{//	Tim kiem thi sinh theo ten
					if(check==1)	a.find_Name();
					else 			cout<<"Khong co du lieu!\n";
					break;
				}
				case 6:{//	SX thi sinh theo DTB
					if(check==1)	a.sort_GPA();
					else 			cout<<"Khong co du lieu!\n";
					break;
				}
				case 7:{//	SX thi sinh theo ten
					if(check==1)	a.sort_Name();
					else 			cout<<"Khong co du lieu!\n";
					break;
				}
				case 8:{//	in danh sach ra ngoai man hinh
					a.output();
					if(check==0)	cout<<"Khong co du lieu!\n";
					break;
				}
				case 9:{//	luu danh sach vao file
					if(check==1){
						str s;
						cout<<"Nhap ten file can luu: ";getline(cin,s);
						a.output(s);
					}else	cout<<"Khong co du lieu!\n";
					
					break;
				}
				default:{//	thoat
					cout<<"Xin chao va hen gap lai!";
					return;
					break;
				}		
			}
			getch();
			system("cls");
		}while(chon<=9&&chon>=0);
	}
};
#endif
