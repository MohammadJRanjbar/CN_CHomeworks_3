#ifndef EVENTSCOORDINATOR_H
#define EVENTSCOORDINATOR_H

#include <chrono>

#include <QObject>
#include <QThread>

class EventsCoordinator : public QThread
{
    Q_OBJECT

    typedef std::chrono::milliseconds Millis;

    explicit EventsCoordinator(QThread *parent = nullptr);

public:    // constructors
    ~EventsCoordinator() override = default;
    static EventsCoordinator *instance(QThread *parent = nullptr);
    static void               release();
    void run() override;

public:    // methods

public:    // getter and setters
Q_SIGNALS:
    void cycleTriggered();

public Q_SLOTS:

private Q_SLOTS:

private:    // members
    inline static EventsCoordinator *m_self = nullptr;
};

#endif    // EVENTSCOORDINATOR_H
