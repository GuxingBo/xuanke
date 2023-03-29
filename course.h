#pragma once

#include <iostream>
#include <string>
#include<vector>
#include "sqlite.h"
using namespace std;
class course
{
public:
	void cou_info();
	void cou_insert_into_table(sqlite& db);

	void cou_del_info();
	void cou_remove_from_table(sqlite& db);

	void cou_che_info();
	void cou_modify_table(sqlite& db);

	void cou_show_table(sqlite& db, vector <string>& v);
private:
	string id;
	string name;
	string hour; //¿ÎÊ±
	string teacher; //ÊÚ¿Î½ÌÊ¦
};

