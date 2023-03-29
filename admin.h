#pragma once

#include <iostream>
#include <string>
#include<vector>
#include "sqlite.h"
#include "course.h"
#include "student.h"
using namespace std;
class admin
{
public:
	int login(sqlite& db);

	void add_course(sqlite& db);
	void delete_course(sqlite& db);
	void change_course(sqlite& db);
	void show_course(sqlite& db, vector <string>& v);


	void add_student(sqlite& db);
	void delete_student(sqlite& db);
	void change_student(sqlite& db);
	void show_student(sqlite& db, vector <string>& v);
private:
	string name;
	string pwd;
};

