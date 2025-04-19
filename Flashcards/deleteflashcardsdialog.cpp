#include "deleteflashcardsdialog.h"
#include "ui_deleteflashcardsdialog.h"

deleteFlashcardsDialog::deleteFlashcardsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deleteFlashcardsDialog)
{
    ui->setupUi(this);

}

deleteFlashcardsDialog::~deleteFlashcardsDialog()
{
    delete ui;
}
