#pragma once


//	��̬ģ���ά���飬i/j �ֱ�Ϊ�������ά�����ֵ
//	���� defaultT ��ʼ��������

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