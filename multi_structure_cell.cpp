//
// compare_multifiles.cpp
//  compare structures and delete the same files
//
//  Created by 王志 on 2019/6/27.
//  Copyright © 2019年 王志. All rights reserved.
//
#include <sys/types.h>
#include <omp.h>
#include <cstdio>
#include <cstring>
//#include <unistd.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#pragma warning(disable : 4996)
using namespace std;
void analyse_compare_result(char* filename, char* twod_name, char * result_file, int NUM);
int main(int argc, const char *argv[])
{
	const int NUM =2830;
	const int ROW = 3420;
	bool if_only_analyse = true;
	//cin.get();
	string* name = new string[NUM];
	string path = "/share/home/wangz/2d_search/2d_last_modi_exclude/2d_config/af_delsame/strcell/";
	int stru_jump[NUM] = { 0 };//用来控制把谁扔出去
	//string name[NUM];
	int i = 0, j = 0, k = 0;
	//cout << "stop1" << endl;
	char file_name[200];
	char twod_name[200];	
	char result_file[200] = "strcure_results_for 3layer";
	if (if_only_analyse == true)
	{
		cout << "3 paramters,they are compare_results path,2d_name path and result path!" << endl;
		for (i = 0; i < argc; i++)
		{
			if (i = 1)
			{
				for (j = 0; j < strlen(argv[1]); j++)
				{
					file_name[j] = argv[1][j];
				}
				file_name[strlen(argv[1])] = '\0';
			}
			if (i = 2)
			{
				for (j = 0; j < strlen(argv[2]); j++)
				{
					twod_name[j] = argv[2][j];
				}
				twod_name[strlen(argv[2])] = '\0';
			}
			if (i = 3)
			{
				for (j = 0; j < strlen(argv[3]); j++)
				{
					result_file[j] = argv[3][j];
				}
				result_file[strlen(argv[3])] = '\0';
			}
		}
		cout << "file_name is :" << file_name << endl;
		cout << "twod name is :" << twod_name << endl;
		analyse_compare_result(file_name,twod_name,result_file,NUM);
		cout << "analyse results finished!" << endl;
		return 1;
	}




	ifstream fin;
	fin.open("2d_files", ios::in);
	if (!fin.is_open())
	{
		cout << "i can not find the name txt!" << endl;
		cin.get();
	}
	while (fin.good() && i<NUM)
	{
		fin >> name[i];
		name[i] = path + name[i];
		i++;
	}
	fin.close();
	string atom[25][2];
	//开始进行命令拼接
	char command_temp[200] = "./strcell_3.out ";

	//cout << "stop2" << endl;


	int **compare = new int *[NUM];
	for (i = 0; i < NUM; i++)
	{
		compare[i] = new int[NUM];
	}
	for (i = 0; i < NUM; i++)
	{
		for (j = 0; j < NUM; j++)
		{
			compare[i][j] = 0;
			if (i == j)
				compare[i][j] = 1;
		}
	}

	//int compare[ROW][NUM] = { {0} };//修改一下这里，把这个二维数组的大小控制一下
	int n = 0;
	char command[25][300];
	//pid_t call[25];
	//从这里开始并行的进行跑图的结构基元获取
#pragma omp parallel for  private(n,j) shared(compare) schedule(dynamic)
	for (i = 0; i < ROW; i++)
	{
		//cout << "now is the " << omp_get_thread_num() << " fork" << endl;
		//if (name[i] == "" || name[i] == "\0" || name[i] == " ")
		//	break;
		if (i % 100 == 0)
		{
			cout << "has gone " << i << " files" << endl;
		}


#pragma omp critical
		{
			n = omp_get_thread_num();
			//fscanf(name, "%s", now_name[n]);
			//cout << "the threads xuhao  is:" << n << endl;
			//cout << "the name is:" << now_name[n] << endl;
			//cin.get();
		}
		for (j = 0; j < NUM; j++)
		{
			if (name[j] == "")
				break;
			atom[n][0] = name[i];
			atom[n][1] = name[j];

			strcpy(command[n], command_temp);
			strcat(command[n], atom[n][0].c_str());
			strcat(command[n], " ");
			strcat(command[n], atom[n][1].c_str());
			//cout << command << endl;
			//cin.get();
			compare[i][j] = system(command[n]);
			if (compare[i][j] != 0)
			{
				compare[i][j] = 1;
				
			}
			

		}
	}
	//然后我们把结果输出出来，用来做后面的分析
	ofstream fout;
	fout.open("compare1_1", ios::out);
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < NUM; j++)
		{
			fout << compare[i][j];
			fout << "\t";
		}
		fout << endl;
	}
	fout.close();


	//next to analysize the compare results!
	//通过调用子函数就行
	delete[]name;
	for (i = 0; i < NUM; i++)
	{
		delete[]compare[i];
	}
	delete[]compare;
	cout << "all total work done!" << endl;
	//cin.get();
	return 0;

}


void analyse_compare_result(char* filename, char* twod_name,char * result_file, int NUM)
{
	//输入是n*n的二维矩阵,还有结构的文件名，输出是进行分类好后的文件
	int i = 0, j = 0;	
	int**compare = new int*[NUM];
	for (i = 0; i < NUM; i++)
	{
		compare[i] = new int[NUM];
	}
	for (i = 0; i < NUM; i++)
	{
		for (j = 0; j < NUM; j++)
		{
			compare[i][j] = 0;
		}
		
	}
	ifstream fin;
	fin.open(filename, ios::in);
	for (i = 0; i < NUM; i++)
	{
		for (j = 0; j < NUM; j++)
		{
			fin>>compare[i][j];
		}

	}
	fin.close();

	//读入结构文件名
	string*name = new string[NUM];	
	fin.open(twod_name, ios::in);
	for (i = 0; i < NUM; i++)
	{		
		fin >> name[i];
	}
	fin.close();


	ofstream  out;
	out.open(result_file, ios::out);
	//下面开始进行正式进行分类了
	int row = 0;//控制写入的行数
	int *flag = new int[NUM];
	for (i = 0; i < NUM; i++)
	{
		flag[i] = 0;
	}
	for (i = 0; i < NUM; i++)
	{
		if (flag[i] == 0)
		{
			out << name[i] << "\t";
			flag[i] = 1;
		}
		else
		{
			continue;
		}
		
		for (j = 0; j < NUM; j++)
		{
			if (compare[i][j] == 1 && compare[j][i] == 1 && flag[j]==0)
			{
				out << name[j] << "\t";
				flag[j] = 1;
			}
		}
		out << endl;
	}
	

	out.close();





	delete[]flag;
	delete[]name;
	for (i = 0; i < NUM; i++)
	{
		delete[]compare[i] ;
	}
	delete[]compare;
	return;

}
