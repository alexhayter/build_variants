/*
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "lib/other.h"

int main() {
    stdio_init_all();
    while(true){
    do_other();
#ifdef DO_EXTRA
    printf("A little extra\n");
#endif
sleep_ms(1000);
    }
    return 0;
}