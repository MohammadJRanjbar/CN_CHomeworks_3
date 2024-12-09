#include "MACAddressGenerator.h"

MACAddressGenerator::MACAddressGenerator() = default;

MACAddress MACAddressGenerator::generate()
{
    MACAddress newAddress;
    do {
        newAddress = MACAddress::random();
    } while (usedAddresses.find(newAddress.toString()) != usedAddresses.end());

    usedAddresses.insert(newAddress.toString());
    return newAddress;
}
