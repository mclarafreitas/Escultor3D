/********************************************************************************
** Form generated from reading UI file 'sculptor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCULPTOR_H
#define UI_SCULPTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sculptor
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Sculptor)
    {
        if (Sculptor->objectName().isEmpty())
            Sculptor->setObjectName(QString::fromUtf8("Sculptor"));
        Sculptor->resize(800, 600);
        centralwidget = new QWidget(Sculptor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Sculptor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Sculptor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Sculptor->setMenuBar(menubar);
        statusbar = new QStatusBar(Sculptor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Sculptor->setStatusBar(statusbar);

        retranslateUi(Sculptor);

        QMetaObject::connectSlotsByName(Sculptor);
    } // setupUi

    void retranslateUi(QMainWindow *Sculptor)
    {
        Sculptor->setWindowTitle(QCoreApplication::translate("Sculptor", "Sculptor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sculptor: public Ui_Sculptor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCULPTOR_H
