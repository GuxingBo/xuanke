#pragma once
#include<iostream>
#include"sqlite3.h"
#include<string>
#include<vector>
using namespace std;
class sqlite
{
public:
	int initdb();
	int createtable(char* sql);
	int insert_table(char* sql);
	int delete_table(char* sql);
	int update_table(char* sql);
	int select_table(char* sql, vector<string>& v);
	string select_from_table(char* sql);
	int login(char* sql);
	int stu_login(char* sql);
private:
	sqlite3* pdb;

};

