#include "Parallel_job_scheduling.h"
#include <string>
#include "Scheduler.h"
#include <stack>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <vector>

using std::string;
using std::stack;
using std::stringstream;
using std::vector;

Parallel_job_scheduling::Parallel_job_scheduling(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(Start()));
	connect(ui.open_file_btn, SIGNAL(clicked()), this, SLOT(LoadGraphFromFile()));
}

void Parallel_job_scheduling::Start()
{
	ui.output_text_edit->setText("");
	if(ui.input_text_edit->toPlainText().isEmpty())
		ui.output_text_edit->setText("Input empty!");
	else
	{
		QStringList lines = ui.input_text_edit->toPlainText().split("\n", QString::SkipEmptyParts);

		QRegExp re("\\d*");
	
		

		if (!re.exactMatch(lines[0]))
			ui.output_text_edit->setText("The first line should define the numer of vertices! It must be digit!");
		else
		{
			int number_of_vertices = lines[0].toInt();
			if (number_of_vertices < 1)
				ui.output_text_edit->setText("The number of vertices must be greather than 0!");
			else
			{
				QString s;
				bool has_error = false;
				
				Graph graph(lines[0].toInt());
				for (int i = 1; i < lines.size(); i++)
				{
					int arrow_count = lines[i].count("->");
					if (arrow_count == 0)
					{
						has_error = true;
						ui.output_text_edit->setText("The "+QString::number(i)+" line is wrong. The '->' is missing. Line:" +lines[i]);
						break;
					}
					else if (arrow_count > 1)
					{
						has_error = true;
						ui.output_text_edit->setText("The " + QString::number(i) + " line is wrong. It contains more '->'. Line:" + lines[i]);
						break;
					}
					
					QString first = lines[i].left(lines[i].toStdString().find("->"));

					if (!re.exactMatch(first) || first.isEmpty())
					{
						has_error = true;
						ui.output_text_edit->setText("The " + QString::number(i) + " line is wrong. First vertex is not a digit:" + lines[i]);
						break;
					}

					if (first.toInt() < 0 || first.toInt() > number_of_vertices)
					{
						has_error = true;
						ui.output_text_edit->setText("The " + QString::number(i) + " line is wrong. First vertex is out of range:" + lines[i]);
						break;
					}

					QString second = lines[i].right(lines[i].count()-lines[i].toStdString().find("->")-2);

					if (!re.exactMatch(second) || second.isEmpty())
					{
						has_error = true;
						ui.output_text_edit->setText("The " + QString::number(i) + " line is wrong. Second vertex is not a digit:" + lines[i]);
						break;
					}

					if (second.toInt() < 0 || second.toInt() > number_of_vertices)
					{
						has_error = true;
						ui.output_text_edit->setText("The " + QString::number(i) + " line is wrong. Second vertex is out of range:" + lines[i]);
						break;
					}

					Edge edge;
					edge.from = first.toInt();
					edge.to = second.toInt();
					graph.AddEdge(edge);
				}
				if (!has_error)
				{
					Scheduler scheduler;
					vector<vector<int>> topological_sort2 = scheduler.CalculateComputationalGraph(graph);
					QString output = "Computational Graph:\n";
					
					for (int j = 0;j<topological_sort2.size();j++)
					{
						output += "Layer "+QString::number(j)+": ";
						for (int k = 0; k<topological_sort2[j].size(); k++)
							output += QString::number(topological_sort2[j][k]) + " ";
						output += "\n";
					}

					ui.output_text_edit->setText(output);
				}
			}
		}
	}
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

		ui.input_text_edit->clear();
		ui.output_text_edit->clear();

		QTextStream stream(&file);
		while (!stream.atEnd())
			ui.input_text_edit->setText(ui.input_text_edit->toPlainText() + stream.readLine() + "\n");
}