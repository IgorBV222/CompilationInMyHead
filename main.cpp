#include <iostream>
#include <vector>
class A {
public:
	virtual void foo(std::vector<int>& vec) = 0;
	virtual ~A() {} // добавляем деструктор
};
class B : public A {
public:
	void foo(std::vector<int>& vec) override {
		std::cout << "foo function" << std::endl;
		vec.erase(vec.begin());
	}
};
int main() {
	A* b = new B();
	std::vector<int> v = { 1,2,3 };
	b->foo(v); // в методе foo выбирается первый элемент vec.begin() и удаляется vec.erase, следовательно останиться {2,3}

	delete b; // если есть деструктор класса родителя он ведь тоже очистит все и у наследника, если я правильно понимаю и этот delete не обязателен?
}