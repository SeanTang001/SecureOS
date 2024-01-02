#include "lfs.h"
#include "bd/lfs_rambd.h"
#include "filesystem.h"

// lfs declarations
lfs_t lfs;
lfs_rambd_t bd;
static uint8_t read_buffer[128];
static uint8_t prog_buffer[128];

const struct lfs_config cfg = {
  .context = &bd,
  .read  = &lfs_rambd_read,
  .prog  = &lfs_rambd_prog,
  .erase = &lfs_rambd_erase,
  .sync  = &lfs_rambd_sync,
  .read_size      = LFS_READ_SIZE,
  .prog_size      = LFS_PROG_SIZE,
  .block_size     = LFS_BLOCK_SIZE,
  .block_count    = LFS_BLOCK_COUNT,
  .block_cycles   = LFS_BLOCK_CYCLES,
  .cache_size     = LFS_CACHE_SIZE,
  .lookahead_size = LFS_LOOKAHEAD_SIZE,
  .read_buffer    = read_buffer,
  .prog_buffer    = prog_buffer
};

const struct lfs_rambd_config bdcfg = {
  .read_size      = 64,
  .prog_size      = 64,
  .erase_size     = LFS_BLOCK_SIZE,
  .erase_count    = LFS_BLOCK_COUNT,
  .buffer         = NULL
};

void init_filesystem(void) {
    lfs_rambd_create(&cfg, &bdcfg);
    lfs_format(&lfs, &cfg);
    int err = lfs_mount(&lfs, &cfg);
 
    /** create necessary directories */
    lfs_mkdir(&lfs, "test");
}
