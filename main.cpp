#include<iostream>
#include<memory>

//using namespace std;
//
//class AAA
//{
//public:
//	AAA()
//	{
//		cout << "AAA()" << endl;
//	}
//	~AAA()
//	{
//		cout << "~AAA()" << endl;
//
//	}
//};
//
//int main()
//{
//	{
//		shared_ptr<AAA> sp(new AAA());
//	}
//	return 0;
//}

// shared_ptr constructor example
//#include <iostream>
//#include <memory>
//
//struct C { int* data; };
//
//int main() {
//
//	std::shared_ptr<int> p1;
//	std::shared_ptr<int> p2(nullptr);
//	std::shared_ptr<int> p3(new int);
//	std::shared_ptr<int> p4(new int, std::default_delete<int>());
//	std::shared_ptr<int> p5(new int, [](int* p){delete p; }, std::allocator<int>());
//	std::shared_ptr<int> p6(p5);
//	std::shared_ptr<int> p7(std::move(p6));
//	std::shared_ptr<int> p8(std::unique_ptr<int>(new int));
//	std::shared_ptr<C> obj(new C);
//	std::shared_ptr<int> p9(obj, obj->data);
//
//	std::cout << "use_count:\n";
//	std::cout << "p1: " << p1.use_count() << '\n';
//	std::cout << "p2: " << p2.use_count() << '\n';
//	std::cout << "p3: " << p3.use_count() << '\n';
//	std::cout << "p4: " << p4.use_count() << '\n';
//	std::cout << "p5: " << p5.use_count() << '\n';
//	std::cout << "p6: " << p6.use_count() << '\n';
//	std::cout << "p7: " << p7.use_count() << '\n';
//	std::cout << "p8: " << p8.use_count() << '\n';
//	std::cout << "p9: " << p9.use_count() << '\n';
//	return 0;
//}

//void fun(const std::shared_ptr<int>& sp)
//{
//	std::cout << "fun: sp.use_count() == " << sp.use_count() << '\n';
//}
//
//int main()
//{
//	auto sp1 = std::make_shared<int>(5);
//	std::cout << "sp1.use_count() == " << sp1.use_count() << '\n';
//
//	fun(sp1);
//	return 0;
//}
//Example3


int main()
{
	auto sp1 = std::make_shared<int>(5);
	auto sp2 = sp1;
	sp2.swap(sp1);
	std::cout << "sp1.use_count() == " << sp1.use_count() << '\n';
	return 0;
}

