#include "EventsCoordinator.h"
#include <QTimer>
#include <QCoreApplication>
#include <iostream>

// Constructor
EventsCoordinator::EventsCoordinator(QThread *parent)
    : QThread(parent)
{
    // Initialization logic if needed
}

// Singleton instance
EventsCoordinator *EventsCoordinator::instance(QThread *parent)
{
    if (m_self == nullptr) {
        m_self = new EventsCoordinator(parent);
    }
    return m_self;
}

// Release Singleton instance
void EventsCoordinator::release()
{
    delete m_self;
    m_self = nullptr;
}

// Thread's run method
void EventsCoordinator::run()
{
    QTimer timer;
    timer.moveToThread(this);

    // Example of setting up a recurring simulation cycle
    connect(&timer, &QTimer::timeout, this, [this]() {
        Q_EMIT cycleTriggered();
    });

    // Start the timer with cycle duration (10ms as per config example)
    timer.start(10);

    // Event loop for the thread
    exec();
}


