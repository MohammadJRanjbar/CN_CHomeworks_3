#ifndef DATALINKHEADER_H
#define DATALINKHEADER_H

#include "../MACAddress//MACAddress.h"

class DataLinkHeader
{
public:
    DataLinkHeader();
    void setSource(const MACAddress &mac);
    void setDestination(const MACAddress &mac);

    MACAddress getSource() const;
    MACAddress getDestination() const;

private:
    MACAddress sourceMAC;
    MACAddress destinationMAC;
};

#endif // DATALINKHEADER_H
