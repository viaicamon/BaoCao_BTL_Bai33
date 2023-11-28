#include<iostream>
#include<string>
#include"Ham_ngoai.cpp"
#ifndef __VECTOR__cpp__
#define __VECTOR__cpp__

using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

template<class T>
class VECTOR_Reverse_itertor{
private:	T *itr;
public:
	VECTOR_Reverse_itertor(T *element=0){	itr=element;	}
	VECTOR_Reverse_itertor<T> &operator=(T *other_itr){
		this->itr=other_itr.itr;
		return *this;
	}
	VECTOR_Reverse_itertor<T> operator++(){
		itr--;
		return itr;
	}
	VECTOR_Reverse_itertor<T> operator++(int ){
		VECTOR_Reverse_itertor<T> array=itr;
		itr--;
		return array;
	}
	T& operator*(){	return *itr;	}
	bool operator!=(VECTOR_Reverse_itertor<T> w){	return this->itr!=w.itr;	}
	bool operator==(VECTOR_Reverse_itertor<T> w){	return this->itr==w.itr;	}
};
Ham_ngoai dp;
template<class T>
class VECTOR{
private:
	T* arr;
	ll cap,size;
public:
	VECTOR(){
		this->cap=1;
		this->size=0;
		this->arr=new T[1];
	}
	VECTOR(const ll &n){
		this->cap=n;
		this->size=n;
		this->arr=new T[cap];
		for(ll i=0;i<n;i++)	this->arr[i]=0;
	}
	VECTOR(const ll &n,T tmp){
		this->cap=this->size=n;
		this->arr=new T[n];
		for(ll i=0;i<n;i++)	this->arr[i]=tmp;
	}
	void pop_back(){	size--;	}
	void erase(ll k){
		if(k>Size() || k<0)		return ;
		for(;k<size;k++)	arr[k]=arr[k+1];
		size--;
	}
	void extend(ll new_cap){
		if(new_cap<cap)		return;		
		T *old=arr;
		arr=new T[new_cap];
		for(ll i=0;i<size;i++)	arr[i]=old[i];
		this->cap=new_cap;
		delete[] old;
	}
	void push_back(T new_element){
		if(size==cap)	extend(2 * cap);
		arr[size]=new_element;
		size++;
	}
	void insert(ll k,T new_element){
		if(cap==size)		extend(2 * cap);
		for(ll i=size-1 ; i>=k ; i--)	arr[i+1]=arr[i];
		arr[k]=new_element;
		size++;
	}
	void sort_1(){	dp.quickSort_1<T>(arr,0,size-1);	}
	void sort_2(){	dp.quickSort_2<T>(arr,0,size-1);	}
	ll Size(){	return this->size;	}
	ll Capcity(){	return this->cap;	}
	bool empty(){	return size==0;	}
	T &head_element(){	return arr[0];	}
	T &last_element(){	return arr[size-1];	}
	T &operator[](ll index){	return arr[index];	}
	VECTOR &operator=(VECTOR a){
		this->cap=a.cap;
		this->size=a.size;
		if(a.arr){
			this->arr=new T[cap];
			arr=a.arr;
		}else	arr=0;	
		return *this;	
	}
	~VECTOR(){	delete[] arr;	}
//							Bo lap iterator									
	typedef T *iterator;								//	Lap xuoi	
	iterator begin(){	return arr;	}
	iterator end(){	return arr+size;	}
	typedef VECTOR_Reverse_itertor<T>riterator;			//	Lap nguoc	
	riterator rbegin(){	return riterator(arr+size-1);	}
	riterator rend(){	return riterator(arr-1);	}
};

#endif

//int main(){
//	VECTOR<int> a;
//	int n,x;
//	cin>>n;
//	for(int i=0;i<n;i++){
//		int c;cin>>c;a.push_back(c);
//	}
//	for(int i=0;i<a.Size();i++){
//		cout<<a[i]<<" ";
//	}cout<<endl;
//	a.insert(0,5);
//	for(int i=0;i<a.Size();i++){
//		cout<<a[i]<<" ";
//	}
//	return 0;
//}
