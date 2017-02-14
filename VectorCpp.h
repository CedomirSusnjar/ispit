#pragma once
#include "Vector.h"

template<class T, int N>
void Vector<T, N>::copy(const Vector<T, N>& vec)
{
	std::copy(vec.niz, vec.niz + vec.n, niz);
}

template<class T, int N>
void Vector<T, N>::move(Vector &&vec)
{
	niz = vec.niz;
	n = vec.n;
}

template<class T, int N>
std::ostream& Vector<T, N>::print(std::ostream &str, std::function<bool(T)>f)
{
	for (int i = 0; i < n; i++)
		if (f(niz[i]))
			str << niz[i] << std::endl;
	return str;
}

template<class T, int N>
std::ostream& operator<<(std::ostream &str, const Vector<T, N>& vec)
{
	for (int i = 0; i < vec.n; i++)
		str << vec.niz[i] << " ";
	return str;
}

template<class T, int N>
Vector<T, N>::Vector(std::initializer_list<T>& a)
{
	if (N != a.size())
		throw std::out_of_range("Invalid number of elements!!");
	niz = new T[n]; int i = 0;
	for (T t : a)
		niz[i++] = t;
}

template<class T, int N>
Vector<T, N>::Vector(const Vector &vec)
{
	copy(vec);
}

template<class T, int N>
Vector<T, N>::Vector(Vector &&vec)
{
	move(std::move(vec));
}

template<class T, int N>
Vector<T, N>::~Vector() { delete[] niz; }

template<class T, int N>
constexpr int Vector<T, N>::size() const { return n; }

template<class T, int N>
Vector<T,N>& Vector<T, N>::operator=(const Vector<T, N> &vec)
{
	if (this == &vec)return *this;
	copy(vec);
	return *this;
}

template<class T, int N>
Vector<T,N>& Vector<T, N>::operator+(const Vector<T,N>& vec)
{
	std::initializer_list<int> a = { 1,2,3 };
	Vector<T, N> pom(a);
	for (int i = 0; i < n; i++)
		pom.niz[i] = niz[i] + vec.niz[i];
	return pom;
}
