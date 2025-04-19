#ifndef ADDFLASHCARDSDIALOG_H
#define ADDFLASHCARDSDIALOG_H

#include <QDialog>

namespace Ui {
class addFlashcardsDialog;
}

class addFlashcardsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addFlashcardsDialog(QWidget *parent = nullptr);
    ~addFlashcardsDialog();
signals:
    void flashcardAdded(int newID);

private slots:
    void on_addButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::addFlashcardsDialog *ui;
};

#endif // ADDFLASHCARDSDIALOG_H
