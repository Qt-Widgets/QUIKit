#include "MainWindow.h"
#include <QApplication>
#include <QUIKit/NoFocusRectStyle.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NoFocusRectStyle *style = new NoFocusRectStyle(a.style());
    a.setStyle(style);
    a.setFont(QApplication::font("QMenu"));

    MainWindow w;
    w.show();

    return a.exec();
}
