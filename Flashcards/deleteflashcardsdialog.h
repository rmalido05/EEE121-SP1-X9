#ifndef DELETEFLASHCARDSDIALOG_H
#define DELETEFLASHCARDSDIALOG_H

#include <QDialog>

namespace Ui {
class deleteFlashcardsDialog;
}

class deleteFlashcardsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit deleteFlashcardsDialog(QWidget *parent = nullptr);
    ~deleteFlashcardsDialog();

private:
    Ui::deleteFlashcardsDialog *ui;
};

#endif // DELETEFLASHCARDSDIALOG_H
