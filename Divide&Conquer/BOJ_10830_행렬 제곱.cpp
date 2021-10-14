#include <iostream>
class square_matrix;
square_matrix operator*(square_matrix& A, square_matrix& B);
class square_matrix
{
public:
	int** A;
	int N;

	square_matrix(int n) : N{ n }
	{
		A = new int* [N];
		for (int i = 0; i < N; ++i) A[i] = new int[N];
	}

	void input()
	{
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) std::cin >> A[i][j];
	}

	square_matrix pow(long long B)	//분할정복을 이용한 거듭제곱
	{
		if (B == 1) return *this;
		else if (B % 2) //A*A^(B-1)
		{
			square_matrix tmp = (this->pow(B - 1));
			return (*this) * tmp;
		}
		else //A^(B/2) * A^(B/2)
		{
			square_matrix tmp = (this->pow(B / 2));
			return tmp * tmp;
		}
	}

	void print()
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j) std::cout << A[i][j] % 1000 << ' ';
			std::cout << '\n';
		}
	}
};

square_matrix operator*(square_matrix& A, square_matrix& B)	//행렬의 곱 연산자 오버로딩
{
	square_matrix tmp(A.N);
	for (int i = 0; i < A.N; ++i)
	{
		for (int j = 0; j < A.N; ++j)
		{
			int n = 0;
			for (int k = 0; k < A.N; ++k)
			{
				n += A.A[i][k] * B.A[k][j] % 1000;
			}
			tmp.A[i][j] = n % 1000;
		}
	}
	return tmp;
}

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	long long B;
	std::cin >> N >> B;

	square_matrix A(N);
	A.input();
	A.pow(B).print();
}