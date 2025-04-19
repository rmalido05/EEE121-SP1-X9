/********************************************************************************
** Form generated from reading UI file 'studymodedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDYMODEDIALOG_H
#define UI_STUDYMODEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_studyModeDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *studyModeDialog)
    {
        if (studyModeDialog->objectName().isEmpty())
            studyModeDialog->setObjectName("studyModeDialog");
        studyModeDialog->resize(480, 640);
        buttonBox = new QDialogButtonBox(studyModeDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 600, 461, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);

        retranslateUi(studyModeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, studyModeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, studyModeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(studyModeDialog);
    } // setupUi

    void retranslateUi(QDialog *studyModeDialog)
    {
        studyModeDialog->setWindowTitle(QCoreApplication::translate("studyModeDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studyModeDialog: public Ui_studyModeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDYMODEDIALOG_H
