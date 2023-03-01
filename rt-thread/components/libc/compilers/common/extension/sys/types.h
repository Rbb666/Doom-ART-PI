/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-09-05     Meco Man     fix bugs
 * 2020-12-16     Meco Man     add useconds_t
 */

#ifndef __SYS_TYPES_H__
#define __SYS_TYPES_H__

#include <stdint.h>
#include <stddef.h>
#include <time.h>

typedef int32_t          clockid_t;
typedef int32_t          key_t;         /* Used for interprocess communication. */
typedef int              pid_t;         /* Used for process IDs and process group IDs. */
typedef unsigned short   uid_t;
typedef unsigned short   gid_t;
typedef signed long      off_t;
typedef int              mode_t;
#ifndef ARCH_CPU_64BIT
typedef signed int       ssize_t;       /* Used for a count of bytes or an error indication. */
#else
typedef long signed int  ssize_t;       /* Used for a count of bytes or an error indication. */
#endif
typedef unsigned long    __timer_t;
typedef __timer_t        timer_t;
typedef long             suseconds_t;   /* microseconds. */
typedef unsigned long    useconds_t;    /* microseconds (unsigned) */

typedef unsigned long    dev_t;

typedef unsigned int     u_int;
typedef unsigned char    u_char;
typedef unsigned long    u_long;

#endif
