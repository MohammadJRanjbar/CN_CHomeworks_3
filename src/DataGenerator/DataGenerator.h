#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <QObject>
#include <QTimer>
#include <vector>
#include "../Packet/Packet.h"

class DataGenerator : public QObject
{
    Q_OBJECT

public:
    explicit DataGenerator(QObject *parent = nullptr);
    ~DataGenerator() = default;

    // Set statistical distribution
    void setDistribution(const QString &distribution);

    // Generate a single packet
    Packet generatePacket();

    // Getter for generated packets
    const std::vector<Packet> &getPackets() const;

Q_SIGNALS:
    void packetGenerated(const Packet &packet);

public Q_SLOTS:
    void onCycleTriggered();  // Slot for handling cycle events

private:
    QString distribution;
    int packetCountPerCycle;
    int ttl;
    std::vector<Packet> generatedPackets;
};

double generatePareto(double scale, double shape)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> uniform(0.0, 1.0);

    double u = uniform(gen);
    return scale / std::pow(1 - u, 1.0 / shape);
}


#endif    // DATAGENERATOR_H
