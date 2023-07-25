#define _CRT_SECURE_NO_WARNINGS
#include "D:/SEAL-main/native/src/seal/seal.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include<chrono>
#include <C:/Users/administered/Desktop/idash2022/src/matrix.h>
#include "client.h"
#include"vector_processing.h"
#include"read_data.h"
using namespace std;
using namespace seal;

void main()
{
	string DATABASE_dir = "E:/iDASH2023/Client/input_data/DATABASE_SITE_genotypes.txt";



	auto start1 = chrono::high_resolution_clock::now();
	matrix<int64_t> DATABASE;
	read_data_DATABASE(DATABASE,DATABASE_dir);
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double_t> dur = end1 - start1;
	cout << "Reading the data costs " << dur.count() << " seconds" << endl;

	auto start2 = chrono::high_resolution_clock::now();
	matrix<int64_t> DATABASE_;
	read_data_faster(DATABASE_, DATABASE_dir,16344,2000);
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<double_t> dur1 = end2 - start2;
	cout << "Reading the data costs " << dur1.count() << " seconds" << endl;
	cout << DATABASE_.get_rows() << " " << DATABASE_.get_cols() << endl;
	int counter = 0;

	for (int i = 0; i < DATABASE_.get_rows(); i++)
	{
		for (int j = 0; j < DATABASE_.get_cols(); j++)
		{
			if (DATABASE_(i, j) == DATABASE(i, j))
			{
				counter++;
			}
		}
	}
	if (counter == DATABASE.get_rows() * DATABASE.get_cols())
	{
		cout << "the amended algorithm produces correct result." << endl;
	}
}