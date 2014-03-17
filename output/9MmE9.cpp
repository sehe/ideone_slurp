// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-09-10 15:39:48
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>

static constexpr auto MOD = 1000000007LL;

inline /*hint hint*/ long long mod(long long x)
{
    if (x >= 0 && x < MOD) return x;

    x %= MOD;
    if (x < 0)
        return x + MOD;

    return x;
}

struct matrix
{
	long long m[4][4];

	static matrix multiply(const matrix &a, const matrix &b)
	{
		matrix c;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				c.m[i][j] = 0;
				for (int k = 0; k < 4; k++)
					c.m[i][j] += a.m[i][k] * b.m[k][j];
			}

		return c;
	}

	void normalize()
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				m[i][j] = mod(m[i][j]);
	}
};

static matrix operator*(matrix const& a, matrix const& b)
{
	return matrix::multiply(a,b);
}

template <typename T>
T pow(T const&a, long long n)
{
    if (n == 0) throw "not implemented";
    if (n == 1) return a;

    auto b = pow(a*a, n>>1);

	return (n & 1)? b*a : b;
}

int main()
{
	//std::cout << "pow(2,  0): " << pow(2,  0) << std::endl;
	std::cout << "pow(2,  1): " << pow(2ll,  1) << std::endl;
	std::cout << "pow(2,  2): " << pow(2ll,  2) << std::endl;
	std::cout << "pow(2,  3): " << pow(2ll,  3) << std::endl;
	std::cout << "pow(2,  4): " << pow(2ll,  4) << std::endl;
	std::cout << "pow(2,  5): " << pow(2ll,  5) << std::endl;
	std::cout << "pow(2, 10): " << pow(2ll, 10) << std::endl;
	std::cout << "pow(2, 16): " << pow(2ll, 16) << std::endl;
	std::cout << "pow(2, 32): " << pow(2ll, 32) << std::endl;

	matrix v = { { { 1,2,3,4}, { 2,3,4,5},
		           { 3,4,5,6}, { 7,8,9,0} } };

	for (long i = 0; i< (1ul << 22ul); ++i)
	{
		auto e = pow(v, 16);
		e.normalize();
	}
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
