#include "course.h"
void course::cou_info()
{
	cout << "������γ̱�ţ�";
	cin >> id;
	cout << "������γ����ƣ�";
	cin >> name;
	cout << "������γ�ʱ����";
	cin >> hour;
	cout << "�������ڿν�ʦ��";
	cin >> teacher;
}
void course::cou_insert_into_table(sqlite& db)
{
	char sql[1024] = { 0 };
	sprintf_s(sql, "insert into course (id,name,hour,teacher) values ('%s','%s','%s','%s');", id.data(), name.data(), hour.data(), teacher.data());
	db.insert_table(sql);
}

void course::cou_del_info()
{
	cout << "������Ҫɾ���Ŀγ̱�ţ�";
	cin >> id;
}
void course::cou_remove_from_table(sqlite& db)
{
	char sql[1024] = { 0 };
	sprintf_s(sql, "delete from course where id = '%s';", id.data());
	db.delete_table(sql);
}

void course::cou_che_info()
{
	cout << "������Ҫ�޸Ŀγ̵ı�ţ�";
	cin >> id;
	cout << "������Ҫ�޸Ŀγ̵����ƣ�";
	cin >> name;
	cout << "������Ҫ�޸ĵĿγ̵Ŀγ�ʱ����";
	cin >> hour;
	cout << "������Ҫ�޸Ŀγ̵��ڿν�ʦ��";
	cin >> teacher;
}
void course::cou_modify_table(sqlite& db)
{
	char sql[1024] = { 0 };
	sprintf_s(sql, "update course set name = '%s' , hour ='%s' , teacher='%s' where id = '%s';", name.data(), hour.data(), teacher.data(), id.data());
	db.update_table(sql);
}

void course::cou_show_table(sqlite& db, vector <string>& v)
{
	char sql[] = "select * from course;";
	db.select_table(sql, v);

	auto iter = v.begin();
	cout << "----------------------------------------------------";
	cout << endl;
	cout << "���        �γ���        ��ʱ          �ڿν�ʦ";
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