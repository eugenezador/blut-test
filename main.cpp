#include "tapblut.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tapblut w;
    w.show();
    return a.exec();
}
