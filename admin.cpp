#include "admin.h"
int admin::login(sqlite& db)
{
	cout << "---------------管理员登录页面---------------" << endl;

	cout << "请输入用户名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;
	char sql[1024] = { 0 };
	sprintf_s(sql, "select *from admin where name= '%s' and pwd='%s'", name.data(), pwd.data());
	db.login(sql);
	int a = 0;
	return 0;
}

void admin::add_course(sqlite& db)
{
	course _course;
	_course.cou_info();
	_course.cou_insert_into_table(db);
}
void admin::delete_course(sqlite& db)
{
	course _course;
	_course.cou_del_info();
	_course.cou_remove_from_table(db);
}
void admin::change_course(sqlite& db)
{
	course _course;
	_course.cou_che_info();
	_course.cou_modify_table(db);
}
void admin::show_course(sqlite& db, vector <string>& v)
{
	course _course;
	_course.cou_show_table(db, v);
}



void admin::add_student(sqlite& db)
{
	student _student;
	_student.stu_info();
	_student.stu_insert_into_table(db);
}
void admin::delete_student(sqlite& db)
{
	student _student;
	_student.stu_del_info();
	_student.stu_remove_from_table(db);
}
void admin::change_student(sqlite& db)
{
	student _student;
	_student.stu_che_info();
	_student.stu_modify_table(db);
}
void admin::show_student(sqlite& db, vector<string>& v)
{
	student _student;
	_student.stu_show_table(db, v);
}