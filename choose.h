#pragma once
#include<iostream>
#include<string>
#include"sqlite.h"
#include"student.h"
using namespace std;
class choose
{
public:
	void choose_insert(sqlite& db); //学生选课

	void choose_del(sqlite& db); //学生退课

	void choose_show(sqlite& db); //查询已选课程
private:
	string id;
	string name;
};

