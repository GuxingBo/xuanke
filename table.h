#pragma once

#include"sqlite.h"
class table
{
public:
	void create_admin(sqlite& db);
	void create_course(sqlite& db);
	void create_student(sqlite& db);
	void create_choose(sqlite& db);
};

