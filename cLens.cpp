#include "pch.h"
#include "cLens.h"
#include <stdio.h>
#include <iostream>


int main() {

	cLens lens;

	lens.Set_r(1, 100);
	lens.Set_r(2, -100);
	lens.Set_d(1, 10);
	lens.Set_N(0, 1.0);
	lens.Set_N(1,1.5);
	lens.Set_N(2, 1.0);


	double focal_length;
	focal_length = lens.FocalLength();
	std::cout << focal_length << std::endl;

}


void cLens::alloc() {

	r = new double[k + 1];
	d = new double[k + 1];
	N = new double[k + 1];

}

void cLens::free() {

	delete[] r;
	delete[] d;
	delete[] N;
}

cLens::cLens() {
	k = 2;
	alloc();
}

cLens::~cLens() {
	free();
}

int cLens::Get_k() {
	return k;
}

void cLens::Set_k(int val) {
	free();
	k = val;
	alloc();
}

double cLens::Get_r(int i) {
	if (1 <= i && i <= k) return r[i]; else return 0;
}

void cLens::Set_r(int i, double val) {
	if (1 <= i && i <= k) r[i] = val;
}


double cLens::Get_d(int i) {
	if (1 <= i && i <= k) return d[i]; else return 0;
}

void cLens::Set_d(int i, double val) {
	if (1 <= i && i <= k) d[i] = val;
}


double cLens::Get_N(int i) {
	// if (1 <= i && i <= k) return N[i]; else return 0;
    if (0 <= i && i <= k) return N[i]; else return 0; // 2021-11-04追記
}

void cLens::Set_N(int i, double val) {
	// if (1 <= i && i <= k) N[i] = val;
	if (0 <= i && i <= k) N[i] = val;    // 2021-11-04追記
}

// rdnをセットしたのちに使用可能
double cLens::FocalLength() {
	int i;
	double p, e;
	double A = 1, B = 0, C = 0, D = 1;
	double A1, B1, C1, D1;

	for (i = 1; i <= k; ++i) {
		p = r[i] == 0 ? 0 : (N[i] - N[i - 1]) / r[i];
		e = d[i] / N[i];

		A1 = A; B1 = B; C1 = A * p + C; D1 = B * p + D;
		A = A1; B = B1; C = C1; D = D1;

		if (i < k) {
			A1 = A - C * e; B1 = B - D * e; C1 = C; D1 = D;
			A = A1; B = B1; C = C1; D = D1;
		}
	}
	return C == 0 ? 1e30 : 1.0 / C;
}

double cLens::Return_456_cLens()
{
	return 456.789;
}
