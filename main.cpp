#include "main.h"
int main()
{               
	sqlite db;
	db.initdb();
	table fac;
	fac.create_course(db); //课程表
	fac.create_student(db); //学生表
	fac.create_choose(db); //选课表
	fac.create_admin(db); //管理员表
	admin root;
	student stu;
	menu men;
	choose cho;
	int a = 0;
	int b = 0;


	while (1)
	{
	flag:
		men.menu1();

		int op = 0;
		cout << "请输入要操作的选项" << endl;
		cin >> op;
		if (3 == op)
		{
			return 0;
		}
		switch (op)
		{
		case(1):
			root.login(db);
			while (1)
			{
				men.menu2();
				vector <string> v;
				int op = 0;
				cout << "请输入要操作的选项" << endl;
				cin >> op;
				if (10 == op)
				{
					return 0;
				}
				switch (op)
				{
				case(1):
					root.add_course(db);
					break;
				case(2):
					root.change_course(db);
					break;
				case(3):
					root.delete_course(db);
					break;
				case(4):
					v.clear();
					root.show_course(db, v);
					break;
				case(5):
					root.add_student(db);
					break;
				case(6):
					root.change_student(db);
					break;
				case(7):
					root.delete_student(db);
					break;
				case(8):
					v.clear();
					root.show_student(db, v);
					break;
				case(9):
					goto flag;
					break;
				default:
					cout << "输入有误，请重新选择" << endl;
					break;
				}
			}
		case(2):
			stu.stu_login(db);
			while(1)
			{
				men.menu3();

				vector <string> v;
				int op = 0;
				cout << "请输入要操作的选项" << endl;
				cin >> op;
				if (7 == op)
				{
					return 0;
				}
				switch (op)
				{
				case(1):
					stu.change_pwd(db);
					break;
				case(2):
					v.clear();
					root.show_course(db, v);
					cho.choose_insert(db);
					break;
				case(3):
					cho.choose_del(db);
					break;
				case(4):
					cho.choose_show(db);
					break;
				case(5):
					v.clear();
					root.show_course(db,v);
					break;
				case(6):
					goto flag;
					break;
				default:
					cout << "输入有误，请重新选择" << endl;
					break;
				}
			}
		}

	}
	//cho.choose_show(db);
	//stu.stu_login(db);
	//root.login();
	//root.add_course(db);
	//root.add_student(db);
	//root.change_course(db);
	//root.change_student(db);
	//root.delete_course(db);
	//root.delete_student(db);
	//vector <string> v;
	//root.show_course(db,v);
	//v.clear();
	//root.show_student(db,v);
	return 0;
}