#include "Primes.h"
#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <chrono> 

using namespace std::chrono;
using namespace std;


Primes::Primes()
{
}

//This is the original assignment answer with the specifications given in the sheet
//This is consise but has a complexity of O(n^2)
vector<int> Primes::Sieves(int n)
{
	auto start = high_resolution_clock::now();

	vector<int> primes(n-1);
	std::iota(primes.begin(), primes.end(), 2);

	for (int i = 2; i*i <= n; ++i)
	{

		primes.erase(
		std::remove_if(primes.begin() + i, primes.end(),[&](int num)
		{
			return num % i == 0;
		}), primes.end());
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	auto time= duration.count();
	return primes;
}

Primes::~Primes()
{
}
