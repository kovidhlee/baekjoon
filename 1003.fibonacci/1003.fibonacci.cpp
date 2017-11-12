/*
URL: https://www.acmicpc.net/problem/1003
문제: 40과 같거나 작은N이 주어졌을 때, fibonacci(N)이 0과 1을 각각 몇 번 출력되는지 구하시오.
int fibonacci(int n) {
	if (n==0) {
		printf("0");
		return 0;
	} else if (n==1) {
		printf("1");
		return 1;
	} else {
		return fibonacci(n‐1) + fibonacci(n‐2);
	}
}
결과: 성공
*/
#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Fib01Counter {
public:
        Fib01Counter(int n) {
                fib_.resize(n + 1);
                fib_[0][0] = 1;
                fib_[0][1] = 0;
                fib_[1][0] = 0;
                fib_[1][1] = 1;
                for (int i = 2; i < n + 1; ++i) {
                        for (int j = 0; j < 2; ++j) {
                                fib_[i][j] = fib_[i-1][j]+ fib_[i-2][j];
                        }
                }
        }
        array<int, 2> Count(int n) {
                return fib_[n];
        }
private:
        vector<array<int, 2> > fib_;
};

int main()
{
        Fib01Counter counter(40);
	int nInput = 0;
	cin >> nInput;

	for (int i = 0; i < nInput; i++)
	{
                int n;
                cin >> n;
                auto result = counter.Count(n);
		cout << result[0] << " " << result[1] << endl;
	}

	return 0;
}
