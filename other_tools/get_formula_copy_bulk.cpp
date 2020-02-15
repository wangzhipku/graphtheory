
//这个程序的目的是批量更改结构的名字，让他们变成formula的编号
#include <unistd.h>
//#include <windows.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#pragma warning(disable : 4996)
using namespace std;
const int cengshu = 7;                               //��������������������ھ�����չʱ�Ĳ���
const int yanshen = cengshu * cengshu * cengshu;
const double pi = 3.1415926;//˵�����˶��پ���
const char a[120][3] = { " ", "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lw", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg" };
double dist[120][120];
int meatal_xuhao[86] = { 3, 4, 11, 12, 13, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 37, 38, 39, 40, 41, 42, 43, 44, 46, 47, 48, 49, 50, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111 };

double dis(double *p1, double *p2)
{
	return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2) + pow(p1[2] - p2[2], 2));
}
void new_get_style(char *style)
{
	ifstream fin;
	fin.open(style, ios::in);
	if (!fin.is_open())
	{
		cout << "i can not find the file:" << style << endl;
		cin.get();
	}
	while (fin.good())
	{
		for (int i = 1; i < 112; i++)
		{
			for (int j = 1; j < 112; j++)
			{
				fin >> dist[i][j];
			}
		}
	}
	fin.close();
	return;
}
class cell
{
public:
	cell(char *jiegou_name);
	int num = 0;
	double **letice;
	double **p;
	double ***p_real;
	double ***real_position;
	int *type;
};
cell::cell(char *name)
{
	int i, j, k;
	//cout << "expand the :" << cengshu << "layer" << endl;
	char temp[300];
	double x_pian = 0.0;
	double y_pian = 0.0;
	double z_pian = 0.0;
	//strcpy(wenjian, "atom1.config");
	FILE *in;
	in = fopen(name, "rt");
	//system("pause");
	if (in == NULL)
	{
		printf("error of rading atom.config!\n");
		printf("the filename is :%s\n", name);
		//cin.get();
		return;
	}
	fscanf(in, "%d", &num);

	type = (int *)malloc(num * sizeof(int));
	letice = (double **)malloc(3 * sizeof(double *));
	for (i = 0; i < 3; i++)
	{
		letice[i] = (double *)malloc(3 * sizeof(double));
	}
	p = (double **)malloc(num * sizeof(double *));
	for (i = 0; i < num; i++)
	{
		p[i] = (double *)malloc(3 * sizeof(double));
	}
	real_position = (double ***)malloc(yanshen * sizeof(double **));
	for (i = 0; i < yanshen; i++)
	{
		real_position[i] = (double **)malloc(num * sizeof(double *));
		for (k = 0; k < num; k++)
			real_position[i][k] = (double *)malloc(3 * sizeof(double));
	}

	p_real = new double **[yanshen];
	for (i = 0; i < yanshen; i++)
	{
		p_real[i] = new double *[num];
		for (k = 0; k < num; k++)
		{
			p_real[i][k] = new double[3];
		}
	}
	while (fgets(temp, 300, in) != NULL)
	{
		if (strstr(temp, "vector") != NULL)
			break;
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			fscanf(in, "%lf", &letice[i][j]);
		}
	}

	fgets(temp, 300, in);
	fgets(temp, 300, in);
	for (i = 0; i < num; i++)
	{

		fscanf(in, "%d", &type[i]);
		fscanf(in, "%lf", &p[i][0]);
		fscanf(in, "%lf", &p[i][1]);
		fscanf(in, "%lf", &p[i][2]);
		fgets(temp, 300, in);
	}
	//int x_xishu = 0;
	//int y_xishu = 0;
	//int z_zishu = 0;

	for (i = 0; i < yanshen; i++)
	{

		for (j = 0; j < num; j++)
		{
			//x_xishu = i/3;
			//y_xishu = i / 3;
			//z_zishu = (i % 9) / 3;

			real_position[i][j][0] = letice[0][0] * p[j][0] + letice[1][0] * p[j][1] + letice[2][0] * p[j][2] + (i % cengshu - ((cengshu - 1) / 2)) * letice[0][0] + (i % (cengshu * cengshu) / cengshu - ((cengshu - 1) / 2)) * letice[1][0] - (i / (cengshu * cengshu) - ((cengshu - 1) / 2)) * letice[2][0];
			real_position[i][j][1] = letice[0][1] * p[j][0] + letice[1][1] * p[j][1] + letice[2][1] * p[j][2] + (i % cengshu - ((cengshu - 1) / 2)) * letice[0][1] + (i % (cengshu * cengshu) / cengshu - ((cengshu - 1) / 2)) * letice[1][1] - (i / (cengshu * cengshu) - ((cengshu - 1) / 2)) * letice[2][1];
			real_position[i][j][2] = letice[0][2] * p[j][0] + letice[1][2] * p[j][1] + letice[2][2] * p[j][2] + (i % cengshu - ((cengshu - 1) / 2)) * letice[0][2] + (i % (cengshu * cengshu) / cengshu - ((cengshu - 1) / 2)) * letice[1][2] - (i / (cengshu * cengshu) - ((cengshu - 1) / 2)) * letice[2][2];
		}
	}
	for (i = 0; i < yanshen; i++)
	{
		for (j = 0; j < num; j++)
		{
			p_real[i][j][0] = (i % cengshu - ((cengshu - 1) / 2)) + p[j][0];
			p_real[i][j][1] = (i % (cengshu * cengshu) / cengshu - ((cengshu - 1) / 2)) + p[j][1];
			p_real[i][j][2] = -(i / (cengshu * cengshu) - ((cengshu - 1) / 2)) + p[j][2];
		}
	}

	fclose(in);
}
string int2string(int i);
void get_copy_config(string* & name_old, string*&name_new, const string &old_path, const string &new_path, const int &total);
int main(int argc, const char*argv[])
{


	cout << "本程序用来批量将.config的文件改为formula形式，改名后无法恢复，请使用前备份源文件！" << endl;
	int i = 0, j = 0, k = 0;
	int str = 0;
	int total = 0;
	string atom_path = "/share/home/database/BDM/files/";
	string bulk_path = "/share/home/wangz/2d_search/2d_last_modi_exclude/2d_config/af_delsame/bulk/";
	string shell[12];
	shell[0] = "ls |grep .*.config|wc -l >> name_num";
	shell[1] = "rm -rf name_num";
	shell[2] = "rm -rf name_list";
	//shell[3] = "cp ";
	system(shell[0].c_str());
	ifstream material_name;
	material_name.open("name_num",ios::in);
	if (!material_name.is_open())
	{
		cout << "i can not find the name_num" << endl;
		cin.get();
		return 0;
	}
	material_name >> total;
	cout << "material num: " << total << endl;
	//cin.get();
	material_name.close();
	system(shell[1].c_str());
	//先读取了文件数量




	//下面开始循环读进去对象
	string *name_got = new string[total];
	string *name_new = new string[total];

	shell[3] = "ls |grep .*.config >> name_list";
	system(shell[3].c_str());

	material_name.open("name_list");
	if (!material_name.is_open())
	{
		cout << "i can not find the name_list" << endl;
		cin.get();
		return 0;
	}
	while (material_name.good())
	{
		material_name >> name_got[i++];
	}
	material_name.close();
	system(shell[2].c_str());
	cout << "got name finished" << endl;


	
	int element[120] = { 0 };
	for (str=0;str<total;str++)
	{
		cell cell_a(const_cast <char*>(name_got[str].c_str()));
		for (i = 0; i < cell_a.num; i++)
		{
			element[cell_a.type[i]]++;
		}
		for (i = 0; i < 120; i++)
		{
			if (element[i] != 0)
			{
				name_new[str] += a[i];
				string temp = int2string(element[i]);
				name_new[str] += temp;
			}
		}

		for (i = 0; i < 120; i++)
		{
			element[i]=0;
		}
	}


	//下面开始测试 
	/*for (i = 0; i < 10; i++)
	{
		cout << name_new[i] << endl;
	}
	cin.get();*/
	int *falg = new int[total];
	for (i = 0; i < total; i++)
	{
		falg[i] = 0;
	}

	int jishu = 0;
	for (i = 0; i < total; i++)
	{
		string temp = name_new[i];
		for (j = 0; j < total; j++)
		{
			if (falg[j] == 0 && temp==name_new[j])
			{				
				name_new[j] = temp + "_" + int2string(jishu++);				
				//cout << name_new[j] << endl;
				//cin.get();				
				falg[j] = 1;			
			}			
		}
		jishu = 0;
	}
	cout << "got new name finished!" << endl;


	//这里添加一个功能，将bulk返回来，放到bulk文件夹中
	

	get_copy_config(name_got,name_new,atom_path,bulk_path, total);
	cout << "复制bulk文件完成！" << endl;






	//下面开始循环改名了
	cout.setf(ios::fixed);
	cout << "now to real change" << endl;	
	for (i = 0; i < total; i++)
	{
		string com = "mv " + name_got[i] + " " + name_new[i];
		system(com.c_str());	
		//cout << "a" << endl;
		cout << '\r' <<setprecision(2)<<(double(i) / total) * 100 << "%" ;		
		cout << endl;
	}


	//这里要注意，这里我们留下改名前和改名后的对照，方便后面的查看
	ofstream fout;
	fout.open("name_compare", ios::out);
	for (i = 0; i < total; i++)
	{
		fout << name_got[i] << '\t' << name_new[i] << endl;
	}
	fout.close();
	cout << "please check the name_compare to make sure name changes!" << endl;







	cout.unsetf(ios::fixed);
	cout << endl;
	delete[]name_got;
	delete[]falg;
	delete[]name_new;
	cout << "all total work done!" << endl;
	cin.get();
	return 0;

	
}

string int2string(int i)
{

	stringstream ss;
	ss << i;

	return ss.str();
}



int  fix_namechange(string excel_name, string duizhao_filename, const int num)
{
	cout << "这个小函数输入分类号的excel文件，以及名字的改变前后对照，输出是名字修改后的分类excel文件" << endl;

	ifstream excel;
	excel.open(excel_name, ios::in);
	if (!excel.is_open())
	{
		cout << "i can not find the file:" << excel_name << endl;
		cin.get();
		return 0;
	}
	while (excel.good())
	{

	}
}


void get_copy_config(string* & name_old, string*&name_new, const string &old_path,const string &new_path,const int &total)
{
	int i = 0, j = 0;
	cout << "开始将对应的体材料复制指定的目录，并且获得新的结构名";
	string * pure_num = new string[total];
	string shell[5];
	shell[0] = "cp ";
	for (i = 0; i < total; i++)
	{
		j = name_old[i].find("-");
		pure_num[i] = name_old[i].substr(0, j);
		//pure_num[i][j + 1] = '\0';
	}
	string temp;
	for (i = 0; i < total; i++)
	{
		temp = name_new[i] + "_bulk" + int2string(i);	
		//cout << shell[0] + old_path + pure_num[i] + "/atom.config  " + new_path + temp << endl;
		system((shell[0] + old_path + pure_num[i] + "/atom.config  " + new_path + temp).c_str());
		cin.get();
		temp.clear();
	}
	delete[]pure_num;
	return;
}