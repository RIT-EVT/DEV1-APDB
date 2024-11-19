#ifndef _APDB_
#define _APDB_

#include <EVT/dev/LCD.hpp>
#include <EVT/io/CANopen.hpp>
#include <EVT/io/GPIO.hpp>
#include <EVT/io/SPI.hpp>
#include <EVT/utils/log.hpp>
#include <LVSS.hpp>
#include <cstdio>
#include <cstring>
#include <dev/ACS71240.hpp>
#include <dev/TPS2HB50AQ1.hpp>

namespace IO = EVT::core::IO;
namespace DEV = EVT::core::DEV;

namespace APDB {

static constexpr uint8_t POWER_SWITCHES_SIZE = 2;

/**
 * This is an example of a class for a board
 */
class APDB : public CANDevice {
public:
    static constexpr uint8_t NODE_ID = 42;

    /**
     * Constructor for the APDB class, takes a pointer to an array of power switches
     * @param powerSwitches an array of pointers to power switches
     */
    explicit APDB(TPS2HB50AQ1* powerSwitches[POWER_SWITCHES_SIZE]);

    CO_OBJ_T* getObjectDictionary() override;

    uint8_t getNumElements() override;

    uint8_t getNodeID() override;

    /**
     * Handle running the core logic of the LVSS
     */
    void process();

private:
    // false = OFF, true = ON?

    TPS2HB50BQ1* powerSwitches[POWER_SWITCHES_SIZE]{};// a struct for each power switch (of which there are 3)
    // ACS781XLR currentSensor;
};

}// namespace APDB
#endif
