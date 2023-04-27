#include <iostream>
#include <string>
#include <memory>
#include <vector>

class ElectronicDevice {
protected:
    std::string brand;
    std::string model;

public:
    ElectronicDevice(std::string brand, std::string model)
            : brand(brand), model(model) {}

    virtual void display() = 0;
};

class Smartwatch : public ElectronicDevice {
private:
    bool hasGPS;

public:
    Smartwatch(std::string brand, std::string model, bool hasGPS)
            : ElectronicDevice(brand, model), hasGPS(hasGPS) {}

    void display() override {
        std::cout << "Brand: " << brand << " Model: " << model;
        if (hasGPS) {
            std::cout << " Has GPS";
        } else {
            std::cout << " Doesn't have GPS";
        }
        std::cout << std::endl;
    }
};

class Smartphone : public ElectronicDevice {
private:
    int storageCapacity;

public:
    Smartphone(std::string brand, std::string model, int storageCapacity)
            : ElectronicDevice(brand, model), storageCapacity(storageCapacity) {}

    void display() override {
        std::cout << "Brand: " << brand << " Model: " << model
                  << " Storage Capacity: " << storageCapacity << " GB"
                  << std::endl;
    }
};

class Laptop : public ElectronicDevice {
protected:
    int ramSize;

public:
    Laptop(std::string brand, std::string model, int ramSize)
            : ElectronicDevice(brand, model), ramSize(ramSize) {}

    void display() override {
        std::cout << "Brand: " << brand << " Model: " << model
                  << " RAM Size: " << ramSize << " GB" << std::endl;
    }
};

class GamingLaptop : public Laptop {
private:
    std::string gpuModel;

public:
    GamingLaptop(std::string brand, std::string model, int ramSize,
                 std::string gpuModel)
            : Laptop(brand, model, ramSize), gpuModel(gpuModel) {}

    void display() override {
        std::cout << "Brand: " << brand << " Model: " << model
                  << " RAM Size: " << ramSize << " GB"
                  << " GPU Model: " << gpuModel << std::endl;
    }
};

class Store {
private:
    std::vector<std::unique_ptr<ElectronicDevice>> devices;

public:
    void addDevice(std::unique_ptr<ElectronicDevice> device) {
        devices.push_back(std::move(device));
    }

    void displayDevices() {
        std::cout << "Devices:\n";
        for (const auto& device : devices) {
            device->display();
        }
    }
};

int main()
{
    Store store;
    auto smartwatch = std::make_unique<Smartwatch>("Apple","6", 1);
    auto smartphone = std::make_unique<Smartphone>("Samsung","22 Ultra", 256);
    auto laptop = std::make_unique<Laptop>("Huawei", "ThinkPad", 16);
    auto laptop2 = std::make_unique<Laptop>("Huawei", "WidePad", 24);
    auto gaminglaptop = std::make_unique<GamingLaptop>("Acer", "GigaPad", 16, "Nvidia 3080TI");
    store.addDevice(std::move(smartwatch));
    store.addDevice(std::move(smartphone));
    store.addDevice(std::move(laptop));
    store.addDevice(std::move(laptop2));
    store.addDevice(std::move(gaminglaptop));
    store.displayDevices();
    return 0;
}
