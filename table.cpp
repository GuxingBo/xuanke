#include "table.h"

void table::create_admin(sqlite& db)
{
	char table_sql[] = "create table if not exists admin(name text NOT NULL UNIQUE,pwd text NOT NULL);";
	db.createtable(table_sql);
}


void table::create_course(sqlite& db)
{
	char table_sql[] = "create table if not exists course(id text NOT NULL UNIQUE,name text NOT NULL,hour text NOT NULL,teacher text NOT NULL);";
	db.createtable(table_sql);
}

void table::create_student(sqlite& db)
{
	char table_sql[] = "create table if not exists student(id text NOT NULL UNIQUE,name text NOT NULL,num text NOT NULL,stu_pwd text NOT NULL);";
	db.createtable(table_sql);
}

void table::create_choose(sqlite& db)
{
	char table_sql[] = "create table if not exists choose(num text ,name text);";
	db.createtable(table_sql);
}