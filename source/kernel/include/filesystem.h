#pragma once

#include "lfs.h"
#include "bd/lfs_rambd.h"

// test configuration options
#ifndef LFS_READ_SIZE
#define LFS_READ_SIZE 64
#endif

#ifndef LFS_PROG_SIZE
#define LFS_PROG_SIZE LFS_READ_SIZE
#endif

#ifndef LFS_BLOCK_SIZE
#define LFS_BLOCK_SIZE 512
#endif

#ifndef LFS_BLOCK_COUNT
#define LFS_BLOCK_COUNT 1024
#endif

#ifndef LFS_BLOCK_CYCLES
#define LFS_BLOCK_CYCLES 1024
#endif

#ifndef LFS_CACHE_SIZE
#define LFS_CACHE_SIZE (64 % LFS_PROG_SIZE == 0 ? 64 : LFS_PROG_SIZE)
#endif

#ifndef LFS_LOOKAHEAD_SIZE
#define LFS_LOOKAHEAD_SIZE 16
#endif

void filesystem_init(void);