#include "Packet.h"



Packet::Packet(const QString &payload)
    : id(0), ttl(0), waitingCycles(0), payload(payload)
{
}

void Packet::setTTL(int ttl)
{
    this->ttl = ttl;
}

int Packet::getTTL() const
{
    return ttl;
}

void Packet::setPayload(const QString &data)
{
    payload = data;
}

QString Packet::getPayload() const
{
    return payload;
}

void Packet::addHop(const QString &node)
{
    path.append(node);
}

QString Packet::getPath() const
{
    return path.join(" -> ");
}

void Packet::incrementWaitingCycles()
{
    ++waitingCycles;
}

int Packet::getWaitingCycles() const
{
    return waitingCycles;
}

void Packet::setHeaders(const DataLinkHeader &dlHeader, const TCPHeader &tcpHeader)
{
    this->dataLinkHeader = dlHeader;
    this->tcpHeader = tcpHeader;
}
