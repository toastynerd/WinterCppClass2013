  //SimpleClass.cpp
//Tyler Morgan
//Winter c++ class
//assignment 4.1

#include <iostream>

class SimpleClass{
public:
	void f1(SimpleClass aSimpleClass);
	void f2(SimpleClass aSimpleClass);
	void f3(SimpleClass& aSimpleClass);
	void f4(SimpleClass* aSimpleClass);
	SimpleClass();
	SimpleClass(const SimpleClass& newSimpleClass);
	~SimpleClass();
};

void SimpleClass::f1(SimpleClass aSimpleClass){
	std::cout << "starting f1" << std::endl;
	SimpleClass newSimpleClass;
	newSimpleClass.f2(newSimpleClass);
}

void SimpleClass::f2(SimpleClass aSimpleClass){
	std::cout << "starting f2" << std::endl;
	SimpleClass newSimpleClass(aSimpleClass);
	newSimpleClass.f3(newSimpleClass);
} 

void SimpleClass::f3(SimpleClass& aSimpleClass){
	std::cout << "starting f3" << std::endl;
	SimpleClass* aSimpleClassPointer = &aSimpleClass;
	aSimpleClass.f4(aSimpleClassPointer);
}

void SimpleClass::f4(SimpleClass* aSimpleClass){
	std::cout << "starting f4" << std::endl;
}
SimpleClass::SimpleClass(){
	std::cout << "Creating a new SimpleClass" << std::endl;
}

SimpleClass::SimpleClass(const SimpleClass& newSimpleClass){
	std::cout << "Creating a new SimpleClass" << std::endl;
}

SimpleClass::~SimpleClass(){
	std::cout << "Destroying an old withered SimpleClass" << std::endl;
}

int main(){
	SimpleClass mySimpleClass;
	mySimpleClass.f1(mySimpleClass);
}
/*There are 5 instances of SimpleClass that are created
frist: the initial BasicCLass mySimpleClass in main()
second: when f1 is called it creates a new instance in its argument aSimpleClass
third: f1 creates a new SimpleClass within its body called newSimpleClass
fourth: f2 creates a new SimpleClass within its argument
fifth: f2 creates a new SimpleClass within its body
f3 and f4 do not create new instances because they pass by reference/by pointer*/ 