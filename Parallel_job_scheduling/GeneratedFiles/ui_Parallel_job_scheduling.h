/********************************************************************************
** Form generated from reading UI file 'Parallel_job_scheduling.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARALLEL_JOB_SCHEDULING_H
#define UI_PARALLEL_JOB_SCHEDULING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Parallel_job_schedulingClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Parallel_job_schedulingClass)
    {
        if (Parallel_job_schedulingClass->objectName().isEmpty())
            Parallel_job_schedulingClass->setObjectName(QStringLiteral("Parallel_job_schedulingClass"));
        Parallel_job_schedulingClass->resize(600, 400);
        menuBar = new QMenuBar(Parallel_job_schedulingClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Parallel_job_schedulingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Parallel_job_schedulingClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Parallel_job_schedulingClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Parallel_job_schedulingClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Parallel_job_schedulingClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Parallel_job_schedulingClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Parallel_job_schedulingClass->setStatusBar(statusBar);

        retranslateUi(Parallel_job_schedulingClass);

        QMetaObject::connectSlotsByName(Parallel_job_schedulingClass);
    } // setupUi

    void retranslateUi(QMainWindow *Parallel_job_schedulingClass)
    {
        Parallel_job_schedulingClass->setWindowTitle(QApplication::translate("Parallel_job_schedulingClass", "Parallel_job_scheduling", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Parallel_job_schedulingClass: public Ui_Parallel_job_schedulingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARALLEL_JOB_SCHEDULING_H
