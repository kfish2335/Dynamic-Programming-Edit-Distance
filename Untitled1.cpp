#include<iostream>
#include<algorithm>
#include <vector>
#include<fstream>
#include<stdlib.h>
using namespace std;
 
int min(int x, int y, int z)
{
	return min(min(x, y), z);
}

int eDDP(string str1, string str2, int m, int n)
{	
	
	int dp[m+1][n+1];

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{

			if (i == 0)
				dp[i][j] = j; 

			else if (j == 0)
				dp[i][j] = i;

			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
 
			else
				dp[i][j] = min(2 + dp[i][j - 1], 
					2 + dp[i - 1][j], 
					1 + dp[i - 1][j - 1]);
		}
	}

	return dp[m][n];
}

 
int main(int argc, char** argv)
{
	
	if (argc =! 2)
	{
		printf("Usage: data_file_1 data_file_2");
		exit(1);
	}

	vector<string> raw_data;
	const char* data_filename = argv[1];
	const char* data_filename1 = argv[2];
	
	ifstream infile(data_filename);
	raw_data.clear();
	string str1;
	
	while (infile.good())
		{
			infile >> str1;
			raw_data.push_back(str1);	
		}	
	infile.close();
	
	ifstream infile2(data_filename1);
	raw_data.clear();
	string str2;
	
	while (infile2.good())
		{
			infile2 >> str2;
			raw_data.push_back(str2);
		}	
	
	int eddistance = eDDP(str1, str2, str1.length(), str2.length());
	
	cout << "edited distance: "<< eddistance <<"\n";
	
	system("pause");
	return 0;
}
