#include "student.h"
int student::stu_login(sqlite& db)
{
	cout << "---------------学生登录页面---------------" << endl;

	cout << "请输入学号：";
	cin >> num;
	cout << "请输入密码：";
	cin >> stu_pwd;
	char sql[1024] = { 0 };
	sprintf_s(sql, "select *from student where num= '%s' and stu_pwd='%s'", num.data(), stu_pwd.data());
	db.stu_login(sql);
	return 0;
}
void student::change_pwd(sqlite& db)
{
	cout << "请输入要修改密码的学号：";
	cin >> num;
	cout << "请输入要修改的密码：";
	cin >> stu_pwd;
	char sql[1024] = { 0 };
	sprintf_s(sql, "update student set stu_pwd = '%s' where num = '%s';", stu_pwd.data(), num.data());
	db.update_table(sql);
}
void student::cou_insert(sqlite& db)
{
	cout << "请输入要选课学生的学号：";
	cin >> num;
	cout << "请输入要选择的课程：";
	cin >> name;
	char sql[1024] = { 0 };
	sprintf_s(sql, "insert into choose (num,name) values ('%s','%s');", num.data(), name.data());
	db.insert_table(sql);
}

void student::cou_del(sqlite& db)
{
	cout << "请输入要退课学生的学号：";
	cin >> num;
	cout << "请输入要退的课程：";
	cin >> name;
	char sql[1024] = { 0 };
	sprintf_s(sql, "delete from choose where num = '%s' and name = '%s' ;", num.data(), name.data());
	db.delete_table(sql);
}

void student::cou_show(sqlite& db)
{
	cout << "请输入学号：";
	cin >> num;
	char sql[1024] = { 0 };
	sprintf_s(sql, "select *from choose where num= '%s'", num.data());
	db.select_from_table(sql);
}
void student::stu_info()
{
	cout << "请输入学生编号：";
	cin >> id;
	cout << "请输入学生姓名：";
	cin >> name;
	cout << "请输入学生学号：";
	cin >> num;
	cout << "请输入学生账号的密码：";
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
	cout << "请输入要删除的学生编号：";
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
	cout << "请输入要修改学生的编号：";
	cin >> id;
	cout << "请输入要修改的姓名：";
	cin >> name;
	cout << "请输入要修改的学号：";
	cin >> num;
	cout << "请输入要修改的密码：";
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

	auto iter = v.begin();//auto可以自动匹配上合适的数据类型
	cout << "----------------------------------------------------";
	cout << endl;
	cout << "编号        姓名          学号           密码";
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