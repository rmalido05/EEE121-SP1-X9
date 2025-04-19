#include "mainwindow.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("[EEE121 SP1] Flashcards!");
    w.show();

    return a.exec();
}
