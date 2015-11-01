// Bianca Hernandez
// Coleman Johnston
// Lesley Amezcua
// Created: 10/30/15
// Summary: 
//
//**********************************************************************
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;
double mean(vector<int> v, int n);
double maxMin(vector<int> v, int n);
double variance(vector<int> v, int n, double means);
double StdDev(double var);

int main()
{
	ifstream fin;
	ifstream fin1;
	ofstream fout;
	int coupon;
	double steelAvg, graphiteAvg, steelVar, graphiteVar, steelSD, graphiteSD;
	
	fin.open("data1.txt");
	fin1.open("data2.txt");
	fout.open("results.txt");
	
	if(fin.fail() || fin1.fail() || fout.fail())
	{
		cout << "Error Opening file. " << endl;
		exit(1);
	}
	
	vector<int> steel;
	vector<int> graphite;
	
	while(fin >> coupon)
	{
		steel.push_back(coupon);
	}
	while(fin1 >> coupon)
	{
		graphite.push_back(coupon);
	}
	
	steelAvg = mean(steel, steel.size());
	graphiteAvg = mean(graphite, graphite.size());
	steelVar = (steel, steel.size(), steelAvg);
	graphiteVar = (graphite, graphite.size(), graphiteAvg);
	steelSD = steelVar;
	graphiteSD = graphiteVar;
	
	fin.close();
	fin1.close();
	fout.close();
	return 0;
}
double mean(vector<int> v, int n)
{
    int total = 0;
    double avg;
    for (int i = 0; i < n; i++)
    {
        total += v[i];
    }
    avg = static_cast<double>(total) / n;
	return avg;
}
double maxMin(vector<int> v, int n)
{
	return  3.4;
}
double variance(vector<int> v, int n , double means)
{
	return 3.4;
}
double StdDev(double var)
{
	return 3.4;
}
