/*
 *  This file is part of conky.
 *
 *  conky is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  conky is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with conky.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

//  darwin_sip.h
//  Nickolas Pylarinos
//
//  Defines for System Integrity Protection monitoring
//

#ifndef DARWIN_SIP_H
#define DARWIN_SIP_H

/* Rootless configuration flags */
#define CSR_ALLOW_UNTRUSTED_KEXTS           (1 << 0)    // 1
#define CSR_ALLOW_UNRESTRICTED_FS           (1 << 1)    // 2
#define CSR_ALLOW_TASK_FOR_PID              (1 << 2)    // 4
#define CSR_ALLOW_KERNEL_DEBUGGER           (1 << 3)    // 8
#define CSR_ALLOW_APPLE_INTERNAL            (1 << 4)    // 16
#define CSR_ALLOW_UNRESTRICTED_DTRACE       (1 << 5)    // 32
#define CSR_ALLOW_UNRESTRICTED_NVRAM        (1 << 6)    // 64
#define CSR_ALLOW_DEVICE_CONFIGURATION      (1 << 7)    // 128
#define CSR_ALLOW_ANY_RECOVERY_OS           (1 << 8)    // 256
#define CSR_ALLOW_USER_APPROVED_KEXTS       (1 << 9)    // 512

#define CSR_VALID_FLAGS (CSR_ALLOW_UNTRUSTED_KEXTS | \
        CSR_ALLOW_UNRESTRICTED_FS | \
        CSR_ALLOW_TASK_FOR_PID | \
        CSR_ALLOW_KERNEL_DEBUGGER | \
        CSR_ALLOW_APPLE_INTERNAL | \
        CSR_ALLOW_UNRESTRICTED_DTRACE | \
        CSR_ALLOW_UNRESTRICTED_NVRAM  | \
        CSR_ALLOW_DEVICE_CONFIGURATION | \
        CSR_ALLOW_ANY_RECOVERY_OS | \
        CSR_ALLOW_USER_APPROVED_KEXTS)

/* Syscalls */
// mark these symbols as weakly linked, as they may not be available
// at runtime on older OS X versions.
extern "C" {
    int csr_get_active_config(information::csr_config_t* config) __attribute__((weak_import));
};

#endif
