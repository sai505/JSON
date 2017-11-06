#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

struct JSON{ //open definition as possible 
	virtual void write();
	virtual void stringify(JSON);
	virtual void print() const =0;
	std::string json_text;
};

template <class T>
struct value:JSON{
	//value can be null, bool, number
	value(T data);
	void print() const; //overide
	void stringify(JSON); //override?
	
	std::string s="";
	int number=0;
	bool t=true;
	T array[]=nullptr;
};

struct Array:value
{
	Array(std::initializer_list<Value*> list)
	:vals(list) {}
	
	~Array() overide{
		for(Value* v: vals)
			delete v;
	}
	
	void add(Value* v){
		vals.push_back(v);	
	}
	
	void print() const overide{
		std::cout<<'[';
		for(auto iter = vals.begin(); iter!=vals.end();++iter){
			(*iter)->print();
			if(std::next(iter) != vals.end())
				std::cout ", ";
		}
		std::cout<<"]";
	}
	std::vector<Value*> vals;
}

struct Object:value
{
	Object() = default;
	~Object(){
		for(auto p: fields){
			delete p.first;
		}
		
	}
}
