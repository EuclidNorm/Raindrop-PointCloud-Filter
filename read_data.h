#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <C:/Users/administered/Desktop/idash2022/src/matrix.h>
using namespace std;

void read_data_faster(matrix<int64_t>& Ma, string& filename, int64_t rows, int64_t cols)
{
    fstream in(filename);
    if (!in.is_open())
    {
        cout << "open .txt fail!" << endl;
        return;
    }

    string line;
    Ma.resize(rows, cols); // 注意需要resize，和txt文件中矩阵的维度对应
    for (int i = 0; i < rows; i++)
    {
        //cout << "Reading " << i+1 << "th line." << endl;
        getline(in, line);
        int nSPos = 0, nEPos = 0;
        nSPos = line.find('\t', nSPos); // 第1个tab键
        nSPos++;
        nSPos = line.find('\t', nSPos); // 第2个tab键
        nSPos++;
        nSPos = line.find('\t', nSPos); // 第3个tab键
        nSPos++;
        nSPos = line.find('\t', nSPos); // 第4个tab键
        // nSPos++;//到第五项开始的位置
        nSPos++;
        for (int j = 0; j < cols; j++)
        {

            Ma(i, j) = line[nSPos + j * 2] - '0';

        }
    }
}
