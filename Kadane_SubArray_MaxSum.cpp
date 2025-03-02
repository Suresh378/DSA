#include<iostream>
#include<vector>
#include<climits>


int KadaneAlgo(const std::vector<int>& nInputVector)
{
	int nMaxSum = INT_MIN;
	int nCurrentSum = 0, nStart = 0, nEnd = 0;

	for (int i = 0; i < nInputVector.size(); i++)
	{
		nCurrentSum += nInputVector[i];

		if (nMaxSum < nCurrentSum)
		{
			nMaxSum = nCurrentSum;
			nEnd = i;
		}

		if (nCurrentSum < 0)
		{
			nStart = i + 1;
			nCurrentSum = 0;
		}
	}

	std::cout << "\nMax sum of Sub Array is " << nMaxSum << "\n" << std::endl;
	std::cout << "Sub Array is [" ;

	for (int i = nStart; i < nEnd + 1; i++)
	{
		std::cout << nInputVector[i];
		if(i != nEnd)
			std::cout << ",";
	}
	std::cout << "]" << std::endl;
	return nMaxSum;
}



int main()
{
	std::cout << "Enter the Array count\n" << std::endl;

	int nCount = 0;

	std::cin >> nCount;

	std::cout << "Enter the Array elements\n" << std::endl;

	std::vector <int> nInputVector(nCount, 0);

	for (int i = 0; i < nCount; i++)
	{
		std::cin >> nInputVector[i];
	}

	std::cout << "Using Kadane's Alorithm to find the Max sum of Sub Array" << std::endl;

	KadaneAlgo(nInputVector);
}