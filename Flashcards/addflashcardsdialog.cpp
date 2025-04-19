#include "addflashcardsdialog.h"
#include "ui_addflashcardsdialog.h"
#include <QMessageBox>
#include <vector>
#include "datastructures.h"

addFlashcardsDialog::addFlashcardsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addFlashcardsDialog)
{
    ui->setupUi(this);
}

int add(QWidget* parent, int diff, QString question, QString answer, vector<QString> choices) {
    FlashcardInterface flashcard;
    flashcard.initializer();
    int id = flashcard.addInterface(parent, diff, question, answer, choices);
    return id;
}

addFlashcardsDialog::~addFlashcardsDialog()
{
    delete ui;
}

void addFlashcardsDialog::on_addButton_clicked()
{
    QString question = ui -> input_question -> text();
    QString choice_a = ui -> input_a -> text();
    QString choice_b = ui -> input_b -> text();
    QString choice_c = ui -> input_c -> text();
    QString choice_d = ui -> input_d -> text();
    QString answer = ui -> input_correct -> currentText();
    QString user_diff = ui -> input_difficulty -> currentText();
    vector<QString> choices;
    choices.push_back(choice_a);
    choices.push_back(choice_b);
    choices.push_back(choice_c);
    choices.push_back(choice_d);
    if ((question.isEmpty()) &&
        (choice_a.isEmpty()) &&
        (choice_b.isEmpty()) &&
        (choice_c.isEmpty()) &&
        (choice_d.isEmpty()) &&
        (answer == "<none>") &&
        (user_diff == "<none>")) {
        QMessageBox::information(this, "Error!", "Invalid Input.");
    }
    else {
        int newID = add(this, user_diff.toInt(), question, answer, choices);
        if (newID != -1) {
            emit flashcardAdded(newID);
        }
    }

    ui -> input_question -> clear();
    ui -> input_a -> clear();
    ui -> input_b -> clear();
    ui -> input_c -> clear();
    ui -> input_d -> clear();
    ui -> input_correct -> setCurrentIndex(0);
    ui -> input_difficulty -> setCurrentIndex(0);
    choices.clear();
    }

void addFlashcardsDialog::on_cancelButton_clicked()
{
    QDialog::reject() ;
}

