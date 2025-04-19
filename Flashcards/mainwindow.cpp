#include "mainwindow.h"
#include "ui_mainwindow.h"

// Dialogs
#include "addflashcardsdialog.h"
#include "editflashcardsdialog.h"
#include "deleteflashcardsdialog.h"
#include "studymodedialog.h"

// CLI
#include "datastructures.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FlashcardInterface flashcard;
    flashcard.initializer();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addFlashcardsButton_clicked()
{
    addFlashcardsDialog add_flashcards_dialog;
    add_flashcards_dialog.setModal(true);
    add_flashcards_dialog.setWindowTitle("Add Flashcards");
    add_flashcards_dialog.exec();
}


void MainWindow::on_editFlashcardsButton_clicked()
{
    editFlashcardsDialog edit_flashcards_dialog;
    edit_flashcards_dialog.setModal(true);
    edit_flashcards_dialog.setWindowTitle("Edit Flashcards");
    edit_flashcards_dialog.exec();
}


void MainWindow::on_deleteFlashcardsButton_clicked()
{
    deleteFlashcardsDialog delete_flashcards_dialog;
    delete_flashcards_dialog.setModal(true);
    delete_flashcards_dialog.setWindowTitle("Delete Flashcards");
    delete_flashcards_dialog.exec();
}


void MainWindow::on_studyModeButton_clicked()
{
    studyModeDialog study_mode_dialog;
    study_mode_dialog.setModal(true);
    study_mode_dialog.setWindowTitle("Study Mode");
    study_mode_dialog.exec();
}


void MainWindow::on_quitButton_clicked()
{
    QCoreApplication::quit();
}

