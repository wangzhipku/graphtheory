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
#define yugu 8000 //Ԥ���ж��ٸ�filename
using namespace std;
void BubbleSort(int *p, int length, int *ind_diff); //�Ӵ�С����,���ҷ�����֮ǰ��Ӧ��λ��
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
	char xuhao_name[3]; //Ԫ�ط���
	char four_filename[14][yugu][100];
	char six_filename[14][yugu][100];

	int four_filenum[14]; //��¼��ÿ�������ӵ�4��λ����
	int six_filenum[14];  //��¼��ÿ�������ӵ�6��λ����

	int four_type[14];
	int six_type[14];
};
struct jilu jilua[93];
void generate_file(struct jilu[93]);

int yang[93] = { 1, 3, 4, 5, 6, 11, 12, 13, 14, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111 };
int yin[14] = { 6, 7, 8, 9, 14, 15, 16, 17, 33, 34, 35, 52, 53, 85 }; //�����ص��ĵط���C,Si����������Ϊ���������������������ӣ�ͬʱҲ�ܱ����������ӷŵ���λ������

int main()
{
	int i = 0, j = 0, k = 0;
	int eyer = 0;	  //�ж�ÿ�εõ�������ǲ���Ҫ�����������
	int pure_flag = 0; //�ж�ÿ�ζ������ǲ���һ������λ
	backstruct(jilua);
	char file_name[100];
	char temp[300];
	char name[50];
	char element[3];
	char in_element[3];
	int pei_num = 0;

	int ii = 0, jj = 0, kk = 0;

	FILE *input; //��ȡ��out.txt�ļ�

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
			fgets(temp, 300, input); //�����˶�Ӧ����λ���

			pure_flag = pure_zapanduan(temp);
			panduan *point;
			point = num_ifinshuzu(eyer, yang);

			backchar(in_element);
			str_copy(in_element, temp);
			kk = findxuhao(in_element);
			panduan *in_point;
			in_point = num_ifinshuzu_bb(kk, yin); //��ʱbb�ṹ�崢�������У���λԪ�ص���Ϣ

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

			//������˵������������Ч����Ϣ
			k = point->local;	 //��ʱk������������yang[]�е����
			kk = in_point->local; //kk�Ǳ�Ե������yin�����е����

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
				if (ii == jilua[k].four_type[kk]) //˵�����µ��ļ���
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
				if (ii == jilua[k].six_type[kk]) //˵�����µ��ļ���
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

void BubbleSort(int *p, int length, int *ind_diff) //�Ӵ�С����,���ҷ�����֮ǰ��Ӧ��λ��
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
	int label = 0; //0˵���Ǵ���ϣ�1�������

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
	//�������ʼ������ȫ���Ľṹ��
	//���濪ʼ�Խṹ��д���ʼ������
	for (i = 0; i < 93; i++)
	{
		jilua[i].xuhao = yang[i];
		strcpy(jilua[i].xuhao_name, a[yang[i]]);
	}
}

panduan *num_ifinshuzu(int test, int *a) //�ж�һ�����ǲ�����һ��������ǵĻ�����1�����򷵻�0
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

panduan *num_ifinshuzu_bb(int test, int *a) //�ж�һ�����ǲ�����һ��������ǵĻ�����1�����򷵻�0
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
			fprintf(out, "%s\n", temp);//��һ��дʲô�����Ӻ���������λ
			//Ȼ��ֱ�д4��λ�������6��λ�����
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