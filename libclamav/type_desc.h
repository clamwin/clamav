/*
 *  ClamAV bytecode internal API
 *
 *  Copyright (C) 2013-2020 Cisco Systems, Inc. and/or its affiliates. All rights reserved.
 *  Copyright (C) 2009-2013 Sourcefire, Inc.
 *
 *  Authors: Török Edvin
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *  MA 02110-1301, USA.
 */
#ifndef TYPE_DESC_H
#define TYPE_DESC_H

#include "clambc.h"
struct cli_bc_ctx;

enum derived_t {
    DFunctionType,
    DPointerType,
    DStructType,
    DPackedStructType,
    DArrayType
};

struct cli_bc_type {
    enum derived_t kind;
    uint16_t *containedTypes;
    unsigned numElements;
    uint32_t size;
    unsigned align;
};

typedef uint32_t (*cli_apicall_int2)(struct cli_bc_ctx *, uint32_t, uint32_t);
typedef uint32_t (*cli_apicall_pointer)(struct cli_bc_ctx *, void *, uint32_t);
typedef uint32_t (*cli_apicall_int1)(struct cli_bc_ctx *, uint32_t);
typedef void *(*cli_apicall_malloclike)(struct cli_bc_ctx *, uint32_t);
typedef int32_t (*cli_apicall_ptrbuffdata)(struct cli_bc_ctx *, void *, uint32_t, uint32_t, uint32_t, uint32_t);
typedef int32_t (*cli_apicall_allocobj)(struct cli_bc_ctx *);
typedef void *(*cli_apicall_bufget)(struct cli_bc_ctx *, int32_t, uint32_t);
typedef int32_t (*cli_apicall_int3)(struct cli_bc_ctx *, int32_t, int32_t, int32_t);
typedef int32_t (*cli_apicall_2bufs)(struct cli_bc_ctx *, void *, int32_t, void *, int32_t);
typedef int32_t (*cli_apicall_ptrbufid)(struct cli_bc_ctx *, void *, int32_t, int32_t);

struct cli_apicall {
    const char *name;
    uint16_t type; /* type id in cli_apicall_types array */
    uint16_t idx;
    uint8_t kind;
};

struct cli_apiglobal {
    const char *name;
    enum bc_global globalid;
    uint16_t type;
    unsigned offset;
};

#ifdef __cplusplus
extern "C" {
#endif
/* win32 dll needs explicit dllimport for variables */
#if defined(_WIN32) && defined(__cplusplus)
#define BCAPI __declspec(dllimport)
#else
#define BCAPI
#endif

BCAPI extern const struct cli_bc_type cli_apicall_types[];
BCAPI extern const unsigned cli_apicall_maxtypes;

BCAPI extern const struct cli_apiglobal cli_globals[];

BCAPI extern const struct cli_apicall cli_apicalls[];
BCAPI extern const cli_apicall_int2 cli_apicalls0[];
BCAPI extern const cli_apicall_pointer cli_apicalls1[];
BCAPI extern const cli_apicall_int1 cli_apicalls2[];
BCAPI extern const cli_apicall_malloclike cli_apicalls3[];
BCAPI extern const cli_apicall_ptrbuffdata cli_apicalls4[];
BCAPI extern const cli_apicall_allocobj cli_apicalls5[];
BCAPI extern const cli_apicall_bufget cli_apicalls6[];
BCAPI extern const cli_apicall_int3 cli_apicalls7[];
BCAPI extern const cli_apicall_2bufs cli_apicalls8[];
BCAPI extern const cli_apicall_ptrbufid cli_apicalls9[];
BCAPI extern const unsigned cli_apicall_maxapi;
BCAPI extern const unsigned cli_apicall_maxglobal;

#ifdef __cplusplus
}
#endif
#endif
