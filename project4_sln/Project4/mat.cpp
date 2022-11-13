#include "mat.h"
#include <iostream>

template<typename T>
MAT<T>::MAT(int r, int c) : r(r), c(c), e(new T[r * c]{})
{
	std::cout << "ctor1:" << r << " " << c << std::endl;
	test_print();
}

template<typename T>
MAT<T>::MAT(const MAT& a) : r(a.r), c(a.c), e(new T[a.r*a.c])
{
	std::cout << "ctor2:" << r << " " << c << std::endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			e[i*c+j] = a.e[i*c+j];
		}
	}
	test_print();
}

template<typename T>
MAT<T>::MAT(MAT&& a) noexcept : r(a.r), c(a.c), e(a.e)
{
	std::cout << "ctor3:" << r << " " << c << std::endl;
	*(T**)& a.e = nullptr;
	*(int*)&a.r = 0;
	*(int*)&a.c = 0;
	test_print();
}

template<typename T>
MAT<T>::~MAT() noexcept
{
	std::cout << "dtor" << std::endl;
	if (e == nullptr) return;
	delete[]e;
	*(T**)& e = nullptr;
	*(int*)&r = 0;
	*(int*)&c = 0;
}

template<typename T>
T* const MAT<T>::operator[](int r)
{
	if (r >= this->r || r < 0) throw "error";
	return e + r * this->c;
}

template<typename T>
MAT<T> MAT<T>::operator+(const MAT& a) const
{
	std::cout << "+" << std::endl;
	if (a.r == r && a.c == c) {
		MAT<T> ans(r, c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ans.e[i*c+j] = this->e[i*c+j] + a.e[i*c+j];
			}
		}
		ans.test_print();
		return ans;
	}
	throw "error";
}

template<typename T>
MAT<T> MAT<T>::operator-(const MAT& a) const
{
	std::cout << "-" << std::endl;
	if (a.r == r && a.c == c) {
		MAT<T> ans(r, c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ans.e[i*c+j] = this->e[i*c+j] - a.e[i*c+j];
			}
		}
		ans.test_print();
		return ans;
	}
	throw "error";
}

template<typename T>
MAT<T> MAT<T>::operator*(const MAT& a) const
{
	std::cout << "*" << std::endl;
	if (this->c == a.r) {
		MAT<T> ans(this->r, a.c);
		for (int i = 0; i < this->r; i++) {
			for (int j = 0; j < a.c; j++) {
				for (int k = 0; k < this->c; k++) {
					ans.e[i*c+j] += this->e[i*c+k] * a.e[k*c+j];
				}
			}
		}
		ans.test_print();
		return ans;
	}
	throw "error";
}

template<typename T>
MAT<T> MAT<T>::operator~() const
{
	std::cout << "~" << std::endl;
	MAT<T> ans(this->c, this->r);
	for (int i = 0; i < this->r; i++) {
		for (int j = 0; j < this->c; j++) {
			ans.e[j*c+i] = this->e[i*c+j];
		}
	}
	ans.test_print();
	return ans;
}

template<typename T>
MAT<T>& MAT<T>::operator=(const MAT& a)
{
	std::cout << "=1" << std::endl;
	if (this == &a) return *this;
	if (e != nullptr) {
		delete[]e;
		*(T**)&e = nullptr;
	}
	*(T**)&e = new T[a.r * a.c];
	for (int i = 0; i < r*c; i++) {
		e[i] = a.e[i];
	}
	*(int*)&r = a.r;
	*(int*)&c = a.c;
	test_print();
	return *this;
	// TODO: 在此处插入 return 语句
}

template<typename T>
MAT<T>& MAT<T>::operator=(MAT&& a) noexcept
{
	std::cout << "=2" << std::endl;
	if (this == &a) return *this;
	if (e != nullptr) {
		delete[]e;
		*(T**)&e = nullptr;
	}
	*(T**)&e = a.e;
	*(int*)& r = a.r;
	*(int*)&c = a.c;
	*(T**)&a.e = nullptr;
	*(int*)&a.r = 0;
	*(int*)&a.c = 0;
	test_print();
	return *this;
	// TODO: 在此处插入 return 语句
}

template<typename T>
MAT<T>& MAT<T>::operator+=(const MAT& a)
{
	std::cout << "+=" << std::endl;
	if (r == a.r && c == a.c) {
		for (int i = 0; i < r*c; i++) {
			this->e[i] += a.e[i];
		}
	}
	else throw "error!";
	test_print();
	return *this;
	// TODO: 在此处插入 return 语句
}

template<typename T>
MAT<T>& MAT<T>::operator-=(const MAT& a)
{
	std::cout << "-=" << std::endl;
	if (r == a.r && c == a.c) {
		for (int i = 0; i < r * c; i++) {
			this->e[i] -= a.e[i];
		}
	}
	else throw "error!";
	test_print();
	return *this;
	// TODO: 在此处插入 return 语句
}

template<typename T>
MAT<T>& MAT<T>::operator*=(const MAT& a)
{
	std::cout << "*=" << std::endl;
	if (this->c == a.r) {
		MAT<T> ans(this->r, a.c);
		for (int i = 0; i < this->r; i++) {
			for (int j = 0; j < a.c; j++) {
				for (int k = 0; k < this->c; k++) {
					ans.e[i * c + j] += this->e[i * c + k] * a.e[k * c + j];
				}
			}
		}
		*this = (MAT&&)ans;
		test_print();
		return *this;
	}
	else throw "error!";
	return *this;
	// TODO: 在此处插入 return 语句
}

template<typename T>
char* MAT<T>::print(char* s) const noexcept
{
	strcpy(s, "");
	char* ss;
	if (typeid(e[0]) == typeid(long long int)) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ss = s + strlen(s);
				sprintf(ss, "%c", ' ');
				ss = s + strlen(s);
				sprintf(ss, "%6lld", e[i * c + j]);
			}
			ss = s + strlen(s);
			sprintf(ss, "\n");
		}
	}
	else if (typeid(e[0]) == typeid(int)) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ss = s + strlen(s);
				sprintf(ss, "%c", ' ');
				ss = s + strlen(s);
				sprintf(ss, "%6ld", e[i * c + j]);
			}
			ss = s + strlen(s);
			sprintf(ss, "\n");
		}
	}
	else if (typeid(e[0]) == typeid(float)) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ss = s + strlen(s);
				sprintf(ss, "%c", ' ');
				ss = s + strlen(s);
				sprintf(ss, "%8f", e[i * c + j]);
			}
			ss = s + strlen(s);
			sprintf(ss, "\n");
		}
	}
	else if (typeid(e[0]) == typeid(double)) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ss = s + strlen(s);
				sprintf(ss, "%c", ' ');
				ss = s + strlen(s);
				sprintf(ss, "%8lf", e[i * c + j]);
			}
			ss = s + strlen(s);
			sprintf(ss, "\n");
		}
	}
	printf("%s", s);
	return s;
}

template<typename T>
void MAT<T>::test_print() {
	
	if (typeid(e[0]) == typeid(long long int)) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				printf("%6lld", e[i * c + j]);
			}
			printf("\n");
		}
	}
	else if (typeid(e[0]) == typeid(int)) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				printf("%6ld", e[i * c + j]);
			}
			printf("\n");
		}
	}
	else if (typeid(e[0]) == typeid(float)) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				printf("%8f", e[i * c + j]);
			}
			printf("\n");
		}
	}
	else if (typeid(e[0]) == typeid(double)) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				printf("%8lf", e[i * c + j]);
			}
			printf("\n");
		}
	}
}

template MAT<int>;			//用于实验四，必须放在模板定义文件的尾部，用于强制实例化
template MAT<long long>;		//用于实验四，必须放在模板定义文件的尾部，用于强制实例化