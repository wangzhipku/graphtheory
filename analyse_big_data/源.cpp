#include <direct.h>
#include <fstream>
#include <cstring>
#include <iostream>
#include <math.h>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <conio.h>
#pragma warning(disable : 4996)
#define yugu 50000
#define peiwei 40
using namespace std;
char a[120][3] = { " ", "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lw", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg" };
int getNumberOfEdges(char fileName[]);
void backchar(char *name);
int findxuhao(char *aa);
void outprint(FILE *out, struct jilu jilua[120]);
void BubbleSort(int *p, int length, int *ind_diff);
void peiwei_mode_paixu(struct jilu jilua[120]);
void tiaoshu_tongji(struct jilu jilua[120]);
int pure_zapanduan(char*a);
void peiwei_num_tj(struct jilu jilua[120]);
void pure_tj(struct jilu jilua[120]);
void peiwei_mode_tj(struct jilu jilua[120]);

void pure__plus_peiwei_num_tj(struct jilu jilua[120]);

void backint(int *a);
int local[120][yugu];
FILE *out;


struct jilu
{
	int xuhao;
	char xuhao_name[3];//Ԫ�ط���
	//std::string mode[yugu];
	int jishu[yugu];//��Ӧ��λ���ĳ��ִ���
	int peiwe_num[yugu];//��Ӧ��λ������λ��
	int mode_num;//��λ������
	char mode[yugu][305];//��ͬ����λ���
	int count;//ÿ��Ԫ�ص�ͳ��������Ŀ����
	int peinum_tj[peiwei];//��¼��ͬ��λ����Ӧ�ļ�¼����
	int flag_pure[yugu];//��¼��ͬ��λ�����Ƿ�Ϊ����ϣ����ķ���0�����ӵķ���1

};
struct jilu jilua[120];
int main()
{
	char name[50];
	char temp[50];
	char tmeppp[300];
	char tmepp[300];
	//string temp_s;
	int pei_num = 0;
	int i = 0, j = 0, k = 0;
	for (i = 0; i < 120; i++)
	{
		for (j = 0; j < yugu; j++)
		{
			local[i][j] = 0;
			jilua[i].flag_pure[j] = -1;
		}
		for (k = 0; k < peiwei; k++)
		{
			jilua[i].peinum_tj[k]=0;
		}

	}
	int hangshu = 0;
	
	int zhongxin_xuhao = 0;
	char element[3];
	int t = 0;
	int ii = 0, jj = 0, kk = 0;

	//���ȶ��ڽṹ���ȫ����ʼ��
	for (i = 0; i < 120; i++)
	{
		jilua[i].xuhao = i;
		jilua[i].mode_num = 0;
		backchar(jilua[i].xuhao_name);
		jilua[i].count = 0;
		for (j = 0; j < yugu; j++)
		{
			jilua[i].jishu[j] = 0;
			jilua[i].peiwe_num[j] = 0;
		}
	}

	for (i = 0; i < 20; i++)
	{
		backchar(name);
		strcpy(name, "out_");
		sprintf(temp, "%d", i);
		strcat(name, temp);
		strcat(name, ".txt");
		cout << name << endl;
		FILE *input;
		input = fopen(name, "r");

		if (NULL == input)
		{

			cout << "i can't find the file,please check the name!" << endl;
			cin.get();
		}
		//hangshu = 0;
		//hangshu = getNumberOfEdges(name);
		//cout << "the hangshu is" << hangshu << endl;
		backchar(temp);

		for (j = 0; !feof(input); j++)
		{
			//cout << "this is the :" << double(float(j) / float(hangshu)) * 100 << '\%' << "for the" << i << "file" << endl;
			//cout << "still has" << hangshu - j << "hang" << endl;
			fscanf(input, "%s\t", &temp);
			fscanf(input, "%s\t", &element);
			for (k = 0; k < 120; k++)
			{
				if (strcmp(element, a[k]) == 0)
				{
					break;
				}
			}

			zhongxin_xuhao = k;
			jilua[zhongxin_xuhao].count++;
			if (k == 119)
			{
				cout << "can't find the element xuhao,sory" << endl;
				cin.get();
			}
			if (zhongxin_xuhao != jilua[k].xuhao)
			{
				cout << "the code is wrong!" << endl;
				cout << "the element is:" << element << endl;
				cout << "the k is :" << k << endl;
				cout << "the zhongxin_xuhao is:" << endl;
				cin.get();
			}
			jilua[k].xuhao = zhongxin_xuhao;
			strcpy(jilua[k].xuhao_name, element);
			fscanf(input, "%d\t", &pei_num);

			if (pei_num == 0||pei_num>75) //�����λ��Ϊ0�Ļ�ֱ������
			{
				fscanf(input, "\n");
				continue;
			}

			//��������˽��������Ϣ��������
			fgets(tmeppp, 300, input);
			strcpy(tmepp, tmeppp);//����׼����������ͬ���ַ��������ڱ��ݲ���
			
			for (ii = 0; ii < jilua[zhongxin_xuhao].mode_num; ii++)
			{
				if (strcmp(tmeppp, jilua[zhongxin_xuhao].mode[ii]) == 0)
				{
					jilua[zhongxin_xuhao].jishu[ii]++;
					jilua[zhongxin_xuhao].peiwe_num[ii] = pei_num;
					if (jilua[zhongxin_xuhao].flag_pure[ii] == -1) 
					{
						jilua[zhongxin_xuhao].flag_pure[ii] = pure_zapanduan(tmeppp);
						cout << "your code wrong!should not equal -1" << endl;
					}
					
					//cout << "i write the data" << ii << endl;
					break;
				}
			}

			if (ii == jilua[zhongxin_xuhao].mode_num  &&  ii != yugu)
			{
				jilua[zhongxin_xuhao].mode_num++;
				//cout << "the row is" << j << endl;
				strcpy(jilua[zhongxin_xuhao].mode[ii], tmepp);
				jilua[zhongxin_xuhao].jishu[ii]++;
				jilua[zhongxin_xuhao].peiwe_num[ii] = pei_num;
				jilua[zhongxin_xuhao].flag_pure[ii] = pure_zapanduan(tmepp);
				
				//cout << "i write the data" << ii << endl;
			}
			if (jilua[zhongxin_xuhao].mode_num == yugu)
			{
				cout << "the 50000 mode_num is used all!" << endl;
				pei_num = 0;
				zhongxin_xuhao = 0;
				backchar(tmeppp);
				backchar(tmepp);
				cin.get();
			}
			backchar(tmeppp);
			backchar(tmepp);
			pei_num = 0;
			zhongxin_xuhao = 0;
			backchar(element);
		}
		backchar(name);
		backchar(element);
		cout << "have read the" << i << "file" << endl;

		fclose(input);
	}

	pure_tj(jilua);//��������˶�ÿ��Ԫ�صĴ�������ͳ��

	peiwei_mode_tj(jilua);//���������ÿ��Ԫ�أ�ÿ����λ�¶����֣��Լ�ÿ����λ�´���λ������

	cout << "start to write the peiwei_num tj file" << endl;
	peiwei_num_tj(jilua);//����ʵ����ͳ��ÿ��Ԫ�ز�ͬ��λ���µ�����ͳ��
	cout << "done to write the peiwei_num tj file" << endl;

	pure__plus_peiwei_num_tj(jilua);//ÿ����Ԫ�أ�ÿ����λ����µĴ���ͳ��

	

	//���������������������һ��������Ԫ�ص���λ������࣬��ӡһ������
	//��һ����
	cout << "start to write the peiwei_mode_paixu file!" << endl;
	peiwei_mode_paixu(jilua);//�������ʵ������һ���ļ����Ԫ�ص���λ��������
	cout << "done to write the peiwei_mode_paixu file!" << endl;
	cout << "start to write the tiaoshu_tj file!" << endl;
	tiaoshu_tongji(jilua);//����ʵ�����������������ͳ��
	cout << "done to write the tiaoshu_tj file!" << endl;
	

	



	for (i = 0; i < 120; i++)
	{
		BubbleSort(jilua[i].jishu, yugu, local[i]);         //�Ӵ�С����,���ҷ�����֮ǰ��Ӧ��λ��			   		 	  

	}
	int zong_modenum = 0;
	for (i = 0; i < 120; i++)
	{
		zong_modenum = zong_modenum + jilua[i].mode_num;//�������ȫ��Ԫ�ص�������λ�����ۺ�
	}
	out = fopen("result_peiwei-50000.txt", "w");

	//������Ҫע�⣬��Ҫ����˳��Ӹ�����ൽ��С��������

	fprintf(out, "%d\n", zong_modenum);
	int iii, jjj, kkk;
	for (iii = 0; iii < 120; iii++)
	{

		fprintf(out, "%s\t", jilua[iii].xuhao_name);
		fprintf(out, "%d\n", jilua[iii].mode_num);
		for (jjj = 0; jjj < jilua[iii].mode_num; jjj++)
		{


			fprintf(out, "%d\t", jilua[iii].peiwe_num[local[iii][jjj]]);
			fprintf(out, "%s\t", jilua[iii].mode[local[iii][jjj]]);
			fprintf(out, "%d\t", jilua[iii].jishu[jjj]);
			fprintf(out, "\n");

			

		}
		//cout << "this is wrong?" << endl;

	}
	fclose(out);
	cout << "��ͳ�ƵĶ�ͳ�ƵĲ���ˣ�" << endl;
	cout << "all work done!" << endl;
	cin.get();
	return 0;
}

int getNumberOfEdges(char fileName[])
{
	char flag;
	int edgeNum = 0, count = 0;
	FILE *fp = fopen(fileName, "r"); //open the TXT file, can only read, cannot write
	while (!feof(fp))
	{

		flag = fgetc(fp);
		if (flag == '\n')
			count++;
	}

	edgeNum = count + 1; //��Ϊ���һ��û�л��з�\n��������Ҫ��count����1
	fclose(fp);
	cout << " the edge number is " << edgeNum << endl;
	return edgeNum - 2;
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
void outprint(FILE *out, struct jilu jilua[120])
{
	out = fopen("result_peiwei.txt", "wb");
	int i, j, k;
	for (i = 1; i < 120; i++)
	{
		fprintf(out, "%s\n", jilua[i].xuhao_name);
		for (j = 0; j < jilua[i].mode_num; j++)
		{
			fprintf(out, "%d\t", jilua[i].peiwe_num[j]);

			fprintf(out, "%s\t", jilua[i].mode[j]);
			fprintf(out, "%d\t", jilua[i].jishu[j]);


		}
		fprintf(out, "\n");
	}
	fclose(out);
}
void backint(int* a)
{
	int i = 0;
	int k = sizeof(a) / sizeof(int);
	for (i = 0; i < k; i++)
	{
		a[k] = '\0';
	}
}
void BubbleSort(int  *p, int length, int * ind_diff)//�Ӵ�С����,���ҷ�����֮ǰ��Ӧ��λ��
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

void peiwei_mode_paixu(struct jilu jilua[120])
{
	int i, j;
	FILE* mode_numpaixu;	
	int *mode_paixu;
	int *local;
	local = (int*)malloc(120 * sizeof(int));
	mode_paixu = (int*)malloc(120 * sizeof(int));
	for (i = 0; i < 120; i++)
	{
		mode_paixu[i] = jilua[i].mode_num;
		local[i] = i+1;
	}
	BubbleSort(mode_paixu, 120, local);
	mode_numpaixu = fopen("peiwei-mode_numpaixu.txt", "w");
	for (j = 0; j < 120; j++)
	{
		fprintf(mode_numpaixu, "%d\t", local[j]);
		fprintf(mode_numpaixu, "%s\t", a[local[j ]]);
		fprintf(mode_numpaixu, "%d\n", mode_paixu[j]);

	}
	
	

	fclose(mode_numpaixu);
	free(mode_paixu);
	free(local);

	

}
void tiaoshu_tongji(struct jilu jilua[120])//û�в�����̬����
{
	int i, j;
	FILE* output;
	output = fopen("tiaoshu_tongji.txt","w");
	int *paixu;
	int *local;
	local = (int*)malloc(120 * sizeof(int));
	paixu = (int*)malloc(120 * sizeof(int));
	for (i = 0; i < 120; i++)
	{
		paixu[i] = jilua[i].count;
		local[i] = i + 1;
	}
	BubbleSort(paixu, 120, local);
	
	for (j = 0; j < 120; j++)
	{
		fprintf(output, "%d\t", local[j]);
		fprintf(output, "%s\t", a[local[j]]);
		fprintf(output, "%d\n", paixu[j]);

	}	
	free(local);
	free(paixu);
	fclose(output);



} 
int pure_zapanduan(char*a)
{
	int i = 0, j = 0;
	char seps[] = " ,\t\n";
	char *token;
	int jishu = 0;
	int label = 0; //0˵���Ǵ���ϣ�1�������
	
	for (i = 0; i < strlen(a); i++)
	{
		if (a[i] == '\t'|| a[i] == ' ')
		{
			jishu++;
		}
	}
	char ** save;
	save = new char*[jishu];
	for (i = 0; i < jishu; i++)
	{
		save[i] = new char[6];
	}

	token = strtok(a, seps);
	i = 0;
	while (token != NULL)
	{
		//printf("%s\n", token);
		
		strcpy_s(save[i],strlen(token)+1,token);
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


void peiwei_num_tj(struct jilu jilua[120])
{
	int i, j, k, m;
	int temp = 0;

	for (i = 0; i < 120; i++)
	{
		for (j = 0; j < jilua[i].mode_num; j++)
		{
			temp = jilua[i].peiwe_num[j];
			if (temp > peiwei || temp == peiwei)
			{
				temp = 0;
				continue;
			}
			jilua[i].peinum_tj[temp] = jilua[i].peinum_tj[temp] + jilua[i].jishu[j];
			temp = 0;	

			
		}
	}
	FILE *out;
	out = fopen("peiwei_tj.txt", "w");
	for (i = 0; i < 120; i++)
	{
		fprintf(out, "%d\t", jilua[i].xuhao);
		fprintf(out, "%s\n", jilua[i].xuhao_name);
		for (j = 0; j < peiwei; j++)
		{
			//fprintf(out, "%d\t", j);
			
			fprintf(out, "%d\t", jilua[i].peinum_tj[j]);
		}
		fprintf(out, "\n");
	}
	fclose(out);



}

void pure_tj(struct jilu jilua[120])
{
	int i, j, k, m;
	int temp = 0;
	int pure[120];
	int za[120];
	for (i = 0; i<120; i++)
	{
		pure[i] = 0;
		za[i] = 0;
	}

	for (i = 0; i < 120; i++)
	{
		for (j = 0; j < jilua[i].mode_num; j++)
		{
			if (jilua[i].flag_pure[j] == 0)
			{
				pure[i] = pure[i] + jilua[i].jishu[j];
			}
			else if(jilua[i].flag_pure[j] == 1)
			{
				za[i] = za[i] + jilua[i].jishu[j];
			}
			else
			{
				cout << "your code is wrong!" << endl;
				cout << jilua[i].mode[j] << endl;
				cout << jilua[i].flag_pure[j] << endl;
				cin.get();
			}

		}
	}
	FILE *out;
	out = fopen("pure_tj.txt", "w");

	for (i = 0; i < 120; i++)
	{
		fprintf(out, "%d\t", jilua[i].xuhao);
		fprintf(out, "%s\t", jilua[i].xuhao_name);
		
		fprintf(out, "%d\t", pure[i]);
		fprintf(out, "%d\n", za[i]);
		
	}
	fclose(out);



}

void pure__plus_peiwei_num_tj(struct jilu jilua[120])
{
	int i, j, k, m;
	int temp = 0;
	int pure[peiwei][120];
	int za[peiwei][120];
	//��ʼ��ʼ��
	for (i = 0; i < peiwei; i++)
	{
		for (j = 0; j < 120; j++)
		{
			pure[i][j]=0;
			za[i][j]=0;
		}
	}

	
	for (i = 0; i < 120; i++)
	{
		for (j = 0; j < jilua[i].mode_num; j++)
		{
			temp = jilua[i].peiwe_num[j];
			if (temp > peiwei || temp == peiwei)
			{
				temp = 0;
				continue;
			}
			//cout << "the temp is" << temp << endl;

			if (jilua[i].flag_pure[j] == 0)
				{
					pure[temp][i] = pure[temp][i] + jilua[i].jishu[j];
				}
			else if(jilua[i].flag_pure[j] ==1)
				{
					za[temp][i] =za[temp][i] + jilua[i].jishu[j];
				}
			else
			{
				cout << "your code wrong!this is the write file part" << endl;
			}
			temp = 0;

			
		}
		temp = 0;
	}




	FILE *out;
	out = fopen("peiwei_pluspure_tj.txt", "w");

	for (i = 0; i < 120; i++)
	{
		fprintf(out, "%d\t", jilua[i].xuhao);
		fprintf(out, "%s\n", jilua[i].xuhao_name);
		for (j = 0; j < peiwei; j++)
		{
			//fprintf(out, "%d\t", j);

			//fprintf(out, "%d\t", jilua[i].peinum_tj[j]);
			fprintf(out, "%d\t", pure[j][i]);
			//fprintf(out, "%d\t", za[j][i]);
		}
		fprintf(out, "\n");
	}
	fclose(out);



}
void peiwei_mode_tj(struct jilu jilua[120])
{
	int i = 0, j = 0;
	int pw_mode_tj[120][peiwei];
	int pure_pw_mode_tj[120][peiwei];
	for (i = 0; i < 120; i++)
	{
		for (j = 0; j < peiwei; j++)
		{
			pw_mode_tj[i][j] = 0;
			pure_pw_mode_tj[i][j] = 0;
		}
	}
	int temp = 0;
	for (i = 0; i < 120; i++)
	{
		for (j = 0; j < jilua[i].mode_num; j++)
		{
			temp = jilua[i].peiwe_num[j];
			if (temp < peiwei)
			{
				pw_mode_tj[i][temp]++;
			}
		}
	}

	for (i = 0; i < 120; i++)
	{
		for (j = 0; j < jilua[i].mode_num; j++)
		{
			temp = jilua[i].peiwe_num[j];
			if (temp<peiwei && jilua[i].flag_pure[j]==0)
			{
				pure_pw_mode_tj[i][temp]++;
			}
		}
	}

	FILE* out1;
	out1=fopen("pw_mode_tj.txt","w");
	for (i = 0; i < 120; i++)
	{
		for (j = 0; j < peiwei; j++)
		{
			fprintf(out1, "%d\t", pw_mode_tj[i][j]);
		}
		fprintf(out1, "\n");
	}
	fclose(out1);
	FILE*out2;
	out2=fopen("pure_pw_mode_tj.txt", "w");
	for (i = 0; i < 120; i++)
	{
		for (j = 0; j < peiwei; j++)
		{
			fprintf(out2, "%d\t", pure_pw_mode_tj[i][j]);
		}
		fprintf(out2, "\n");
	}
	fclose(out2);




}