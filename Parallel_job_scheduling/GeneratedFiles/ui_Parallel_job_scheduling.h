/********************************************************************************
** Form generated from reading UI file 'Parallel_job_scheduling.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARALLEL_JOB_SCHEDULING_H
#define UI_PARALLEL_JOB_SCHEDULING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Parallel_job_schedulingClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QTextEdit *input_text_edit;
    QFrame *frame;
    QTextEdit *output_text_edit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Parallel_job_schedulingClass)
    {
        if (Parallel_job_schedulingClass->objectName().isEmpty())
            Parallel_job_schedulingClass->setObjectName(QStringLiteral("Parallel_job_schedulingClass"));
        Parallel_job_schedulingClass->resize(480, 335);
        centralWidget = new QWidget(Parallel_job_schedulingClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 471, 279));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        input_text_edit = new QTextEdit(gridLayoutWidget);
        input_text_edit->setObjectName(QStringLiteral("input_text_edit"));

        gridLayout->addWidget(input_text_edit, 0, 0, 1, 1);

        frame = new QFrame(gridLayoutWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(380, 100));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame, 1, 0, 1, 1);

        output_text_edit = new QTextEdit(gridLayoutWidget);
        output_text_edit->setObjectName(QStringLiteral("output_text_edit"));
        output_text_edit->setReadOnly(true);

        gridLayout->addWidget(output_text_edit, 2, 0, 1, 1);

        Parallel_job_schedulingClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Parallel_job_schedulingClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 21));
        Parallel_job_schedulingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Parallel_job_schedulingClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Parallel_job_schedulingClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Parallel_job_schedulingClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Parallel_job_schedulingClass->setStatusBar(statusBar);

        retranslateUi(Parallel_job_schedulingClass);

        QMetaObject::connectSlotsByName(Parallel_job_schedulingClass);
    } // setupUi

    void retranslateUi(QMainWindow *Parallel_job_schedulingClass)
    {
        Parallel_job_schedulingClass->setWindowTitle(QApplication::translate("Parallel_job_schedulingClass", "Parallel job scheduling", nullptr));
        pushButton->setText(QApplication::translate("Parallel_job_schedulingClass", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Parallel_job_schedulingClass: public Ui_Parallel_job_schedulingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARALLEL_JOB_SCHEDULING_H
