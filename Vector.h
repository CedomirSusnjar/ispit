#pragma once
#include <initializer_list>
#include <iostream>
#include <functional>
template <class T,int N>
class Vector
{
private:
	static_assert(N > 0, "Invalid number of elements!");
	int n = N;
	T* niz;
	void copy(const Vector<T,N>&);
	void move(Vector&&);
	std::ostream& print(std::ostream&, std::function<bool(T)>);
	template <class A, int M>
	friend std::ostream& operator<<(std::ostream&, const Vector<A,M>&);
public:
	Vector(std::initializer_list<T>&);
	Vector(const Vector&);
	Vector(Vector&&);
	~Vector();
	constexpr int size() const;

	Vector& operator=(const Vector&);
	Vector& operator+(const Vector&);
};

