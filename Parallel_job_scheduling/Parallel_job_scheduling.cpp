#include "Parallel_job_scheduling.h"
#include <string>
#include "Scheduler.h"
#include <stack>

using std::string;
using std::stack;

Parallel_job_scheduling::Parallel_job_scheduling(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(Start()));
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
			ui.output_text_edit->setText("The first line should define the numer of edges! It must be digit!");
		else
		{
			if(lines[0].toInt() != lines.size()-1 || lines.size() < 2)
				ui.output_text_edit->setText("The number of edges does not match to the given edges!");
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

					QString second = lines[i].right(lines[i].count()-lines[i].toStdString().find("->")-2);

					if (!re.exactMatch(second) || second.isEmpty())
					{
						has_error = true;
						ui.output_text_edit->setText("The " + QString::number(i) + " line is wrong. Second vertex is not a digit:" + lines[i]);
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
					stack<int> topological_sort = scheduler.CalculateTopologicalSort(graph);

					QString output = "Topological sort:\n";
					while (!topological_sort.empty())
					{
						output += QString::number(topological_sort.top()) + " ";
						topological_sort.pop();
					}
					ui.output_text_edit->setText(output);
				}
			}
		}
	}
}