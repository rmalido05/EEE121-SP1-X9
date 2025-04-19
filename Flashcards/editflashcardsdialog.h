#ifndef EDITFLASHCARDSDIALOG_H
#define EDITFLASHCARDSDIALOG_H
#include <vector>
#include <QDialog>

namespace Ui {
class editFlashcardsDialog;
}

class editFlashcardsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editFlashcardsDialog(QWidget *parent = nullptr);
    ~editFlashcardsDialog();
    void setFlashcardFields(const QString& question,
                            const std::vector<QString>& choices,
                            char answer,
                            int difficulty);

public slots:
    void addFlashcardToDropdown(int newID);

private:
    Ui::editFlashcardsDialog *ui;

private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_cancelButton_clicked();
};

#endif // EDITFLASHCARDSDIALOG_H
