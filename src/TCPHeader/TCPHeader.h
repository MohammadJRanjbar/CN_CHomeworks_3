#ifndef TCPHEADER_H
#define TCPHEADER_H

class TCPHeader
{
public:
    TCPHeader();
    void setSourcePort(int port);
    void setDestinationPort(int port);

    int getSourcePort() const;
    int getDestinationPort() const;

private:
    int sourcePort;
    int destinationPort;
};

#endif // TCPHEADER_H
