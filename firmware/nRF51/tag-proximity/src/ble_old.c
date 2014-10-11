#include <openbeacon.h>
#include <main.h>
#include <ble.h>
#include <ble_bci.h>

#define BLE_ADDRESS_ADDR		{ 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF }
#define BLE_ADDRESS_TYPE		BDADDR_TYPE_RANDOM
#define BLE_ADDRESS			{ BLE_ADDRESS_ADDR, BLE_ADDRESS_TYPE }

static uint8_t data[BCI_ADV_MTU_DATA];
static uint8_t len;

void ble_dump(void)
{
	int16_t status;

	uint8_t mft[] = {
		0x4C, 0x00,		/* Apple's Company Identifier Code */
		0x02,			/* Device type: iBeacon */
		0x15,			/* Remaining length */
		0xAA, 0xAA, 0xAA, 0xAA,	/* UUID */
		0xAA, 0xAA, 0xAA, 0xAA,
		0xAA, 0xAA, 0xAA, 0xAA,
		0xAA, 0xAA, 0xAA, 0xAA,
		0xBB, 0xBB,		/* Major */
		0xCC, 0xCC,		/* Minor */
		0xDD			/* RSSI at 1 meter away */
	};

	//blink_fast(5);
	BLUETOOTH_INIT(status);

	if (status < 0)
		halt(5);

	len = bci_ad_put(data, BCI_AD_MFT_DATA, mft, sizeof(mft), BCI_AD_INVALID);

	bci_set_advertising_data(data, len);
	bci_set_advertise_enable(BCI_ENABLE);

	while (1)
		__WFE();
}
