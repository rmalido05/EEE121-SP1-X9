#include "editflashcardsdialog.h"
#include "ui_editflashcardsdialog.h"
#include "datastructures.h"

editFlashcardsDialog::editFlashcardsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editFlashcardsDialog)
{
    ui->setupUi(this);
}

editFlashcardsDialog::~editFlashcardsDialog()
{
    delete ui;
}

void editFlashcardsDialog::setFlashcardFields(const QString& question,
                                              const vector<QString>& choices,
                                              char answer,
                                              int difficulty) {
    ui -> input_question -> setText(question);
    ui -> input_a -> setText(choices[0]);
    ui -> input_b -> setText(choices[1]);
    ui -> input_c -> setText(choices[2]);
    ui -> input_d -> setText(choices[3]);
    ui -> input_correct -> setCurrentIndex((int)(answer-'A'));
    ui -> input_difficulty -> setCurrentIndex(difficulty);
}

void editFlashcardsDialog::on_comboBox_currentIndexChanged(int index)
{
    QString input_ID = ui -> input_ID -> currentText();
    FlashcardInterface flashcard;
    flashcard.editInterface(this, input_ID.toInt());
}


void editFlashcardsDialog::on_cancelButton_clicked()
{
    QDialog::reject() ;
}

