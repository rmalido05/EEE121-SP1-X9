#ifndef STUDYMODEDIALOG_H
#define STUDYMODEDIALOG_H

#include <QDialog>

namespace Ui {
class studyModeDialog;
}

class studyModeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit studyModeDialog(QWidget *parent = nullptr);
    ~studyModeDialog();

private:
    Ui::studyModeDialog *ui;
};

#endif // STUDYMODEDIALOG_H
