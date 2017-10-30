#include <iostream>
#include <string>
#include <vector>
struct JSON{ //open definition as possible 
	virtual void write();
	virtual void stringify(JSON);
	virtual void print() const;
	std::string json_text;
};

template <class T>
struct value:JSON{
	value(T data);
	void print() const; //overide
	void stringify(JSON); //override?
	
	std::string s="";
	int number=0;
	bool t=true;
	T array[]=nullptr;
};
