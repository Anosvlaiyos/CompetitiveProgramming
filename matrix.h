#include "stdafx.h"
#define scanf scanf_s
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007LL
template <typename T>
struct matrix {
	T **nums;
	int	r, c;
	matrix(int rr, int cc) {
		r = rr; c = cc;
		nums = (T **)malloc(r * sizeof(T *));
		for (int i = 0; i<r; i++) nums[i] = (T *)malloc(c * sizeof(T));
		for (int i = 0; i < r; i++)for (int j = 0; j < c; j++)nums[i][j] = 0;
	}
	T* operator[](int x) { return nums[x]; }
	matrix<T> operator*(matrix a) {
		matrix b = matrix(r, a.c);
		int i, j, k;
		for (i = 0; i < r; i++)for (j = 0; j < c; j++)for (k = 0; k < a.c; k++)b[i][k] += nums[i][j] * a[j][k];
		return b;
	}
	matrix<T> operator+(matrix a) {
		matrix b = matrix(r,c);
		int i, j;
		for (i = 0; i < r; i++)for (j = 0; j < c; j++)b[i][j] = nums[i][j] + a[i][j];
		return b;
	}
	matrix<T> operator-(matrix a) {
		matrix b = matrix(r, c);
		int i, j;
		for (i = 0; i < r; i++)for (j = 0; j < c; j++)b[i][j] = nums[i][j] - a[i][j];
		return b;
	}
	matrix<T> operator^(int p) {
		if (p == 1)return *this;
		matrix h = (*this) ^ (p / 2);
		h = h * h;
		if (p % 2)h = h * (*this);
		return h;
	}
	matrix<T> operator=(matrix a){
		
	}
	void print() {
		int i, j;
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) printf("%d ",nums[i][j]);
			printf("\n");
		}
	}
};
int main() {
	int i, j;
	matrix<int> a = matrix(2,2);
	a[0][0] = 1; a[0][1] = 1;
	a[1][0] = 1; a[1][1] = 0;
	(a^1000000000).print();
	getchar(); getchar();
}