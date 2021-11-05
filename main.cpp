#include "tresenraya.h"
#include "cerrar.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    TresEnRaya w;
    w.setWindowIcon(QIcon(":tres.ico"));
    w.show();
    return a.exec();
}
