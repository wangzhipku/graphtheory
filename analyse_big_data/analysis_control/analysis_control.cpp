#include "pch.h"
#include <conio.h>
#include <cstring>
#include <direct.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#pragma warning(disable : 4996)
#define yugu 8000 //预估有多少个filename
using namespace std;
void BubbleSort(int *p, int length, int *ind_diff); //从大到小排序,并且返回其之前对应的位置
int pure_zapanduan(char *a);
void backchar(char *name);
void backint(int *a);
int findxuhao(char *aa);
void backstruct(struct jilu jilua[93]);
void str_copy(char *in_element, char *b);
void generate_file(struct jilu jilua[93]);
struct panduan
{
	int flag;
	int local;
};
struct panduan aa;
struct panduan bb;
struct panduan *num_ifinshuzu(int test, int *a);
struct panduan *num_ifinshuzu_bb(int test, int *a);
char a[120][3] = { " ", "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lw", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg" };
struct jilu
{
	int xuhao;
	char xuhao_name[3]; //元素符号
	char four_filename[14][yugu][100];
	char six_filename[14][yugu][100];

	int four_filenum[14]; //记录和每种阴离子的4配位次数
	int six_filenum[14];  //记录和每种阴离子的6配位次数

	int four_type[14];
	int six_type[14];
};
struct jilu jilua[93];
void generate_file(struct jilu[93]);

int yang[93] = { 1, 3, 4, 5, 6, 11, 12, 13, 14, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111 };
int yin[14] = { 6, 7, 8, 9, 14, 15, 16, 17, 33, 34, 35, 52, 53, 85 }; //两者重叠的地方是C,Si，即我们认为这两个，既是中心阳离子，同时也能被当做阴离子放到配位环境中

int main()
{
	int i = 0, j = 0, k = 0;
	int eyer = 0;	  //判断每次得到的序号是不是要储存的阳离子
	int pure_flag = 0; //判断每次读到的是不是一个纯配位
	backstruct(jilua);
	char file_name[100];
	char temp[300];
	char name[50];
	char element[3];
	char in_element[3];
	int pei_num = 0;

	int ii = 0, jj = 0, kk = 0;

	FILE *input; //读取的out.txt文件

	for (i = 0; i < 20; i++)
	{
		backchar(name);
		strcpy(name, "out_");
		sprintf(temp, "%d", i);
		strcat(name, temp);
		strcat(name, ".txt");
		cout << name << endl;

		input = fopen(name, "r");

		if (NULL == input)
		{

			cout << "i can't find the file,please check the name!" << endl;
			cin.get();
		}
		backchar(temp);

		for (j = 0; !feof(input); j++)
		{
			fscanf(input, "%s\t", &file_name);
			fscanf(input, "%s\t", &element);
			fscanf(input, "%d\t", &pei_num);
			eyer = findxuhao(element);
			fgets(temp, 300, input); //读到了对应的配位情况

			pure_flag = pure_zapanduan(temp);
			panduan *point;
			point = num_ifinshuzu(eyer, yang);

			backchar(in_element);
			str_copy(in_element, temp);
			kk = findxuhao(in_element);
			panduan *in_point;
			in_point = num_ifinshuzu_bb(kk, yin); //此时bb结构体储存着其中，配位元素的信息

			if (!((pei_num == 6 && point->flag == 1 && pure_flag == 0 && in_point->flag == 1) || (pei_num == 4 && point->flag == 1 && pure_flag == 0 && in_point->flag == 1)))
			{
				backchar(element);
				backchar(in_element);
				backchar(file_name);
				backchar(temp);
				pei_num = 0;
				continue;
			}
			cout << pei_num << endl;
			cout << element << endl;
			cout << temp << endl;
			cout << in_element << endl;
			cin.get();

			//到这里说明读到的是有效的信息
			k = point->local;	 //此时k是中心离子在yang[]中的序号
			kk = in_point->local; //kk是边缘例子在yin【】中的序号

			if (pei_num == 4)
			{
				jilua[k].four_filenum[kk]++;
				for (ii = 0; ii < jilua[k].four_type[kk]; ii++)
				{
					if (strcmp(file_name, jilua[k].four_filename[kk][ii]) == 0)
					{
						break;
					}
				}
				if (ii == jilua[k].four_type[kk]) //说明是新的文件名
				{
					if (jilua[k].four_type[kk] == yugu)
					{
						cout << "the yugu has run out of" << endl;
						cin.get();
					}
					jilua[k].four_type[kk]++;
					strcpy(jilua[k].four_filename[kk][ii], file_name);
				}
			}
			else if (pei_num == 6)
			{
				jilua[k].six_filenum[kk]++;
				for (ii = 0; ii < jilua[k].six_type[kk]; ii++)
				{
					if (strcmp(file_name, jilua[k].six_filename[kk][ii]) == 0)
					{
						break;
					}
				}
				if (ii == jilua[k].six_type[kk]) //说明是新的文件名
				{
					if (jilua[k].six_type[kk] == yugu)
					{
						cout << "the yugu has run out of" << endl;
						cin.get();
					}
					jilua[k].six_type[kk]++;
					strcpy(jilua[k].six_filename[kk][ii], file_name);
				}
			}
			else
			{
				cout << "your code is wrong!please check!" << endl;
				cin.get();
			}

			backchar(temp);
			backchar(file_name);
			pei_num = 0;
			backchar(element);
			backchar(in_element);
		}
		backchar(name);
		backchar(element);
		cout << "have read the" << i << "file" << endl;
		fclose(input);
		backchar(in_element);
	}
	cout << "now lest's to generate the file!" << endl;
	generate_file(jilua);
	cout << "all work done" << endl;
	return 0;
}

void BubbleSort(int *p, int length, int *ind_diff) //从大到小排序,并且返回其之前对应的位置
{
	for (int m = 0; m < length; m++)
	{
		ind_diff[m] = m;
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (p[j] < p[j + 1])
			{
				float temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;

				int ind_temp = ind_diff[j];
				ind_diff[j] = ind_diff[j + 1];
				ind_diff[j + 1] = ind_temp;
			}
		}
	}
}
int pure_zapanduan(char *a)
{
	int i = 0, j = 0;
	char seps[] = " ,\t\n";
	char *token;
	int jishu = 0;
	int label = 0; //0说明是纯配合，1是杂配合

	for (i = 0; i < strlen(a); i++)
	{
		if (a[i] == '\t' || a[i] == ' ')
		{
			jishu++;
		}
	}
	char **save;
	save = new char *[jishu];
	for (i = 0; i < jishu; i++)
	{
		save[i] = new char[6];
	}

	token = strtok(a, seps);
	i = 0;
	while (token != NULL)
	{
		//printf("%s\n", token);

		strcpy_s(save[i], strlen(token) + 1, token);
		token = strtok(NULL, seps);
		i++;
	}
	for (i = 0; i < jishu; i++)
	{
		for (j = 0; j < jishu; j++)
		{
			if (i != j && strcmp(save[i], save[j]) != 0)
			{
				label = 1;
				break;
			}
		}
		if (label == 1)
		{
			break;
		}
	}

	for (i = 0; i < jishu; i++)
	{
		delete[] save[i];
	}

	delete save;

	return label;
}

void backchar(char *name)
{
	int i = 0;
	int k = strlen(name);
	for (i = 0; i < k; i++)
	{
		name[i] = '\0';
	}
}
int findxuhao(char *aa)
{
	int k = 0;
	for (k = 0; k < 120; k++)
	{
		if (strcmp(aa, a[k]) == 0)
		{
			break;
		}
	}
	return k;
}

void backint(int *a)
{
	int i = 0;
	int k = sizeof(a) / sizeof(int);
	for (i = 0; i < k; i++)
	{
		a[k] = '\0';
	}
}
void backstruct(struct jilu jilua[93])
{
	int i = 0, j = 0;
	int k = 0;
	for (i = 0; i < 93; i++)
	{
		jilua[i].xuhao = 0;

		backchar(jilua[i].xuhao_name);
		for (j = 0; j < 14; j++)
		{
			jilua[i].four_filenum[j] = 0;
			jilua[i].six_filenum[j] = 0;
			jilua[i].four_type[j] = 0;
			jilua[i].six_type[j] = 0;
			for (k = 0; k < yugu; k++)
			{
				backchar(jilua[i].four_filename[j][k]);
				backchar(jilua[i].six_filename[j][k]);
			}
		}
	}
	//到这里初始化完了全部的结构体
	//下面开始对结构体写入初始的数据
	for (i = 0; i < 93; i++)
	{
		jilua[i].xuhao = yang[i];
		strcpy(jilua[i].xuhao_name, a[yang[i]]);
	}
}

panduan *num_ifinshuzu(int test, int *a) //判断一个数是不是在一个数组里，是的话返回1，否则返回0
{
	int i, j;
	int flag = 0;
	panduan *a_point;
	a_point = &aa;

	j = sizeof(a) / sizeof(int);
	for (i = 0; i < j; i++)
	{
		if (test == a[i])
		{
			flag = 1;
			aa.local = i;
			break;
		}
	}
	if (i == j)
	{
		flag = 0;
	}
	aa.flag = flag;
	return a_point;
}
void str_copy(char *in_element, char *b)
{
	int i, j;
	j = strlen(b);
	for (i = 0; i < 2; i++)
	{
		if (b[i] != '\t')
		{
			in_element[i] = b[i];
		}
		else
			break;
	}
}

panduan *num_ifinshuzu_bb(int test, int *a) //判断一个数是不是在一个数组里，是的话返回1，否则返回0
{
	int i, j;
	int flag = 0;
	panduan *a_point;
	a_point = &bb;

	j = sizeof(a) / sizeof(int);
	for (i = 0; i < j; i++)
	{
		if (test == a[i])
		{
			flag = 1;
			bb.local = i;
			break;
		}
	}
	if (i == j)
	{
		flag = 0;
	}
	bb.flag = flag;
	return a_point;
}

void generate_file(struct jilu jilua[93])
{
	int i = 0, j = 0, k = 0;
	FILE *out;
	char name[50];
	char temp[50];
	int four = 4;
	int six = 6;
	for (i = 0; i < 93; i++)
	{
		strcpy(name, jilua[i].xuhao_name);

		for (j = 0; j < 14; j++)
		{
			strcat(name, "-");
			strcat(name, a[yin[j]]);
			strcpy(temp, name);
			strcat(name, ".txt");
			cout << name << endl;
			out = fopen(name, "w");
			fprintf(out, "%s\n", temp);//第一行写什么阳离子和阴离子配位
			//然后分别写4配位的情况和6配位的情况
			fprintf(out, "%d\t", four);
			fprintf(out, "%d\n", jilua[i].four_filenum[j]);


			for (k = 0; k < jilua[i].four_type[j]; k++)
			{
				fprintf(out, "%s\n", jilua[i].four_filename[j][k]);

			}

			fprintf(out, "\n");

			fprintf(out, "%d\t", six);
			fprintf(out, "%d\n", jilua[i].six_filenum[j]);
			for (k = 0; k < jilua[i].six_type[j]; k++)
			{
				fprintf(out, "%s\n", jilua[i].six_filename[j][k]);

			}


		}
		fclose(out);
		backchar(name);
		backchar(temp);
	}
}