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
#include <cmath>
#include <iomanip>

using namespace std;

double mean(vector<int> v, int n);
double max(vector<int> v, int n);
double min(vector<int> v, int n);
double variance(vector<int> v, int n, double means);
double stdDev(double var);
bool results(int v, double, double);

int main()
{
	ifstream fin;
	ifstream fin1;
	ofstream fout;
	int coupon;
	double steelAvg, graphiteAvg, steelVar, graphiteVar, steelSD, graphiteSD;
	bool steelResult, graphiteResult;
	
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
	fout << fixed << setprecision(2);
	fout << "\t\t\t\tSteel"<< "\t\t" << "Graphite" << endl;
	fout << "Mean:\t\t\t" << steelAvg << "\t" << graphiteAvg << endl;
	
	steelVar = variance(steel, steel.size(), steelAvg);
	graphiteVar = variance(graphite, graphite.size(), graphiteAvg);
	fout << "Variance: \t\t" << steelVar << "\t"<< graphiteVar << endl;

	steelSD = stdDev(steelVar);
	graphiteSD = stdDev(graphiteVar);
	fout << "StdDeviation: \t" << steelSD << "\t\t"<< graphiteSD <<endl << endl;
	
	fout << "\tViable Coupons" << endl << endl;
	
	fout << "\tSteel\tGraphite" << endl;
	
	
	for(int i = 0; i < steel.size(); i++)
	{
		steelResult = results(steel[i], steelSD, steelAvg);
		graphiteResult = results(graphite[i], graphiteSD, graphiteAvg);
		if(steelResult == 1)
		{
			if(graphiteResult == 1)
			{
				fout << "\t" << steel[i] << "\t" << graphite[i]<< endl;	
			}
			else
				fout << "\t" << steel[i] << endl;		
		}
		else if(graphiteResult == 1)
		{
			if(steelResult == 1)
			{
				fout << "\t" << steel[i] << "\t" << graphite[i]<< endl;	
			}
			else
				fout << "\t\t" << graphite[i]<< endl;
		}

	}
	
	fin.close();
	fin1.close();
	fout.close();
	return 0;
}// End of main

//***************************************************************
double mean(vector<int> v, int n)
{
    int total = 0;//sum of all elements in the vector v.
    double avg;//the average or mean 
    for (int i = 0; i < n; i++)
    {
        total += v[i];
    }
    avg = static_cast<double>(total) / n;
	return avg;//return the average or mean
} // End of mean

//***************************************************************
double max(vector<int> v, int n)
{
	int max = v[0];
	for(int ix = 0; ix < n; ix++)
	{
		if(v[ix] > max)
		{
			max = v[ix];
		}
	}
	
	return max;
}// End of max

//***************************************************************
double min(vector<int> v, int n)
{
	int min = v[0];
    for(int i = 0; i < n; i++)
    {
        if(v[i] < min)
        {
            min = v[i];
        }
    }
	return min;
} // End of min

//***************************************************************
double variance(vector<int> v, int n , double means)
{
	double sum = 0.0;
	for(int i = 0; i < n; i++)
	{
	  sum += pow( (v[i] - means) , 2 );//(v[i] - mean)^2  
	}
	return (sum / n);//take the average and return the result.
} // End of variance

//***************************************************************
double stdDev(double var)
{
	return sqrt(var);
} // End of StdDev

//***************************************************************
bool results(int v, double deviation, double means)
{
	return((v - (deviation * 3)) >= 1600);
}