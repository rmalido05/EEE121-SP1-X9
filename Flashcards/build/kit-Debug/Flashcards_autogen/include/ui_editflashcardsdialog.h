/********************************************************************************
** Form generated from reading UI file 'editflashcardsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITFLASHCARDSDIALOG_H
#define UI_EDITFLASHCARDSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_editFlashcardsDialog
{
public:
    QComboBox *input_correct;
    QPushButton *cancelButton;
    QFrame *line_4;
    QLabel *label_5;
    QComboBox *input_difficulty;
    QLineEdit *input_question;
    QLineEdit *input_c;
    QLabel *label_7;
    QFrame *line_5;
    QLabel *label;
    QFrame *line;
    QPushButton *addButton;
    QLineEdit *input_b;
    QFrame *line_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;
    QFrame *line_3;
    QLineEdit *input_d;
    QLineEdit *input_a;
    QLabel *label_4;
    QLabel *label_8;
    QComboBox *input_ID;

    void setupUi(QDialog *editFlashcardsDialog)
    {
        if (editFlashcardsDialog->objectName().isEmpty())
            editFlashcardsDialog->setObjectName("editFlashcardsDialog");
        editFlashcardsDialog->resize(480, 640);
        input_correct = new QComboBox(editFlashcardsDialog);
        input_correct->addItem(QString());
        input_correct->addItem(QString());
        input_correct->addItem(QString());
        input_correct->addItem(QString());
        input_correct->addItem(QString());
        input_correct->setObjectName("input_correct");
        input_correct->setGeometry(QRect(140, 340, 91, 24));
        input_correct->setEditable(false);
        cancelButton = new QPushButton(editFlashcardsDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(380, 600, 80, 24));
        line_4 = new QFrame(editFlashcardsDialog);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(0, 20, 481, 16));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        label_5 = new QLabel(editFlashcardsDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 290, 81, 16));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(12);
        label_5->setFont(font);
        label_5->setMargin(0);
        label_5->setIndent(-1);
        label_5->setOpenExternalLinks(false);
        input_difficulty = new QComboBox(editFlashcardsDialog);
        input_difficulty->addItem(QString());
        input_difficulty->addItem(QString());
        input_difficulty->addItem(QString());
        input_difficulty->addItem(QString());
        input_difficulty->setObjectName("input_difficulty");
        input_difficulty->setGeometry(QRect(100, 380, 91, 24));
        input_difficulty->setEditable(false);
        input_question = new QLineEdit(editFlashcardsDialog);
        input_question->setObjectName("input_question");
        input_question->setGeometry(QRect(100, 150, 361, 24));
        input_c = new QLineEdit(editFlashcardsDialog);
        input_c->setObjectName("input_c");
        input_c->setGeometry(QRect(100, 260, 361, 24));
        label_7 = new QLabel(editFlashcardsDialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 380, 111, 31));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setFont(font);
        label_7->setMargin(0);
        label_7->setIndent(-1);
        label_7->setOpenExternalLinks(false);
        line_5 = new QFrame(editFlashcardsDialog);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(-3, 580, 481, 20));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        label = new QLabel(editFlashcardsDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 150, 81, 16));
        label->setFont(font);
        line = new QFrame(editFlashcardsDialog);
        line->setObjectName("line");
        line->setGeometry(QRect(230, 0, 20, 641));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        addButton = new QPushButton(editFlashcardsDialog);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(290, 600, 80, 24));
        input_b = new QLineEdit(editFlashcardsDialog);
        input_b->setObjectName("input_b");
        input_b->setGeometry(QRect(100, 230, 361, 24));
        line_2 = new QFrame(editFlashcardsDialog);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(10, 0, 20, 641));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        label_2 = new QLabel(editFlashcardsDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 200, 81, 16));
        label_2->setFont(font);
        label_3 = new QLabel(editFlashcardsDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 230, 81, 16));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);
        label_3->setMargin(0);
        label_3->setIndent(-1);
        label_3->setOpenExternalLinks(false);
        label_6 = new QLabel(editFlashcardsDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 340, 111, 16));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font);
        label_6->setMargin(0);
        label_6->setIndent(-1);
        label_6->setOpenExternalLinks(false);
        line_3 = new QFrame(editFlashcardsDialog);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(450, 0, 20, 641));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        input_d = new QLineEdit(editFlashcardsDialog);
        input_d->setObjectName("input_d");
        input_d->setGeometry(QRect(100, 290, 361, 24));
        input_a = new QLineEdit(editFlashcardsDialog);
        input_a->setObjectName("input_a");
        input_a->setGeometry(QRect(100, 200, 361, 24));
        label_4 = new QLabel(editFlashcardsDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 260, 81, 16));
        label_4->setFont(font);
        label_8 = new QLabel(editFlashcardsDialog);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 100, 111, 16));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setFont(font);
        label_8->setMargin(0);
        label_8->setIndent(-1);
        label_8->setOpenExternalLinks(false);
        input_ID = new QComboBox(editFlashcardsDialog);
        input_ID->setObjectName("input_ID");
        input_ID->setGeometry(QRect(140, 100, 91, 24));
        input_ID->setEditable(false);

        retranslateUi(editFlashcardsDialog);

        QMetaObject::connectSlotsByName(editFlashcardsDialog);
    } // setupUi

    void retranslateUi(QDialog *editFlashcardsDialog)
    {
        editFlashcardsDialog->setWindowTitle(QCoreApplication::translate("editFlashcardsDialog", "Dialog", nullptr));
        input_correct->setItemText(0, QCoreApplication::translate("editFlashcardsDialog", "<none>", nullptr));
        input_correct->setItemText(1, QCoreApplication::translate("editFlashcardsDialog", "A", nullptr));
        input_correct->setItemText(2, QCoreApplication::translate("editFlashcardsDialog", "B", nullptr));
        input_correct->setItemText(3, QCoreApplication::translate("editFlashcardsDialog", "C", nullptr));
        input_correct->setItemText(4, QCoreApplication::translate("editFlashcardsDialog", "D", nullptr));

        input_correct->setCurrentText(QCoreApplication::translate("editFlashcardsDialog", "<none>", nullptr));
        cancelButton->setText(QCoreApplication::translate("editFlashcardsDialog", "Cancel", nullptr));
        label_5->setText(QCoreApplication::translate("editFlashcardsDialog", "Choice D:", nullptr));
        input_difficulty->setItemText(0, QCoreApplication::translate("editFlashcardsDialog", "<none>", nullptr));
        input_difficulty->setItemText(1, QCoreApplication::translate("editFlashcardsDialog", "1", nullptr));
        input_difficulty->setItemText(2, QCoreApplication::translate("editFlashcardsDialog", "2", nullptr));
        input_difficulty->setItemText(3, QCoreApplication::translate("editFlashcardsDialog", "3", nullptr));

        input_difficulty->setCurrentText(QCoreApplication::translate("editFlashcardsDialog", "<none>", nullptr));
        input_question->setInputMask(QString());
        input_question->setText(QString());
        input_question->setPlaceholderText(QCoreApplication::translate("editFlashcardsDialog", "Enter Question", nullptr));
        input_c->setText(QString());
        input_c->setPlaceholderText(QCoreApplication::translate("editFlashcardsDialog", "Enter Chocie C", nullptr));
        label_7->setText(QCoreApplication::translate("editFlashcardsDialog", "Difficulty:", nullptr));
        label->setText(QCoreApplication::translate("editFlashcardsDialog", "Question:", nullptr));
        addButton->setText(QCoreApplication::translate("editFlashcardsDialog", "Apply", nullptr));
        input_b->setPlaceholderText(QCoreApplication::translate("editFlashcardsDialog", "Enter Choice B", nullptr));
        label_2->setText(QCoreApplication::translate("editFlashcardsDialog", "Choice A:", nullptr));
        label_3->setText(QCoreApplication::translate("editFlashcardsDialog", "Choice B:", nullptr));
        label_6->setText(QCoreApplication::translate("editFlashcardsDialog", "Correct Choice:", nullptr));
        input_d->setPlaceholderText(QCoreApplication::translate("editFlashcardsDialog", "Enter Chocie D", nullptr));
        input_a->setPlaceholderText(QCoreApplication::translate("editFlashcardsDialog", "Enter Choice A", nullptr));
        label_4->setText(QCoreApplication::translate("editFlashcardsDialog", "Choice C:", nullptr));
        label_8->setText(QCoreApplication::translate("editFlashcardsDialog", "Flashcard No.:", nullptr));
        input_ID->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class editFlashcardsDialog: public Ui_editFlashcardsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITFLASHCARDSDIALOG_H
