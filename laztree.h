#include "stdafx.h"
#include <bits/stdc++.h>
#define scanf scanf_s
using namespace std;
#define SIZE 100000
#define INDEX 1
#define IDENTITY 0
int N;
CLASS arr[SIZE + INDEX];
CLASS _[SIZE * 2 ], __[SIZE*2],___[SIZE*2];
template<typename T>
inline T Group(T a, int b) {
	//type in the function that is equivilent to applying "Union" 'b' times
}
template<typename T>
inline T Union(T a, T b) {
	//type in any union function that is commutative, associative, and has an identity
}
void init() {
	int i;
	for (i = INDEX; i < INDEX + N; i++) {
		_[i + N - INDEX] = arr[i]; ___[i + N - INDEX] = 1;
	}
	for (i = N - 1; i != 0; i--) {
		_[i] = Union(_[i << 1], _[i << 1 ^ 1]); ___[i] = ___[i << 1] + ___[i << 1 ^ 1];
	}
	for (i = 1; i < 2 * N; i++)__[i] = IDENTITY;
}
template<typename T>
void update(int here,int there, T val) {
	here += N - INDEX; there += N - INDEX;
	for (; here <= there; here >>= 1, there >>= 1) {
		if (here % 2 != 0)  __[here] = Union(__[here], Group(val, ___[here]));
		if (there % 2 != 1) __[there] = Union(__[there], Group(val, ___[there]));
	}
}
auto query(int here,int there) {
	auto ret = IDENTITY;
	here += N - INDEX; there += N - INDEX;
	for (; here <= there; here >>= 1, there >>= 1) {
		if (here % 2 != 0) {
			ret = Union(ret, _[here] = Union(_[here], __[here])); __[here++] = IDENTITY;
		}
		if (there % 2 != 1) {
			ret = Union(ret, _[there] = Union(_[there], __[there])); __[there--] = IDENTITY;
		}
	}
	return ret;
}