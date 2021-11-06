/********************************************************************************
** Form generated from reading UI file 'studentfailer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTFAILER_H
#define UI_STUDENTFAILER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentFailer
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StudentFailer)
    {
        if (StudentFailer->objectName().isEmpty())
            StudentFailer->setObjectName(QString::fromUtf8("StudentFailer"));
        StudentFailer->resize(800, 600);
        centralwidget = new QWidget(StudentFailer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        StudentFailer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StudentFailer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        StudentFailer->setMenuBar(menubar);
        statusbar = new QStatusBar(StudentFailer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StudentFailer->setStatusBar(statusbar);

        retranslateUi(StudentFailer);

        QMetaObject::connectSlotsByName(StudentFailer);
    } // setupUi

    void retranslateUi(QMainWindow *StudentFailer)
    {
        StudentFailer->setWindowTitle(QCoreApplication::translate("StudentFailer", "StudentFailer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentFailer: public Ui_StudentFailer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTFAILER_H
