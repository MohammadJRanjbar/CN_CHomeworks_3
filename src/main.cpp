#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "Router.h" // فرض می‌کنیم کلاس روتر و دیگر اجزاء تعریف شده‌اند
#include "AS.h"     // کلاس Autonomous System
#include "DHCPServer.h" // برای مدیریت DHCP
#include "ConfigParser.h" // برای خواندن فایل کانفیگ



struct AutonomousSystem {
    int id;
    std::string topology_type;
    int node_count;
    std::vector<int> as_gateways;
    std::vector<int> user_gateways;
    int dhcp_server;
    std::vector<int> broken_routers;
    std::vector<std::pair<int, std::vector<int>>> gateways;
    std::vector<std::pair<int, std::vector<std::pair<int, int>>>> connections_to_other_as;
};

// تابع ساخت AS و روترها
void initializeNetwork(const std::vector<AutonomousSystem>& systems) {
    for (const auto& as : systems) {
        std::cout << "Initializing AS ID: " << as.id << "\n";
        // ساخت نودها
        std::vector<Router> routers;
        for (int i = 0; i < as.node_count; ++i) {
            routers.emplace_back(Router(i));
        }

        // مدیریت روترهای خراب
        for (int broken_router : as.broken_routers) {
            if (broken_router < routers.size()) {
                routers[broken_router].setStatus(false); // خاموش کردن
            }
        }

        // تنظیم DHCP Server
        if (as.dhcp_server < routers.size()) {
            routers[as.dhcp_server].enableDHCP();
        }

        // تنظیم Gateway‌ها
        for (const auto& gateway : as.gateways) {
            int node_id = gateway.first;
            if (node_id < routers.size()) {
                for (int user : gateway.second) {
                    routers[node_id].addUser(user);
                }
            }
        }

        // ایجاد ارتباطات درون AS
        if (as.topology_type == "Mesh") {
            for (size_t i = 0; i < routers.size(); ++i) {
                for (size_t j = i + 1; j < routers.size(); ++j) {
                    routers[i].connectTo(routers[j]);
                }
            }
        } else if (as.topology_type == "RingStar") {
            for (size_t i = 0; i < routers.size(); ++i) {
                routers[i].connectTo(routers[(i + 1) % routers.size()]);
            }
        }

        // مدیریت ارتباطات بین AS‌ها
        for (const auto& connection : as.connections_to_other_as) {
            int target_as_id = connection.first;
            for (const auto& gateway_pair : connection.second) {
                int local_gateway = gateway_pair.first;
                int remote_gateway = gateway_pair.second;
                std::cout << "Connecting AS " << as.id << " gateway " << local_gateway
                          << " to AS " << target_as_id << " gateway " << remote_gateway << "\n";
            }
        }
    }
}

int main() {
    // فایل کانفیگ را بخوانید
    ConfigParser config("config.json");
    auto systems = config.parseAS();

    // شبکه را مقداردهی کنید
    initializeNetwork(systems);

    std::cout << "Network initialized. All routers are off.\n";
    return 0;
}
