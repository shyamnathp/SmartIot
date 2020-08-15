#include<Shape.h>
#include<Primes.h>
#include<vector>
#include<numeric>
#include<iterator>
#include<algorithm>

#include "gtest/gtest.h"

using namespace std;

int main()
{

	/*some tests based on google test assertions for Circle and Square class*/
	Circle cOne(2, 2, 2);
	Square sOne(1, 1, 1);

	EXPECT_EQ(cOne.FitInsideCircle(sOne), true);
	EXPECT_EQ(sOne.FitInsideSquare(cOne), false);
	
	Circle cTwo(3, 2, 1);
	Square sTwo(2.5, 2.5, 3);
	EXPECT_EQ(cTwo.GetArea(), float(3.14));
	EXPECT_EQ(cTwo.GetPerimeter(), float(6.28));
	EXPECT_EQ(cTwo.IsInside(float(3.2), float(1.2)), true);
	EXPECT_EQ(cTwo.FitInsideCircle(sTwo), false);

	EXPECT_EQ(sTwo.GetArea(), float(9));
	EXPECT_EQ(sTwo.GetPerimeter(), float(12));
	EXPECT_EQ(sTwo.IsInside(float(3.2), float(1.2)), true);
	EXPECT_EQ(sTwo.FitInsideSquare(cTwo), true);

	/*test for Sieves using both the approach mentioned in the sheet and a faster approach*/
	vector<int> testPrimes = Primes::Sieves(200);
	EXPECT_EQ(testPrimes.size(), 46);
}