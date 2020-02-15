#include <sys/types.h>
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
const int NUM_ALL = 158288;
void analyse_compare_result(char* filename, char* two_naname, char * result_name, int NUM = 244);
int anayse_ridus_check(string file_name, string path, int total);
int flag_file_check(string name);
void vaqum_situation_check(int head_num);
void all_part_check(string cut_bulk, string total_count, string real_count);
int bulk_name_check(string bulk_name, string count, string path, int num_all);
int main(int argc, const char *argv[])
{
	int i = 0, j = 0;
	string bulk_name = "bulk";
	string count_name = "count";
	string path = "/share/home/wangz/2d_search/ridus_cut/data/cut_1111/cut/";
	if (bulk_name_check(bulk_name, count_name, path, 89739) == 0)
	{
		cout << "right file new got!" << endl;
	}
	return 0;


















	string cut_bulk = "cut_bulk";
	string total_count = "count_total";
	string real_count = "count_real";
	all_part_check(cut_bulk, total_count, real_count);
	cout << "check complete!" << endl;
	return 0;




















	//��ʼ�����µ�flag����ȷ���ļ�����Ч��
	
	string* all_name = new string[NUM_ALL];
	int* flag_sure = new int[NUM_ALL];	
	ifstream fin;
	fin.open("name", ios::in);
	for (i = 0; i < NUM_ALL; i++)
	{
		fin >> all_name[i];
	}
	fin.close();
	for (i = 0; i < NUM_ALL; i++)
	{
		flag_sure[i] = 0;
		flag_sure[i] = flag_file_check(path + all_name[i]+"/flag");
	}
	ofstream fout;
	fout.open("right_file", ios::out);
	for (i = 0; i < NUM_ALL; i++)
	{
		if (flag_sure[i] == 1)
		{
			fout << all_name[i] << endl;
		}
	}
	fout.close();
	cout << "make sure complete!" << endl;
	return 0;













	//����������falg������������ļ�¼
	analyse_compare_result(const_cast<char*>("compare_all"), const_cast<char*>("2dname"), const_cast<char*>("result_str"), 3336);
	cout << "classify complete!" << endl;
	return 0;

	vaqum_situation_check(71591);
	return 0;









	//���ԣ����ridus����check
	string check_file = "four_and_more.txt";
	string check_config_path = "/share/home/wangz/2d_search/ridus_cut/temp_result_13000/";
	string all_config = "all_config";
	if (anayse_ridus_check(check_file, all_config, 8685) == 0)
	{
		cout << "all total work done!" << endl;
		cin.get();
		return 0;
	}
	else
	{
		cout << "check file encounter errors!" << endl;
		cin.get();
		return 1;
	}





	cout << "now lets to start classify!" << endl;
	char filename[100] = "compare_NUM.txt";
	char twoname[100] = "name";
	char result[100] = "244_classify_10.8.txt";
	analyse_compare_result(filename, twoname, result);
	cout << "classify complete!" << endl;






	cout << "all total work done!" << endl;
	cin.get();
	return 0;






}







void analyse_compare_result(char* filename, char* two_naname,char * result_name,int NUM)
{
	//������n*n�Ķ�ά����,���нṹ���ļ���������ǽ��з���ú���ļ�
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
			fin >> compare[i][j];
		}

	}
	fin.close();

	//����ṹ�ļ���
	string*name = new string[NUM];
	fin.open(two_naname, ios::in);	
	int flaga = 0;
	int count = 0;
	for (i = 0; i < NUM; i++)
	{
		fin >> name[i];		
		for (j = 0; j < name[i].length(); j++)
		{
			if (name[i][j] == '_')
			{
				count++;
				if (count == 2)
				{
					name[i][j] = '\0';	
					flaga = 1;
					count = 0;
				}						
			}
			if (flaga == 0)
			{
				name[i][j] = name[i][j];
			}
			else
			{
				name[i][j] = '\0';			
			}
			
		}
		//cout << "after processing" << endl;		
		//cout << name[i] << endl;
		//cin.get();		
		flaga = 0;
	}
	fin.close();

	//for (i = 0; i < 50; i++)
	//{
	//	cout << name[i] << endl;
	//}




	ofstream  out;
	out.open(result_name, ios::out);
	//���濪ʼ������ʽ���з�����
	int row = 0;//����д�������



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
			if (compare[i][j] != 0 && compare[j][i] != 0 && flag[j] == 0)
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
		delete[]compare[i];
	}
	delete[]compare;
	return;

}



void all_part_check(string cut_bulk, string total_count, string real_count)
{
	int lines = 0;
	int i = 0, j = 0;
	ifstream fin;
	fin.open(cut_bulk, ios::in);
	if (!fin.is_open())
	{
		cout << "i can not find the file: "<<cut_bulk << endl;
		cin.get();
		return;
	}
	string temp;
	while (fin.good() && fin.peek() != EOF)
	{
		fin >> temp;
		i++;		
	}
	fin.close();
	lines = i - 1;
	cout << "is:" << i - 1 << "lines" << endl;
	fin.open(cut_bulk,ios::in);
	fin.seekg(0, ios::beg);
	string* save_name = new string[i - 1];
	for (j = 0; j < i - 1; j++)
	{
		fin >> save_name[j];
		//cout << save_name[j] << endl;
		//save_name[j] = path + save_name[j];		
	}
	fin.close();

	int*flag = new int[lines];//1��ʾ���Ҳ����all��0��ʾpart��
	int count_all, count_real;
	fin.open(total_count, ios::in);
	ifstream fin2;
	fin2.open(real_count, ios::in);
	for (i = 0; i < lines; i++)
	{
		fin >> count_all;
		fin2 >> count_real;
		if (count_all == count_real)
		{
			flag[i] = 1;
		}
		else if (count_all > count_real)
		{
			flag[i] = 0;
		}
		else
		{
			cout << "wrong!" << save_name[i] << endl;
			cin.get();
		}
	}

	//Ȼ���Ǹ��ݽ�������Ӧ�Ŀ���
	int all = 0;
	int part = 0;
	ofstream fout, fout2;
	fout.open("all",ios::out);
	fout2.open("part", ios::out);
	for (i = 0; i < lines; i++)
	{
		if (flag[i] == 1)
		{
			fout << save_name[i] << endl;
			all++;
		}
		else
		{
			fout2 << save_name[i] << endl;
			part++;
		}
	}
	cout << "all: " << all << "part: " << part << "null: " << 65517 - part - all << endl;
	fout.close();
	fout2.close();
	return;

}

int anayse_ridus_check(string file_name, string all_config, int total)
{
	//�������Ŀ������
	int lines = 0;
	//string str1 = "ls " + path + "  >>all_config";
	//system(str1.c_str());
	ifstream fin;
	fin.open("all_config");
	int i = 0, j = 0;
	if (!fin.is_open())
	{
		cout << "i can not find the file: all_config" << endl;
		cin.get();
		return 1;
	}
	string temp;
	while (fin.good() && fin.peek() != EOF)
	{
		fin >> temp;
		i++;
		if (temp == file_name)
			i = i - 1;
	}
	fin.close();
	lines = i - 1;
	cout << "is:" << i - 1 << "lines" << endl;
	fin.open("all_config");
	fin.seekg(0, ios::beg);
	string* save_name = new string[i - 1];
	for (j = 0; j < i - 1; j++)
	{
		fin >> save_name[j];
		//cout << save_name[j] << endl;
		//save_name[j] = path + save_name[j];
		if (save_name[j] == file_name)
			j--;
	}
	fin.close();
	//���濪ʼ���������ļ���������ļ�
	//����������ļ���ͷ�����Լ�ӵ�еĸ���������Ƕ�Ӧ�����˸�2d�ļ�
	fin.open(file_name);	
	if (!fin.is_open())
	{
		cout << "i can not find the file:"<<file_name << endl;
		cin.get();
		return 0;
	}
	string head_name;
	int compare[2];
	int count = 0;	
	int*count_all = new int[total];
	for (i = 0; i < total; i++)
	{
		count_all[i] = 0;
	}
	int falg = 0;
	for (i = 0; i < total; i++)
	{
		falg = 0;
		fin >> compare[0];
		fin >> compare[1];
		head_name = to_string(compare[0]);
		for (j = 1; j < compare[1]+1; j++)
		{
			//head_name = head_name + "_" + to_string(j);
			//�����������ļ���Ѱ����û������ַ���
			for (int k = 0; k < lines; k++)
			{
				if (head_name[0] < save_name[k][0])
					break;
				if (head_name[0] == save_name[k][0])
				{
					//����Ϊ�����٣����������Ų����ǰ���˳���
					if (save_name[k].find(head_name + "_" + to_string(j)+'-') == 0)
					{
						//cout << save_name[k] << endl;
						//cout << j << endl;
						count_all[i]++;
						if (count_all[i] == compare[1])
						{
							falg = 1;
							break;
						}
						break;
					}
				}
			}
			//����Ѿ���ȫ�ˣ�������ȥ������һ��
			if (falg == 1)
			{
				break;
			}			
		}
		cout << head_name << ","<<count_all[i] << endl;
		//cin.get();
	}
	
	fin.close();


	//��������Ӧ�Ľ��
	ofstream fout;
	fout.open("num_check_last");
	for (i = 0; i < total; i++)
	{
		fout << count_all[i] << endl;
	}
	fout.close();
	delete[]count_all;
	delete[]save_name;
	return 0;
}

void vaqum_situation_check(int head_num)
{
	//�����������������������txt���������ÿ��ͷ��Ӧ������ж����֣���������ܵ����ֵ
	//�����head num��71591
	ifstream fin;
	fin.open("bulk_head.txt", ios::in);
	ifstream finn;
	
	int*head_situ_num = new int[head_num];
	int* head_max = new int[head_num];
	int i = 0, j = 0, falg, count;
	for (i = 0; i < head_num; i++)
	{
		head_situ_num[i] = 0;
		head_max[i] = -2000;
	}
	int con_flag = 1;
	int aa_falg = 0;
	string temp, aa;
	finn.open("all_bulk.txt", ios::in);
	for (i = 0; i < head_num; i++)
	{
		if (con_flag==1)
			fin >> temp;//��ȡ��ͷ��ʲô		
		while (finn.good() && finn.peek() != EOF)
		{
			if (con_flag == 1 &&aa_falg==0)
			{
				finn >> aa;				
			}
			/*if (aa[0] <temp[0] || (aa[1] <temp[1] && aa[1] != '_'))
				continue;
			if (aa[0] > temp[0] || (aa[1] > temp[1] && aa[1]!='_'))
				break;*/
			falg = aa.find(temp);
			//cout << aa[temp.length()] << endl;
			//����ֻ�����ֿ��ܣ�aa��temp�����ڻ��߲���
			if (falg == -1 || aa[temp.length()] != '_')
			{
				con_flag = 1;
				aa_falg = 1;
				break;
			}
			else if(falg != -1 &&aa[temp.length()]=='_')//˵�����������
			{						
				aa_falg = 0;
				head_situ_num[i]++;
				falg = aa.find('_');
				string numm = aa.substr(falg+1);
				char num[5];
				strcpy(num, numm.c_str());
				count = atoi(num);
				//cout << aa << "," << temp << "," << count << endl;
				if (count > head_max[i])
					head_max[i] = count;
			}
			else
			{
				cout << "wrong!" << endl;
				cin.get();
			}
		}
		
		cout << temp << "," << head_max[i] << endl;
	}
	finn.close();
	fin.close();

	//���濪ʼ�������յĽ��	
	ofstream fout;
	fout.open("check_result", ios::out);
	for (i = 0; i < head_num; i++)
	{
		fout << head_situ_num[i] << "\t";
		fout << head_max[i] << endl;
	}
	fout.close();
	delete[]head_max;
	delete[]head_situ_num;
	cout << "generate result complete!" << endl;
	return;
}

int flag_file_check(string name)
{
	//�������ļ�·����������ж������Ӧ��falg�ļ��ǲ���ok��
	//��ͨok����1�����ʷ���2
	int i = 0;
	//cout << name << endl;
	ifstream fin;
	fin.open(name, ios::in);
	if (!fin.is_open())
	{
		cout << "i can not find the file:" << name << endl;
		cin.get();
	}
	char line[4][300];
	for (i = 0; i < 4; i++)
	{
		fin.getline(line[i], 299,'\n');
		//cout << line[i] << endl;
	}
	if ((line[0][0] == 'D' || line[0][0] == 'S') && line[1][0] == '1' && line[2][0] == '1')
	{
		//cout << name << endl;
		if (line[3][0] == '1')
		{
			//cout << name << endl;
			//c/in.get();
			return 2;
		}
			
		else					
		//cout << line[0] << endl << line[1] << endl << line[2] << endl;
		//cin.get();
		return 1;
	}
	else
	{
		//cout << line[0] << endl << line[1] << endl << line[2] << endl;
		//cin.get();
		return 0;
	}
		
}


int bulk_name_check(string bulk_name,string count,string path,int num_all)
{
	//������·�����������֣��Լ�bulk������
	//�����һ���ļ�������Ϊright_bulk,д������Ч���ļ���
	int i = 0, j = 0;
	int situa = 0;
	string temp;
	ifstream fin, fin2;
	ofstream fout;
	fin.open(bulk_name, ios::in);
	fin2.open(count, ios::in);
	if (!(fin.is_open() && fin2.is_open()))
	{
		cout << "i can not find the file!" << bulk_name << count << endl;
		cin.get();
	}
	int right_count = 0;
	int falg[300] = { -1 };
	for (i = 0; i < 300; i++)
	{
		falg[i] = -1;
	}
	int usual_flag = 0;//����ǲ��ǳ����˳������
	fout.open("right_name", ios::out);
	for (i = 0; i < num_all; i++)
	{
		fin >> temp;
		fin2 >> situa;
		
		for (j = 1; j < situa + 1; j++)
		{
			falg[j - 1] = flag_file_check(path + temp + "_"+to_string(j)+"/flag");
			if (falg[j - 1] == 2)
			{
				usual_flag = 1;
			}
			if (falg[j - 1]==1|| falg[j - 1] == 2)//˵������Ч��
			{
				right_count++;
			}
		}
		if (usual_flag == 1)
		{
			for (j = 1; j < situa + 1; j++)
			{
				if (falg[j - 1] == 2)
				{
					fout << temp + "_" + to_string(j) << endl;;
				}
			}
		}
		else
		{
			if (usual_flag == 0)
			{
				for (j = 1; j < situa + 1; j++)
				{
					if (falg[j - 1] == 1)
					{
						fout << temp + "_" + to_string(j) << endl;
					}
				}
			}
		}
		right_count = 0;
		usual_flag = 0;
		//���flag
		for (j = 0; j < situa; j++)
		{
			falg[j] = -1;
		}
	}
	fin.close();
	fin2.close();
	return 0;

}

