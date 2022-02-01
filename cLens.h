#pragma once
class cLens
{
	int k;

	double* r;
	double* d;
	double* N;

	void alloc();
	void free();

public:
	cLens();
	virtual ~cLens();

	int		Get_k();
	void    Set_k(int val);

	double  Get_r(int i);
	void    Set_r(int i, double val);

	double  Get_d(int i);
	void    Set_d(int i, double val);

	double  Get_N(int i);
	void    Set_N(int i, double val);

	double  FocalLength();

	double  Return_456_cLens();
};

