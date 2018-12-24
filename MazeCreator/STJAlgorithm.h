#pragma once

#include <cstdio>

/*
	全排列算法

*/

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

class STJAlgorithm {

	public:

	STJAlgorithm();
	STJAlgorithm(const int &_seq_len);
	~STJAlgorithm();

	void init(const int &_seq_len);
	//	找下一种排列
	bool findnxt();
	int operator[](const int &x);
	bool operator ++();
	//	重置长度
	void set(const int &_seq_len);
	void print();
	int size();
	STJAlgorithm &operator=(STJAlgorithm &other);
	

	private:

	int *seq_front;
	int *dir_front;
	int *seq_rear;

	bool is_inside(int *suc_pos) 
	{
		return suc_pos >= seq_front && suc_pos < seq_rear;
	}
};
STJAlgorithm::STJAlgorithm()
{

}

STJAlgorithm::STJAlgorithm(const int&_seq_len)
{
	init(_seq_len);
}

STJAlgorithm::~STJAlgorithm()
{
	delete[] seq_front;
	delete[] dir_front;
}

void STJAlgorithm::init(const int &_seq_len)
{
	seq_front = new int[_seq_len];
	dir_front = new int[_seq_len];

	int *h1, *h2;
	h1 = seq_front;
	h2 = dir_front;

	for (int i = 0; i < _seq_len; ++i)
	{
		*h1 = i;
		*h2 = -1;
		++h1;
		++h2;
	}
	seq_rear = seq_front + _seq_len;
}

bool STJAlgorithm::findnxt()
{
	int *seq_pos, *dir_pos;
	seq_pos = NULL;
	dir_pos = NULL;

	int *h_seq = seq_front;
	int *h_dir = dir_front;

	for (; h_seq < seq_rear; ++h_seq, ++h_dir)
	{
		int *suc_pos = h_seq + *h_dir;

		if (is_inside(suc_pos) && *h_seq > *suc_pos)
		{
			if (seq_pos == NULL || *h_seq > *seq_pos)
			{
				seq_pos = h_seq;
				dir_pos = h_dir;
			}
		}
	}
	if (seq_pos == NULL)
	{
		return 0;
	}

	h_seq = seq_front;
	h_dir = dir_front;

	for (; h_seq < seq_rear; ++h_seq, ++h_dir)
	{
		if (*h_seq > *seq_pos)
		{
			*h_dir = -*h_dir;
		}
	}

	swap(*seq_pos, *(seq_pos + *dir_pos));
	swap(*dir_pos, *(dir_pos + *dir_pos));

	return 1;
}

int STJAlgorithm::operator[](const int &x)
{
	if (seq_front == NULL) return 0;

	if (!is_inside(seq_front + x))
	{
		return NULL;
	}
	return seq_front[x];
}

bool STJAlgorithm::operator ++()
{
	return findnxt();
}

void STJAlgorithm::set(const int &_seq_len)
{
	if (seq_front != NULL)
	{
		delete[] seq_front;
		delete[] dir_front;
	}
	init(_seq_len);
}

void STJAlgorithm::print()
{
	if (seq_front == NULL) return;

	int *h_seq = seq_front;

	for (; h_seq < seq_rear; ++h_seq)
	{
		printf("%d ", *h_seq);
	}
	putchar('\n');
}

int STJAlgorithm::size()
{
	if (seq_front == NULL) return 0;
	return seq_rear - seq_front;
}

STJAlgorithm &STJAlgorithm::operator=(STJAlgorithm &other)
{
	if (other.size() == 0) return *this;

	set(other.size());

	int *h_seq = seq_front;
	int *oh_seq = other.seq_front;

	int *h_dir = dir_front;
	int *oh_dir = other.dir_front;

	for (; h_seq < seq_rear;)
	{
		*h_seq = *oh_seq;
		++h_seq;
		++oh_seq;

		*h_dir = *oh_dir;
		++h_dir;
		++oh_dir;
	}

	return *this;
}