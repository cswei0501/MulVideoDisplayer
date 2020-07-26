#include <QApplication>
#include "Service/servicefacetory.h"
#include "mainwindow.h"

#pragma execution_character_set("utf-8")
int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QApplication a(argc, argv);
    a.setApplicationName(QObject::tr("多路视频播放器"));
    ServiceFactoryI *facetoryI = new ServiceFactory;
    a.setProperty(FACETORY_KEY, reinterpret_cast<unsigned long long>(facetoryI));

    MainWindow w;
    w.showMaximized();

    QObject::connect(qApp, &QApplication::aboutToQuit, [&]{
        delete facetoryI;
    });
    return a.exec();
}
