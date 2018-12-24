#pragma once


//	动态模板二维数组，i/j 分别为数组的两维度最大值
//	并用 defaultT 初始化该数组

template<class T>
class Array2D
{
	public:

	T *operator[](const int &_i);

	virtual void init(const int &_i, const int &_j);
	virtual void show();

	protected:

	int i, j;
	T *buf;
};

template<class T>
T *Array2D<T>::operator[](const int &_i)
{
	return buf + _i * j;
}

template<class T>
void Array2D<T>::init(const int &_i, const int &_j)
{
	
}

template<class T>
void Array2D<T>::show()
{

}