QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += inc .
SOURCES += \
        Model/Car.cpp \
        Model/CarWash.cpp \
        Model/Entity.cpp \
        Repository/FactorySettings.cpp \
        Service/Service.cpp \
        Utilities/Undo.cpp \
        Utilities/sort.cpp \
        Validator/Validator.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    car_database.csv \
    car_db_test.csv

HEADERS += \
    inc/Car.h \
    inc/CarWash.h \
    inc/Console.h \
    inc/Entity.h \
    inc/FactorySettings.h \
    inc/FileRepository.h \
    inc/IObserver.h \
    inc/IPublisher.h \
    inc/IRepository.h \
    inc/MemoryRepository.h \
    inc/RepoFactory.h \
    inc/Service.h \
    inc/Undo.h \
    inc/Utilities.h \
    inc/Validator.h \
    inc/sort.h \
    inc/tests/TestCSVFileRepository.h \
    inc/tests/TestCar.h \
    inc/tests/TestCarWash.h \
    inc/tests/TestEntity.h \
    inc/tests/TestFactorySettings.h \
    inc/tests/TestMemoryRepository.h \
    inc/tests/TestRepoFactory.h \
    inc/tests/TestService.h \
    inc/tests/TestValidator.h \
    inc/sort.h \
    inc/Undo.h
