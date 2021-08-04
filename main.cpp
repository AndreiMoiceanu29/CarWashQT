#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include "Car.h"
#include "CarWash.h"
#include "Service.h"
#include "sort.h"
#include <QMetaType>
Service *Service::instance = 0;
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    qmlRegisterType<Car>("com.mge.car",1,0,"Car");
    qmlRegisterType<CarWash>("com.mge.carwash",1,0,"CarWash");
    qmlRegisterSingletonType<Service>("com.mge.service",1,0,"Service",&Service::qmlInstance);
    qRegisterMetaType<Car>();
    qRegisterMetaType<CarWash>();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
