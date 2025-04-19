/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QLabel *menuTitle;
    QPushButton *addFlashcardsButton;
    QPushButton *editFlashcardsButton;
    QPushButton *deleteFlashcardsButton;
    QPushButton *studyModeButton;
    QPushButton *quitButton;
    QFrame *line_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(390, 10, 21, 591));
        QFont font;
        font.setFamilies({QString::fromUtf8("Helvetica Rounded")});
        font.setPointSize(28);
        line->setFont(font);
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(0, 30, 801, 20));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(0, 510, 801, 20));
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(0, 100, 801, 20));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(0, 140, 801, 20));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        menuTitle = new QLabel(centralwidget);
        menuTitle->setObjectName("menuTitle");
        menuTitle->setGeometry(QRect(160, 40, 491, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Helvetica Rounded")});
        font1.setPointSize(50);
        font1.setBold(false);
        menuTitle->setFont(font1);
        addFlashcardsButton = new QPushButton(centralwidget);
        addFlashcardsButton->setObjectName("addFlashcardsButton");
        addFlashcardsButton->setGeometry(QRect(330, 150, 131, 24));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("HelveticaNeue")});
        font2.setPointSize(10);
        addFlashcardsButton->setFont(font2);
        editFlashcardsButton = new QPushButton(centralwidget);
        editFlashcardsButton->setObjectName("editFlashcardsButton");
        editFlashcardsButton->setGeometry(QRect(330, 233, 131, 21));
        editFlashcardsButton->setFont(font2);
        deleteFlashcardsButton = new QPushButton(centralwidget);
        deleteFlashcardsButton->setObjectName("deleteFlashcardsButton");
        deleteFlashcardsButton->setGeometry(QRect(330, 300, 131, 24));
        deleteFlashcardsButton->setFont(font2);
        studyModeButton = new QPushButton(centralwidget);
        studyModeButton->setObjectName("studyModeButton");
        studyModeButton->setGeometry(QRect(330, 370, 131, 24));
        studyModeButton->setFont(font2);
        quitButton = new QPushButton(centralwidget);
        quitButton->setObjectName("quitButton");
        quitButton->setGeometry(QRect(330, 453, 131, 21));
        quitButton->setFont(font2);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(0, 459, 801, 31));
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        menuTitle->setText(QCoreApplication::translate("MainWindow", "FLASHCARDS!", nullptr));
        addFlashcardsButton->setText(QCoreApplication::translate("MainWindow", "Add Flashcards", nullptr));
        editFlashcardsButton->setText(QCoreApplication::translate("MainWindow", "Edit Flashcards", nullptr));
        deleteFlashcardsButton->setText(QCoreApplication::translate("MainWindow", "Delete Flashcards", nullptr));
        studyModeButton->setText(QCoreApplication::translate("MainWindow", "Study Mode", nullptr));
        quitButton->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
