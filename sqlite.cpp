#include"sqlite.h"

//��ʼ���������ݿ�
int sqlite::initdb()
{
	int ret = sqlite3_open("xuanke.db", &pdb);
	if (ret != SQLITE_OK)
	{
		cout << "���ݿⴴ��ʧ��!" << endl;
		return -1;
	}
	cout << "���ݿⴴ��(��)�ɹ�" << endl;
	return 0;
}
//������
int sqlite::createtable(char* sql)
{
	char* errmsg = NULL;
	int ret = SQLITE_OK;
	ret = sqlite3_exec(pdb, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		cout << "����ʧ��!" << errmsg << endl;
		sqlite3_free(errmsg);
		return -1;
	}
	return 0;
}

int sqlite::login(char* sql)
{
	char** ppTable = NULL;  //���select�Ľ��	
	char* errmsg = NULL;
	int row = 0;
	int column = 0;
	int ret = sqlite3_get_table(pdb, sql, &ppTable, &row, &column, &errmsg);
	if (ret != SQLITE_OK)
	{
		cout << "sqlite3_get_table error:" << errmsg << endl;
		sqlite3_free(errmsg);
		errmsg = NULL;
		return -1;
	}
	if (0 == row)
	{
		cout << "�û������������" << endl;
	}
	else
	{
		cout << "��¼�ɹ�" << endl;
	}
	return 0;
}
int sqlite::stu_login(char* sql)
{
	char** ppTable = NULL;  //���select�Ľ��	
	char* errmsg = NULL;
	int row = 0;
	int column = 0;
	int ret = sqlite3_get_table(pdb, sql, &ppTable, &row, &column, &errmsg);
	if (ret != SQLITE_OK)
	{
		cout << "sqlite3_get_table error:" << errmsg << endl;
		sqlite3_free(errmsg);
		errmsg = NULL;
		return -1;
	}
	if (0 == row)
	{
		cout << "ѧ�Ż��������" << endl;
	}
	else
	{
		cout << "��¼�ɹ�" << endl;
	}
	return 0;
}

int sqlite::insert_table(char* sql)
{
	char* errmsg = NULL;
	int ret = sqlite3_exec(pdb, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		cout << "�����ʧ��!" << errmsg << endl;
		sqlite3_free(errmsg);
		return -1;
	}
	cout << "����ɹ�" << endl;
	return 0;
}

int sqlite::delete_table(char* sql)
{
	char* errmsg = NULL;
	int ret = sqlite3_exec(pdb, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		cout << "ɾ��ʧ��!" << errmsg << endl;
		sqlite3_free(errmsg);
		return -1;
	}
	cout << "ɾ���ɹ�" << endl;
	return 0;
}

int sqlite::update_table(char* sql)
{
	char* errmsg = NULL;
	int ret = sqlite3_exec(pdb, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		cout << "����ʧ��!" << errmsg << endl;
		sqlite3_free(errmsg);
		return -1;
	}
	cout << "���³ɹ�" << endl;
	return 0;
}



//��ѡ���ȡ��
string sqlite::select_from_table(char* sql)
{
	char** ppTable = NULL;  //���select�Ľ��	
	char* errmsg = NULL;
	int row = 0;
	int ret = sqlite3_get_table(pdb, sql, &ppTable, &row, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		cout << "sqlite3_get_table error:" << errmsg << endl;
		sqlite3_free(errmsg);
		errmsg = NULL;
		return "fail";
	}
	int i = 0; int j = 1;
	for (i=-9;i<row;i++)
	{
		cout << ppTable[j];
		j++;
	}
	return ppTable[1];
}


//ȫ��ȡ�����еĶ���������������pptable��֮����ת����������ȥ
int sqlite::select_table(char* sql, vector<string>& v)
{
	char** ppTable = NULL;  //���select�Ľ��
	int row = 0;  //���ҵ�������
	int column = 0; //�鵽�Ľ��������
	char* errmsg = NULL;
	int ret = sqlite3_get_table(pdb, sql, &ppTable, &row, &column, &errmsg);
	if (ret != SQLITE_OK)
	{
		cout << "sqlite3_get_table error:" << errmsg << endl;
		sqlite3_free(errmsg);
		errmsg = NULL;
		return -1;
	}
	int i = 0, j = 0;
	for (i = 0; i < row + 1; i++)
	{
		for (j = 0; j < column; j++)
		{
			v.push_back(ppTable[i * column + j]);
		}
	}
	return 0;
}