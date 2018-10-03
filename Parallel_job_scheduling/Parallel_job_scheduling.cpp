#include "Parallel_job_scheduling.h"
#include <string>
#include <stack>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <vector>
#include "Graph.h"

using std::string;
using std::stack;
using std::stringstream;
using std::vector;

Parallel_job_scheduling::Parallel_job_scheduling(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ScheduleJobs()));
	connect(ui.open_file_btn, SIGNAL(clicked()), this, SLOT(LoadGraphFromFile()));
	connect(ui.clear_fields, SIGNAL(clicked()), this, SLOT(ClearFields()));
}

void Parallel_job_scheduling::ScheduleJobs()
{
	ui.output_text_edit->setText("");
	if (ui.input_text_edit->toPlainText().isEmpty())
	{
		ui.output_text_edit->setText("Input empty!");
	}
	else
	{
		QStringList lines = ui.input_text_edit->toPlainText().split("\n", QString::SkipEmptyParts);

		QRegExp re("\\d*");

		if (!re.exactMatch(lines[0]))
		{
			ui.output_text_edit->setText("The first line should define the numer of vertices! It must be digit!");
		}
		else
		{
			int number_of_vertices = lines[0].toInt();
			if (number_of_vertices < 1)
			{
				ui.output_text_edit->setText("The number of vertices must be greather than 0!");
			}
			else
			{
				try
				{
					QString s;
					bool has_error = false;

					Graph graph(lines[0].toInt());
					for (int i = 1; !has_error && i < lines.size(); i++)
					{
						int from, to;
						if (CheckEdgeLine(lines[i], i, number_of_vertices, from, to))
						{
							graph.AddEdge(from, to);
						}
						else
						{
							has_error = true;
						}
					}

					if (!has_error)
						CalculateDependencies(graph);
				}
				catch (const std::exception e)
				{
					ui.output_text_edit->setText("Exception: " + QString(e.what()));
				}
			}
		}
	}
}

void Parallel_job_scheduling::ClearFields()
{
	ui.input_text_edit->clear();
	ui.output_text_edit->clear();
}

void Parallel_job_scheduling::LoadGraphFromFile()
{
	QString file_name = QFileDialog::getOpenFileName(this,
		tr("Open Graph"), "",
		tr("Text file (*.txt);"));

	if (file_name.isEmpty())
		return;

	QFile file(file_name);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(this, tr("Unable to open file"),
			file.errorString());
		return;
	}

	ClearFields();

	QTextStream stream(&file);
	while (!stream.atEnd())
	{
		ui.input_text_edit->setText(ui.input_text_edit->toPlainText() + stream.readLine() + "\n");
	}
}

bool Parallel_job_scheduling::CheckCondition(bool condition, int line_number, const QString& reason, const QString& line)
{
	if (condition)
	{
		ui.output_text_edit->setText("The " + QString::number(line_number) + " line is wrong. Reason: "+reason+" Line:" + line);
		return true;
	}
	return false;
}

bool Parallel_job_scheduling::CheckEdgeLine(const QString& line, int line_number, int number_of_vertices, int& from, int& to)
{
	int arrow_count = line.count("->");

	if (CheckCondition(arrow_count == 0, line_number, QString("The '->' is missing."), line))
		return false;

	if (CheckCondition(arrow_count > 1, line_number, QString("It contains more '->'."), line))
		return false;

	QString first = line.left(line.indexOf("->"));
	QRegExp re("\\d*");

	if (CheckCondition(!re.exactMatch(first) || first.isEmpty(), line_number, QString("First vertex is not a digit."), line))
		return false;

	if (CheckCondition(first.toInt() < 0 || first.toInt() >= number_of_vertices, line_number, QString("First vertex is out of range."), line))
		return false;

	QString second = line.right(line.count() - line.indexOf("->") - 2);

	if (CheckCondition(!re.exactMatch(second) || second.isEmpty(), line_number, QString("Second vertex is not a digit."), line))
		return false;

	if (CheckCondition(second.toInt() < 0 || second.toInt() >= number_of_vertices, line_number, QString("Second vertex is out of range."), line))
		return false;

	from = first.toInt();
	to = second.toInt();

	return true;
}

void Parallel_job_scheduling::CalculateDependencies(const Graph & graph)
{
	vector<vector<int>> dependency_tree;
	if (graph.CalculateDependencyTree(dependency_tree))
	{
		QString output = "Computational Graph:\n";

		for (int j = 0; j < dependency_tree.size(); j++)
		{
			output += "Layer " + QString::number(j) + ": ";
			for (int k = 0; k < dependency_tree[j].size(); k++)
			{
				output += QString::number(dependency_tree[j][k]) + " ";
			}
			output += "\n";
		}

		ui.output_text_edit->setText(output);
	}
	else
	{
		ui.output_text_edit->setText("There is a cycle in the graph!");
	}
}
