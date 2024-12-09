#include "TCPHeader.h"

TCPHeader::TCPHeader() : sourcePort(0), destinationPort(0)
{
}

void TCPHeader::setSourcePort(int port)
{
    sourcePort = port;
}

void TCPHeader::setDestinationPort(int port)
{
    destinationPort = port;
}

int TCPHeader::getSourcePort() const
{
    return sourcePort;
}

int TCPHeader::getDestinationPort() const
{
    return destinationPort;
}
