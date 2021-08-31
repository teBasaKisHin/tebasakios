#pragma once

#include <cstdint>
#include <array>

#include "error.hpp"

namespace pci {
    // CONFIG_ADRESSレジスタのIOポートアドレス
    const uint16_t kConfigAddress = 0x0cf8;
    // CONDIG_DATAレジスタのIOポートアドレス
    const uint16_t kConfigData = 0x0cfc;

    void WriteAddress(uint32_t address);
    void WriteData(uint32_t value);
    uint32_t ReadData();

    uint16_t ReadVendorId(uint8_t bus, uint8_t device, uint8_t function);
    uint16_t ReadDeviceId(uint8_t bus, uint8_t device, uint8_t fuction);
    uint16_t ReadHeaderType(uint8_t bus, uint8_t device, uint8_t fuction);
    
    uint32_t ReadClassCode(uint8_t bus, uint8_t device, uint8_t fuction);
    uint32_t ReadBusNumbers(uint8_t bus, uint8_t device, uint8_t fuction);

    bool IsSingleFunctionDevice(uint8_t header_type);

    // PCIデバイスを操作するための基礎データを格納する
    struct Device {
        uint8_t bus, device, function, header_type;
    };

    inline std::array<Device, 32> devices;

    inline int num_device;

    Error ScanAllBus();
}