#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Parallel_job_scheduling.h"

class Parallel_job_scheduling : public QMainWindow
{
	Q_OBJECT

public:
	Parallel_job_scheduling(QWidget *parent = Q_NULLPTR);

private:
	Ui::Parallel_job_schedulingClass ui;
};
