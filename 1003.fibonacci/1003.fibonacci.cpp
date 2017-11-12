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
#include <utility>

using namespace std;

class Fib01Counter {
public:
        Fib01Counter(int n) {
                table_.resize(n + 1, make_pair(0, 0));
                table_[0].first = 1;
                table_[0].second = 0;
                table_[1].first = 0;
                table_[1].second = 1;
                for (int i = 2; i < n + 1; ++i) {
                        table_[i].first = table_[i-1].first+ table_[i-2].first;
                        table_[i].second = table_[i-1].second + table_[i-2].second;
                }
        }
        pair<int, int> Count(int n) {
                return table_[n];
        }
private:
        vector<pair<int, int> > table_;
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
		cout << result.first << " " << result.second << endl;
	}

	return 0;
}
