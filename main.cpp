#include "main.h"
int main()
{               
	sqlite db;
	db.initdb();
	table fac;
	fac.create_course(db); //�γ̱�
	fac.create_student(db); //ѧ����
	fac.create_choose(db); //ѡ�α�
	fac.create_admin(db); //����Ա��
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
		cout << "������Ҫ������ѡ��" << endl;
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
				cout << "������Ҫ������ѡ��" << endl;
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
					cout << "��������������ѡ��" << endl;
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
				cout << "������Ҫ������ѡ��" << endl;
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
					cout << "��������������ѡ��" << endl;
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