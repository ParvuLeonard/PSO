#define F (1 << 14)

/* x, y sunt numere in format fixed point 17.14; n este numar intreg */
int convert_int_fp(int n);
int convert_fp_int(int x);
int convert_fp_int_round(int x);
int add_fp_fp(int x, int y);
int substract_fp_fp(int x, int y);
int add_fp_int(int x, int n);
int substract_int_fp(int x, int n);
int multiply_fp_fp(int x, int y);
int multiply_fp_int(int x, int n);
int divide_fp_fp(int x, int y);
int divide_fp_int(int x, int n);

int convert_int_fp(int n)
{
	return n * F;
}

int convert_fp_int(int x)
{
	return x / F;
}

int convert_fp_int_round(int x)
{
	if (x>=0) 
	{
		return (x + F / 2) / F;
	} else
	{
		return (x - F / 2) / F;
	}
}

int add_fp_fp(int x, int y)
{
	return x + y;
}

int substract_fp_fp(int x, int y)
{
	return x - y;
}

int add_fp_int(int x, int n)
{
	return x + n * F;
}

int substract_int_fp(int x, int n)
{
	return x - n * F;
}

int multiply_fp_fp(int x, int y)
{
	return ((int64_t)x) * y / F;
}

int multiply_fp_int(int x, int n)
{
	return x * n;
}

int divide_fp_fp(int x, int y)
{
	return ((int64_t)x) * F / y;
}

int divide_fp_int(int x, int n)
{
	return x / n;
}
