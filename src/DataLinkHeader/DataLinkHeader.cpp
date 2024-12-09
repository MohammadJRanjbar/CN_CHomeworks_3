#include "DataLinkHeader.h"

DataLinkHeader::DataLinkHeader()
    : sourceMAC(MACAddress()), destinationMAC(MACAddress())
{
}

void DataLinkHeader::setSource(const MACAddress &mac)
{
    sourceMAC = mac;
}

void DataLinkHeader::setDestination(const MACAddress &mac)
{
    destinationMAC = mac;
}

MACAddress DataLinkHeader::getSource() const
{
    return sourceMAC;
}

MACAddress DataLinkHeader::getDestination() const
{
    return destinationMAC;
}
