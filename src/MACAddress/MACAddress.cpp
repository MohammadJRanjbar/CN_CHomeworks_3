#include "MACAddress.h"
#include <random>
#include <sstream>
#include <iomanip>

MACAddress::MACAddress() : address("00:00:00:00:00:00") {}

MACAddress::MACAddress(const QString &address) : address(address) {}

QString MACAddress::toString() const
{
    return address;
}

MACAddress MACAddress::random()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    std::ostringstream oss;
    for (int i = 0; i < 6; ++i) {
        if (i > 0) oss << ":";
        oss << std::hex << std::setw(2) << std::setfill('0') << dis(gen);
    }

    return MACAddress(QString::fromStdString(oss.str()));
}
