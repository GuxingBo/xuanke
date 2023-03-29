#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"sqlite.h"

using namespace std;
class student
{
public:
	int stu_login(sqlite& db); //ѧ����¼

	void change_pwd(sqlite& db); //ѧ�� �޸�����

	void cou_insert(sqlite& db);  //ѧ��ѡ��

	void cou_del(sqlite& db); //ѧ���˿�

	void cou_show(sqlite& db); //�鿴��ѡ�γ�

	void stu_info();
	void stu_insert_into_table(sqlite& db); //����Ա����ѧ��

	void stu_del_info();
	void stu_remove_from_table(sqlite& db); //����Աɾ��ѧ��

	void stu_che_info();
	void stu_modify_table(sqlite& db); //����Ա�޸�ѧ��

	void stu_show_table(sqlite& db, vector <string>& v); //����Ա�鿴����ѧ��
private:
	string id;
	string name;
	string num;  //ѧ��
	string stu_pwd;
};

