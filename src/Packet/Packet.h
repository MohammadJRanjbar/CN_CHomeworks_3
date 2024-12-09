#ifndef PACKET_H
#define PACKET_H

#include "../DataLinkHeader/DataLinkHeader.h"
#include "../TCPHeader/TCPHeader.h"
#include <QString>
#include <QDateTime>

class Packet
{
public:
    Packet();
    explicit Packet(const QString &payload);

    // Set and Get methods
    void setTTL(int ttl);
    int getTTL() const;

    void setPayload(const QString &data);
    QString getPayload() const;

    void addHop(const QString &node);
    QString getPath() const;

    void incrementWaitingCycles();
    int getWaitingCycles() const;

    void setHeaders(const DataLinkHeader &dlHeader, const TCPHeader &tcpHeader);
    int id;
    int ttl;  // Time-to-Live
    QDateTime timestamp;

private:
    QString payload;
    QStringList path;  // Nodes visited
    int waitingCycles; // Time spent in queues
    DataLinkHeader dataLinkHeader;
    TCPHeader tcpHeader;
};

#endif // PACKET_H
