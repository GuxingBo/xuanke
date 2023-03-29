#include "choose.h"

void choose::choose_insert(sqlite& db)
{
	student _student;
	_student.cou_insert(db);
}

void choose::choose_del(sqlite& db)
{
	student _student;
	_student.cou_del(db);
}
void  choose::choose_show(sqlite& db)
{
	student _student;
	_student.cou_show(db);
}