QT     += core
CONFIG += lrelease
CONFIG += no_keywords
CONFIG += c++20

INCLUDEPATH += $$PWD\Globals

SOURCES += \
    $$PWD/DHCPServer/DHCPServer.cpp \
    $$PWD/DataGenerator/DataGenerator.cpp \
    $$PWD/DataLinkHeader/DataLinkHeader.cpp \
    $$PWD/EventsCoordinator/EventsCoordinator.cpp \
    $$PWD/IP/IP.cpp \
    $$PWD/MACAddress/MACAddress.cpp \
    $$PWD/MACAddressGenerator/MACAddressGenerator.cpp \
    $$PWD/Packet/Packet.cpp \
    $$PWD/PortBindingManager/PortBindingManager.cpp \
    $$PWD/Port/Port.cpp \
    $$PWD/TCPHeader/TCPHeader.cpp \
    $$PWD/main.cpp

HEADERS += \
    $$PWD/DHCPServer/DHCPServer.h \
    $$PWD/DataGenerator/DataGenerator.h \
    $$PWD/DataLinkHeader/DataLinkHeader.h \
    $$PWD/EventsCoordinator/EventsCoordinator.h \
    $$PWD/Globals/Globals.h \
    $$PWD/IP/IP.h \
    $$PWD/MACAddress/MACAddress.h \
    $$PWD/MACAddressGenerator/MACAddressGenerator.h \
    $$PWD/Packet/Packet.h \
    $$PWD/PortBindingManager/PortBindingManager.h \
    $$PWD/Port/Port.h \
    $$PWD/TCPHeader/TCPHeader.h
