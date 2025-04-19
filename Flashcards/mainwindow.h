#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addFlashcardsButton_clicked();

    void on_editFlashcardsButton_clicked();

    void on_deleteFlashcardsButton_clicked();

    void on_studyModeButton_clicked();

    void on_quitButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
