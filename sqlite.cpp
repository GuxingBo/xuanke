#include"sqlite.h"

//初始化创建数据库
int sqlite::initdb()
{
	int ret = sqlite3_open("xuanke.db", &pdb);
	if (ret != SQLITE_OK)
	{
		cout << "数据库创建失败!" << endl;
		return -1;
	}
	cout << "数据库创建(打开)成功" << endl;
	return 0;
}
//创建表
int sqlite::createtable(char* sql)
{
	char* errmsg = NULL;
	int ret = SQLITE_OK;
	ret = sqlite3_exec(pdb, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		cout << "表创建失败!" << errmsg << endl;
		sqlite3_free(errmsg);
		return -1;
	}
	return 0;
}

int sqlite::login(char* sql)
{
	char** ppTable = NULL;  //存放select的结果	
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
		cout << "用户名或密码错误" << endl;
	}
	else
	{
		cout << "登录成功" << endl;
	}
	return 0;
}
int sqlite::stu_login(char* sql)
{
	char** ppTable = NULL;  //存放select的结果	
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
		cout << "学号或密码错误" << endl;
	}
	else
	{
		cout << "登录成功" << endl;
	}
	return 0;
}

int sqlite::insert_table(char* sql)
{
	char* errmsg = NULL;
	int ret = sqlite3_exec(pdb, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		cout << "表插入失败!" << errmsg << endl;
		sqlite3_free(errmsg);
		return -1;
	}
	cout << "插入成功" << endl;
	return 0;
}

int sqlite::delete_table(char* sql)
{
	char* errmsg = NULL;
	int ret = sqlite3_exec(pdb, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		cout << "删除失败!" << errmsg << endl;
		sqlite3_free(errmsg);
		return -1;
	}
	cout << "删除成功" << endl;
	return 0;
}

int sqlite::update_table(char* sql)
{
	char* errmsg = NULL;
	int ret = sqlite3_exec(pdb, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		cout << "更新失败!" << errmsg << endl;
		sqlite3_free(errmsg);
		return -1;
	}
	cout << "更新成功" << endl;
	return 0;
}



//有选择的取出
string sqlite::select_from_table(char* sql)
{
	char** ppTable = NULL;  //存放select的结果	
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


//全部取出表中的东西，东西存在于pptable，之后再转存于容器中去
int sqlite::select_table(char* sql, vector<string>& v)
{
	char** ppTable = NULL;  //存放select的结果
	int row = 0;  //查找到的行数
	int column = 0; //查到的结果的列数
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