#include "Parallel_job_scheduling.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Parallel_job_scheduling w;
	w.show();
	return a.exec();
}
