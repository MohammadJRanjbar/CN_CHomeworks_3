#include "DataGenerator.h"
#include "../Packet/Packet.h"
#include <random>
#include <cmath>
#include <iostream>

double generatePareto(double scale, double shape)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> uniform(0.0, 1.0);

    double u = uniform(gen);
    return scale / std::pow(1 - u, 1.0 / shape);
}


DataGenerator::DataGenerator(QObject *parent)
    : QObject(parent),
    packetCountPerCycle(5),  // Default packet count
    ttl(10)                  // Default TTL
{
}

void DataGenerator::setDistribution(const QString &distribution)
{
    this->distribution = distribution;
}

Packet DataGenerator::generatePacket()
{
    static int packetID = 0;
    Packet packet;
    packet.id = ++packetID;
    packet.ttl = ttl;
    packet.timestamp = QDateTime::currentDateTime();
    return packet;
}

void DataGenerator::onCycleTriggered()
{
    generatedPackets.clear();

    int count = 0;
    if (distribution == "Poisson") {
        std::poisson_distribution<int> poisson(5);
        std::random_device rd;
        std::mt19937 gen(rd());
        count = poisson(gen);
    } else if (distribution == "Pareto") {
        double scale = 1.0, shape = 1.5;
        count = static_cast<int>(generatePareto(scale, shape));
    }

    for (int i = 0; i < count; ++i) {
        Packet packet = generatePacket();
        generatedPackets.push_back(packet);
        Q_EMIT packetGenerated(packet);
    }

    std::cout << "Generated " << count << " packets in this cycle.\n";
}

const std::vector<Packet> &DataGenerator::getPackets() const
{
    return generatedPackets;
}

// Pareto distribution generator
