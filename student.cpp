#include "student.h"
int student::stu_login(sqlite& db)
{
	cout << "---------------ѧ����¼ҳ��---------------" << endl;

	cout << "������ѧ�ţ�";
	cin >> num;
	cout << "���������룺";
	cin >> stu_pwd;
	char sql[1024] = { 0 };
	sprintf_s(sql, "select *from student where num= '%s' and stu_pwd='%s'", num.data(), stu_pwd.data());
	db.stu_login(sql);
	return 0;
}
void student::change_pwd(sqlite& db)
{
	cout << "������Ҫ�޸������ѧ�ţ�";
	cin >> num;
	cout << "������Ҫ�޸ĵ����룺";
	cin >> stu_pwd;
	char sql[1024] = { 0 };
	sprintf_s(sql, "update student set stu_pwd = '%s' where num = '%s';", stu_pwd.data(), num.data());
	db.update_table(sql);
}
void student::cou_insert(sqlite& db)
{
	cout << "������Ҫѡ��ѧ����ѧ�ţ�";
	cin >> num;
	cout << "������Ҫѡ��Ŀγ̣�";
	cin >> name;
	char sql[1024] = { 0 };
	sprintf_s(sql, "insert into choose (num,name) values ('%s','%s');", num.data(), name.data());
	db.insert_table(sql);
}

void student::cou_del(sqlite& db)
{
	cout << "������Ҫ�˿�ѧ����ѧ�ţ�";
	cin >> num;
	cout << "������Ҫ�˵Ŀγ̣�";
	cin >> name;
	char sql[1024] = { 0 };
	sprintf_s(sql, "delete from choose where num = '%s' and name = '%s' ;", num.data(), name.data());
	db.delete_table(sql);
}

void student::cou_show(sqlite& db)
{
	cout << "������ѧ�ţ�";
	cin >> num;
	char sql[1024] = { 0 };
	sprintf_s(sql, "select *from choose where num= '%s'", num.data());
	db.select_from_table(sql);
}
void student::stu_info()
{
	cout << "������ѧ����ţ�";
	cin >> id;
	cout << "������ѧ��������";
	cin >> name;
	cout << "������ѧ��ѧ�ţ�";
	cin >> num;
	cout << "������ѧ���˺ŵ����룺";
	cin >> stu_pwd;
}
void student::stu_insert_into_table(sqlite& db)
{
	char sql[1024] = { 0 };
	sprintf_s(sql, "insert into student (id,name,num,stu_pwd) values ('%s','%s','%s','%s');", id.data(), name.data(), num.data(), stu_pwd.data());
	db.insert_table(sql);
}



void student::stu_del_info()
{
	cout << "������Ҫɾ����ѧ����ţ�";
	cin >> id;
}
void student::stu_remove_from_table(sqlite& db)
{
	char sql[1024] = { 0 };
	sprintf_s(sql, "delete from student where id = '%s';", id.data());
	db.delete_table(sql);
}


void student::stu_che_info()
{
	cout << "������Ҫ�޸�ѧ���ı�ţ�";
	cin >> id;
	cout << "������Ҫ�޸ĵ�������";
	cin >> name;
	cout << "������Ҫ�޸ĵ�ѧ�ţ�";
	cin >> num;
	cout << "������Ҫ�޸ĵ����룺";
	cin >> stu_pwd;
}
void student::stu_modify_table(sqlite& db)
{
	char sql[1024] = { 0 };
	sprintf_s(sql, "update student set name = '%s' , num ='%s' , stu_pwd='%s' where id = '%s';", name.data(), num.data(), stu_pwd.data(), id.data());
	db.update_table(sql);
}



void student::stu_show_table(sqlite& db, vector <string>& v)
{
	char sql[] = "select * from student;";
	db.select_table(sql, v);

	auto iter = v.begin();//auto�����Զ�ƥ���Ϻ��ʵ���������
	cout << "----------------------------------------------------";
	cout << endl;
	cout << "���        ����          ѧ��           ����";
	cout << endl;
	cout << "----------------------------------------------------";
	cout << endl;
	while (iter != v.end())
	{
		for (int i = 0; i < 4; i++)
		{
			cout << *iter;
			cout << "          ";
			iter++;
		}
		cout << endl;
		cout << "----------------------------------------------------";
		cout << endl;
	}
}