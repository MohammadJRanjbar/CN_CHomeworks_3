TARGET = cnca3d
APPNAME = cnca3
VERSION = 1.0.0
BUNDLE_VERSION = 6

# استفاده از lld برای لینک‌دهی سریع‌تر
QMAKE_LFLAGS += -fuse-ld=lld

# تنظیم مسیرهای پیش‌فرض برای استقرار
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# فایل‌های اضافی پروژه
DISTFILES += \
    .clang-format \
    .clang-tidy \
    .gitignore \
    assets/config.json

# افزودن سورس‌کد پروژه
include($$PWD/src/src.pri)

# کتابخانه‌های مورد نیاز
QT += core
QT -= gui

# استاندارد C++17
CONFIG += c++17 console
CONFIG -= app_bundle

# مسیرهای اضافه برای هدرها و منابع
INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

# تنظیم مسیر کتابخانه‌ها
LIBS += -L$$PWD/libs

# فایل‌های JSON
HEADERS += $$PWD/include/json.hpp
SOURCES += $$PWD/src/main.cpp \
           $$PWD/src/EventsCoordinator.cpp \
           $$PWD/src/DataGenerator.cpp \
           $$PWD/src/MACAddress.cpp \
           $$PWD/src/MACAddressGenerator.cpp \
           $$PWD/src/Packet.cpp \
           $$PWD/src/DataLinkHeader.cpp \
           $$PWD/src/TCPHeader.cpp

HEADERS += $$PWD/src/EventsCoordinator.h \
           $$PWD/src/DataGenerator.h \
           $$PWD/src/MACAddress.h \
           $$PWD/src/MACAddressGenerator.h \
           $$PWD/src/Packet.h \
           $$PWD/src/DataLinkHeader.h \
           $$PWD/src/TCPHeader.h

# تنظیمات برای هشدارهای SDK
CONFIG += sdk_no_version_check

# هشدارهای کامپایلر
QMAKE_CXXFLAGS += -Wall -Wextra -Wpedantic
