/**
 *  The MIT License (MIT)
 *
 *  Copyright (c) 2013 Paulo B. de Oliveira Filho <pauloborgesfilho@gmail.com>
 *  Copyright (c) 2013 Claudio Takahasi <claudio.takahasi@gmail.com>
 *  Copyright (c) 2013 João Paulo Rechi Vita <jprvita@gmail.com>
 *  Copyright (c) 2014 Ciro Cattuto <ciro.cattuto@gmail.com>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#ifndef __BLE_H__
#define __BLE_H__

#define ENOMEM				0x01 /* Out of memory */
#define EINVAL				0x02 /* Invalid argument */
#define EALREADY			0x03 /* Operation already in progress */
#define ENOREADY			0x04 /* Not ready */
#define EBUSY				0x05 /* Device or resource busy */
#define EINTERN				0x06 /* Internal error */


#define BDADDR_LEN				6
#define BDADDR_TYPE_PUBLIC		0
#define BDADDR_TYPE_RANDOM		1


/* Link Layer specification Section 1.3, Core 4.1 page 2500 */
typedef struct bdaddr {
	uint8_t addr[BDADDR_LEN];
	uint8_t type;
} bdaddr_t;


#define BLUETOOTH_INIT(status)              \
	do {                                    \
		static bdaddr_t addr = BLE_ADDRESS; \
		status = bci_init(&addr);           \
	} while (0)

/* Reasons for disconnection
 * Error codes, Section 1.3, Core 4.1 p. 666 */
#define	BLE_HCI_CONNECTION_TIMEOUT   				0x08
#define BLE_HCI_REMOTE_USER_TERMINATED_CONNECTION   		0x13
#define	BLE_HCI_REMOTE_DEV_TERMINATION_DUE_TO_LOW_RESOURCES	0x14
#define BLE_HCI_REMOTE_DEV_TERMINATION_DUE_TO_POWER_OFF		0x15
#define	BLE_HCI_LOCAL_HOST_TERMINATED_CONNECTION		0x16

#endif /* __BLE_H__ */
