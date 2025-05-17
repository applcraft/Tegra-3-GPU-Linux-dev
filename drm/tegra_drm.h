
/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * Tegra DRM Command Submission Definitions
 */

#ifndef _UAPI_TEGRA_DRM_H_
#define _UAPI_TEGRA_DRM_H_

#include <drm/drm.h>

#define DRM_TEGRA_GEM_CREATE      0x00
#define DRM_TEGRA_GEM_MMAP        0x01
#define DRM_TEGRA_GEM_SET_FLAGS   0x02
#define DRM_TEGRA_GEM_GET_FLAGS   0x03
#define DRM_TEGRA_GEM_GET_OFFSET  0x04
#define DRM_TEGRA_SYNCPT_READ     0x05
#define DRM_TEGRA_SYNCPT_INCR     0x06
#define DRM_TEGRA_CHANNEL_OPEN    0x07
#define DRM_TEGRA_CHANNEL_CLOSE   0x08
#define DRM_TEGRA_GET_SYNCPT     0x09
#define DRM_TEGRA_SUBMIT         0x0A
#define DRM_TEGRA_GET_SYNCPT_BASE 0x0B
#define DRM_TEGRA_GEM_SET_TILING  0x0C
#define DRM_TEGRA_GEM_GET_TILING  0x0D

#define DRM_IOCTL_TEGRA_GEM_CREATE    DRM_IOWR(DRM_COMMAND_BASE + DRM_TEGRA_GEM_CREATE, struct drm_tegra_gem_create)
#define DRM_IOCTL_TEGRA_GEM_MMAP      DRM_IOWR(DRM_COMMAND_BASE + DRM_TEGRA_GEM_MMAP, struct drm_tegra_gem_mmap)
#define DRM_IOCTL_TEGRA_SUBMIT        DRM_IOWR(DRM_COMMAND_BASE + DRM_TEGRA_SUBMIT, struct drm_tegra_submit)

struct drm_tegra_gem_create {
    __u64 size;
    __u32 flags;
    __u32 handle;
};

struct drm_tegra_cmdbuf {
    __u32 handle;
    __u32 offset;
    __u32 words;
    __u32 pad;
};

struct drm_tegra_submit {
    __u32 context;
    __u32 num_syncpts;
    __u64 syncpts;
    __u32 num_cmdbufs;
    __u64 cmdbufs;
    __u32 num_relocs;
    __u64 relocs;
    __u32 timeout;
    __u32 flags;
    __u32 fence;    /* returned */
};

#endif
