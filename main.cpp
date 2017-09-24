#include <iostream>

#include <QApplication>
#include <QFile>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
#if QT_VERSION > QT_VERSION_CHECK(5, 5, 0)
    qunsetenv("QT_DEVICE_PIXEL_RATIO");
    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", QByteArray("1"));
#else
    qputenv("QT_DEVICE_PIXEL_RATIO", QByteArray("0"));
#endif

    QApplication qtApp(argc, argv);

    QFile File(":dark.qss");
    if (File.open(QFile::ReadOnly))
    {
        QString StyleSheet = QLatin1String(File.readAll());
        qtApp.setStyleSheet(StyleSheet);
    }

    MainWindow mainwindow;
    mainwindow.show();

    return qtApp.exec();
}
