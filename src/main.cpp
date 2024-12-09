#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>
#include <QString>
#include "EventsCoordinator.h"
#include "DataGenerator.h"
#include "MACAddressGenerator.h"
#include "Packet.h"

// استفاده از فضای نام json
using json = nlohmann::json;

// ساختار داده برای تعریف سیستم‌های مستقل (AS)
struct AutonomousSystem {
    int id;
    std::string topology_type;
    int node_count;
    std::vector<int> as_gateways;
    std::vector<int> user_gateways;
    int dhcp_server;
    std::vector<int> broken_routers;
    // سایر جزئیات ...
};

// توابع کمکی
void parseConfig(const std::string &filePath, json &config) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open config file: " + filePath);
    }
    file >> config;
}

void createAutonomousSystem(const json &asConfig) {
    AutonomousSystem as;
    as.id = asConfig["id"];
    as.topology_type = asConfig["topology_type"];
    as.node_count = asConfig["node_count"];
    for (const auto &gateway : asConfig["as_gateways"]) {
        as.as_gateways.push_back(gateway);
    }
    for (const auto &user_gateway : asConfig["user_gateways"]) {
        as.user_gateways.push_back(user_gateway);
    }
    as.dhcp_server = asConfig["dhcp_server"];
    for (const auto &broken_router : asConfig["broken_routers"]) {
        as.broken_routers.push_back(broken_router);
    }
    std::cout << "Autonomous System " << as.id << " created.\n";
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    try {
        // خواندن فایل پیکربندی
        std::string configPath = "config.json";
        json config;
        parseConfig(configPath, config);

        // تنظیمات اولیه
        int simulationDuration = std::stoi(config["simulation_duration"]);
        int cycleDuration = std::stoi(config["cycle_duration"]);
        int ttl = config["TTL"];

        std::cout << "Simulation Duration: " << simulationDuration << " ms\n";
        std::cout << "Cycle Duration: " << cycleDuration << " ms\n";
        std::cout << "TTL: " << ttl << "\n";

        // ایجاد سیستم‌های مستقل (AS)
        for (const auto &asConfig : config["Autonomous_systems"]) {
            createAutonomousSystem(asConfig);
        }

        // ایجاد و اتصال مولد داده‌ها
        EventsCoordinator *coordinator = EventsCoordinator::instance();
        DataGenerator dataGenerator;
        dataGenerator.setDistribution(config["statistical_distribution"]);

        QObject::connect(coordinator, &EventsCoordinator::cycleTriggered,
                         &dataGenerator, &DataGenerator::onCycleTriggered);

        QObject::connect(&dataGenerator, &DataGenerator::packetGenerated, [](const Packet &packet) {
            std::cout << "Packet Generated: ID " << packet.getId() << "\n";
        });

        // شروع شبیه‌سازی
        coordinator->start();
        return app.exec();

    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return -1;
    }
}
