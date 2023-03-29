#include "course.h"
void course::cou_info()
{
	cout << "请输入课程编号：";
	cin >> id;
	cout << "请输入课程名称：";
	cin >> name;
	cout << "请输入课程时长：";
	cin >> hour;
	cout << "请输入授课教师：";
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
	cout << "请输入要删除的课程编号：";
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
	cout << "请输入要修改课程的编号：";
	cin >> id;
	cout << "请输入要修改课程的名称：";
	cin >> name;
	cout << "请输入要修改的课程的课程时长：";
	cin >> hour;
	cout << "请输入要修改课程的授课教师：";
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
	cout << "编号        课程名        课时          授课教师";
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