#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Parallel_job_scheduling.h"
#include "Graph.h"

class Parallel_job_scheduling : public QMainWindow
{
	Q_OBJECT

public:
	Parallel_job_scheduling(QWidget *parent = Q_NULLPTR);

public slots:
	void ScheduleJobs();
	void ClearFields();
	void LoadGraphFromFile();

private:
	bool CheckEdgeLine(const QString& line, int line_number, int number_of_vertices, int& from, int& to);
	void CalculateDependencies(const Graph& graph);
	bool CheckCondition(bool condition, int line_number, const QString& reason, const QString& line);
	Ui::Parallel_job_schedulingClass ui;
};
