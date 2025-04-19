#include "studymodedialog.h"
#include "ui_studymodedialog.h"

studyModeDialog::studyModeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::studyModeDialog)
{
    ui->setupUi(this);
}

studyModeDialog::~studyModeDialog()
{
    delete ui;
}
