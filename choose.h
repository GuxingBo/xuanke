#pragma once
#include<iostream>
#include<string>
#include"sqlite.h"
#include"student.h"
using namespace std;
class choose
{
public:
	void choose_insert(sqlite& db); //ѧ��ѡ��

	void choose_del(sqlite& db); //ѧ���˿�

	void choose_show(sqlite& db); //��ѯ��ѡ�γ�
private:
	string id;
	string name;
};

