/********************************************************************************
** Form generated from reading UI file 'addflashcardsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFLASHCARDSDIALOG_H
#define UI_ADDFLASHCARDSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addFlashcardsDialog
{
public:
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *input_correct;
    QLabel *label_7;
    QPushButton *cancelButton;
    QPushButton *addButton;
    QLineEdit *input_question;
    QLineEdit *input_a;
    QLineEdit *input_b;
    QLineEdit *input_c;
    QLineEdit *input_d;
    QComboBox *input_difficulty;

    void setupUi(QDialog *addFlashcardsDialog)
    {
        if (addFlashcardsDialog->objectName().isEmpty())
            addFlashcardsDialog->setObjectName("addFlashcardsDialog");
        addFlashcardsDialog->resize(480, 640);
        line = new QFrame(addFlashcardsDialog);
        line->setObjectName("line");
        line->setGeometry(QRect(230, 0, 20, 641));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(addFlashcardsDialog);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(10, 0, 20, 641));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(addFlashcardsDialog);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(450, 0, 20, 641));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_4 = new QFrame(addFlashcardsDialog);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(0, 20, 481, 16));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        line_5 = new QFrame(addFlashcardsDialog);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(-3, 580, 481, 20));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        label = new QLabel(addFlashcardsDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 100, 81, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(addFlashcardsDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 150, 81, 16));
        label_2->setFont(font);
        label_3 = new QLabel(addFlashcardsDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 180, 81, 16));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);
        label_3->setMargin(0);
        label_3->setIndent(-1);
        label_3->setOpenExternalLinks(false);
        label_4 = new QLabel(addFlashcardsDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 210, 81, 16));
        label_4->setFont(font);
        label_5 = new QLabel(addFlashcardsDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 240, 81, 16));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font);
        label_5->setMargin(0);
        label_5->setIndent(-1);
        label_5->setOpenExternalLinks(false);
        label_6 = new QLabel(addFlashcardsDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 290, 111, 16));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font);
        label_6->setMargin(0);
        label_6->setIndent(-1);
        label_6->setOpenExternalLinks(false);
        input_correct = new QComboBox(addFlashcardsDialog);
        input_correct->addItem(QString());
        input_correct->addItem(QString());
        input_correct->addItem(QString());
        input_correct->addItem(QString());
        input_correct->addItem(QString());
        input_correct->setObjectName("input_correct");
        input_correct->setGeometry(QRect(140, 290, 91, 24));
        input_correct->setEditable(false);
        label_7 = new QLabel(addFlashcardsDialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 330, 111, 31));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setFont(font);
        label_7->setMargin(0);
        label_7->setIndent(-1);
        label_7->setOpenExternalLinks(false);
        cancelButton = new QPushButton(addFlashcardsDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(380, 600, 80, 24));
        addButton = new QPushButton(addFlashcardsDialog);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(290, 600, 80, 24));
        input_question = new QLineEdit(addFlashcardsDialog);
        input_question->setObjectName("input_question");
        input_question->setGeometry(QRect(100, 100, 361, 24));
        input_a = new QLineEdit(addFlashcardsDialog);
        input_a->setObjectName("input_a");
        input_a->setGeometry(QRect(100, 150, 361, 24));
        input_b = new QLineEdit(addFlashcardsDialog);
        input_b->setObjectName("input_b");
        input_b->setGeometry(QRect(100, 180, 361, 24));
        input_c = new QLineEdit(addFlashcardsDialog);
        input_c->setObjectName("input_c");
        input_c->setGeometry(QRect(100, 210, 361, 24));
        input_d = new QLineEdit(addFlashcardsDialog);
        input_d->setObjectName("input_d");
        input_d->setGeometry(QRect(100, 240, 361, 24));
        input_difficulty = new QComboBox(addFlashcardsDialog);
        input_difficulty->addItem(QString());
        input_difficulty->addItem(QString());
        input_difficulty->addItem(QString());
        input_difficulty->addItem(QString());
        input_difficulty->setObjectName("input_difficulty");
        input_difficulty->setGeometry(QRect(100, 330, 91, 24));
        input_difficulty->setEditable(false);

        retranslateUi(addFlashcardsDialog);

        QMetaObject::connectSlotsByName(addFlashcardsDialog);
    } // setupUi

    void retranslateUi(QDialog *addFlashcardsDialog)
    {
        addFlashcardsDialog->setWindowTitle(QCoreApplication::translate("addFlashcardsDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addFlashcardsDialog", "Question:", nullptr));
        label_2->setText(QCoreApplication::translate("addFlashcardsDialog", "Choice A:", nullptr));
        label_3->setText(QCoreApplication::translate("addFlashcardsDialog", "Choice B:", nullptr));
        label_4->setText(QCoreApplication::translate("addFlashcardsDialog", "Choice C:", nullptr));
        label_5->setText(QCoreApplication::translate("addFlashcardsDialog", "Choice D:", nullptr));
        label_6->setText(QCoreApplication::translate("addFlashcardsDialog", "Correct Choice:", nullptr));
        input_correct->setItemText(0, QCoreApplication::translate("addFlashcardsDialog", "<none>", nullptr));
        input_correct->setItemText(1, QCoreApplication::translate("addFlashcardsDialog", "A", nullptr));
        input_correct->setItemText(2, QCoreApplication::translate("addFlashcardsDialog", "B", nullptr));
        input_correct->setItemText(3, QCoreApplication::translate("addFlashcardsDialog", "C", nullptr));
        input_correct->setItemText(4, QCoreApplication::translate("addFlashcardsDialog", "D", nullptr));

        input_correct->setCurrentText(QCoreApplication::translate("addFlashcardsDialog", "<none>", nullptr));
        label_7->setText(QCoreApplication::translate("addFlashcardsDialog", "Difficulty:", nullptr));
        cancelButton->setText(QCoreApplication::translate("addFlashcardsDialog", "Close", nullptr));
        addButton->setText(QCoreApplication::translate("addFlashcardsDialog", "Add", nullptr));
        input_question->setInputMask(QString());
        input_question->setText(QString());
        input_question->setPlaceholderText(QCoreApplication::translate("addFlashcardsDialog", "Enter Question", nullptr));
        input_a->setPlaceholderText(QCoreApplication::translate("addFlashcardsDialog", "Enter Choice A", nullptr));
        input_b->setPlaceholderText(QCoreApplication::translate("addFlashcardsDialog", "Enter Choice B", nullptr));
        input_c->setText(QString());
        input_c->setPlaceholderText(QCoreApplication::translate("addFlashcardsDialog", "Enter Chocie C", nullptr));
        input_d->setPlaceholderText(QCoreApplication::translate("addFlashcardsDialog", "Enter Chocie D", nullptr));
        input_difficulty->setItemText(0, QCoreApplication::translate("addFlashcardsDialog", "<none>", nullptr));
        input_difficulty->setItemText(1, QCoreApplication::translate("addFlashcardsDialog", "1", nullptr));
        input_difficulty->setItemText(2, QCoreApplication::translate("addFlashcardsDialog", "2", nullptr));
        input_difficulty->setItemText(3, QCoreApplication::translate("addFlashcardsDialog", "3", nullptr));

        input_difficulty->setCurrentText(QCoreApplication::translate("addFlashcardsDialog", "<none>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addFlashcardsDialog: public Ui_addFlashcardsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFLASHCARDSDIALOG_H
