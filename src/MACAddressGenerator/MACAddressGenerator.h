#ifndef MACADDRESSGENERATOR_H
#define MACADDRESSGENERATOR_H

#include "../MACAddress//MACAddress.h"
#include <set>

class MACAddressGenerator
{
public:
    MACAddressGenerator();
    ~MACAddressGenerator() = default;

    // Generate a unique MAC address
    MACAddress generate();

private:
    std::set<QString> usedAddresses;  // Keeps track of used addresses
};

#endif // MACADDRESSGENERATOR_H
