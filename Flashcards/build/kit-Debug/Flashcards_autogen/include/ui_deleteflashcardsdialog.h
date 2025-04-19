/********************************************************************************
** Form generated from reading UI file 'deleteflashcardsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEFLASHCARDSDIALOG_H
#define UI_DELETEFLASHCARDSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_deleteFlashcardsDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *deleteFlashcardsDialog)
    {
        if (deleteFlashcardsDialog->objectName().isEmpty())
            deleteFlashcardsDialog->setObjectName("deleteFlashcardsDialog");
        deleteFlashcardsDialog->resize(480, 640);
        buttonBox = new QDialogButtonBox(deleteFlashcardsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 600, 461, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);

        retranslateUi(deleteFlashcardsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, deleteFlashcardsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, deleteFlashcardsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(deleteFlashcardsDialog);
    } // setupUi

    void retranslateUi(QDialog *deleteFlashcardsDialog)
    {
        deleteFlashcardsDialog->setWindowTitle(QCoreApplication::translate("deleteFlashcardsDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleteFlashcardsDialog: public Ui_deleteFlashcardsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEFLASHCARDSDIALOG_H
