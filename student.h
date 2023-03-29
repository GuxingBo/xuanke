#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"sqlite.h"

using namespace std;
class student
{
public:
	int stu_login(sqlite& db); //学生登录

	void change_pwd(sqlite& db); //学生 修改密码

	void cou_insert(sqlite& db);  //学生选课

	void cou_del(sqlite& db); //学生退课

	void cou_show(sqlite& db); //查看已选课程

	void stu_info();
	void stu_insert_into_table(sqlite& db); //管理员增加学生

	void stu_del_info();
	void stu_remove_from_table(sqlite& db); //管理员删除学生

	void stu_che_info();
	void stu_modify_table(sqlite& db); //管理员修改学生

	void stu_show_table(sqlite& db, vector <string>& v); //管理员查看所有学生
private:
	string id;
	string name;
	string num;  //学号
	string stu_pwd;
};

