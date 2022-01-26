// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#pragma once

// //////////
// ARTSEY layer ids (needed everywhere)
#define LAYER_ID_GLOBAL -1
#define BASE 0
#define NUM 1
#define SYM 2
#define PAR 3
#define NAV 4
#define CUS 5
#define BIG_SYM 6
#define BIG_FUN 7

// //////////
// Board tuning so standard layout/map can be built programatically
#ifdef KEYBOARD_crkbd_rev1
#include "boards/crkbd_rev1.h"
#endif

// //////////
// Include layers last so all overrides and ids are set prior to processing
#include "layers.h"

// //////////
// Keymap generation stuff to use left/right handedness based on qmk compile env selection
// Standard ARTSEY layer definitions

// Artsey layout wrapper
#ifdef KEYBOARD_crkbd_rev1
#define ARTSEY_LAYOUT_WRAPPER(...) LAYOUT_split_3x5_3(__VA_ARGS__)
#else
#define ARTSEY_LAYOUT_WRAPPER(...) LAYOUT(__VA_ARGS__)
#endif

// Allow proper auto selection of std size via keymaps
#ifdef ARTSEY_SIZE_STD
// Allow proper auto selection of left / right via keymaps
#ifdef ARTSEY_HAND_LEFT
#define ARTSEY_STD_LAYER_BASE ARTSEY_STD_LAYER_BASE_LEFT
#define ARTSEY_STD_LAYER_NUM ARTSEY_STD_LAYER_NUM_LEFT
#define ARTSEY_STD_LAYER_SYM ARTSEY_STD_LAYER_SYM_LEFT
#define ARTSEY_STD_LAYER_PAR ARTSEY_STD_LAYER_PAR_LEFT
#define ARTSEY_STD_LAYER_NAV ARTSEY_STD_LAYER_NAV_LEFT
#define ARTSEY_STD_LAYER_CUS ARTSEY_STD_LAYER_CUS_LEFT
#endif
#ifdef ARTSEY_HAND_RIGHT
#define ARTSEY_STD_LAYER_BASE ARTSEY_STD_LAYER_BASE_RIGHT
#define ARTSEY_STD_LAYER_NUM ARTSEY_STD_LAYER_NUM_RIGHT
#define ARTSEY_STD_LAYER_SYM ARTSEY_STD_LAYER_SYM_RIGHT
#define ARTSEY_STD_LAYER_PAR ARTSEY_STD_LAYER_PAR_RIGHT
#define ARTSEY_STD_LAYER_NAV ARTSEY_STD_LAYER_NAV_RIGHT
#define ARTSEY_STD_LAYER_CUS ARTSEY_STD_LAYER_CUS_RIGHT
#endif
#endif

// Allow proper auto selection of big size via keymaps
#ifdef ARTSEY_SIZE_BIG
// Allow proper auto selection of left / right via keymaps
#ifdef ARTSEY_HAND_LEFT
#define ARTSEY_BIG_LAYER_BASE ARTSEY_BIG_LAYER_BASE_LEFT
#define ARTSEY_BIG_LAYER_NUM ARTSEY_BIG_LAYER_NUM_LEFT
#define ARTSEY_BIG_LAYER_SYM ARTSEY_BIG_LAYER_SYM_LEFT
#define ARTSEY_BIG_LAYER_PAR ARTSEY_BIG_LAYER_PAR_LEFT
#define ARTSEY_BIG_LAYER_NAV ARTSEY_BIG_LAYER_NAV_LEFT
#define ARTSEY_BIG_LAYER_CUS ARTSEY_BIG_LAYER_CUS_LEFT
#define ARTSEY_BIG_LAYER_BIG_SYM ARTSEY_BIG_LAYER_BIG_SYM_LEFT
#define ARTSEY_BIG_LAYER_BIG_FUN ARTSEY_BIG_LAYER_BIG_FUN_LEFT

#endif
#ifdef ARTSEY_HAND_RIGHT
#define ARTSEY_BIG_LAYER_BASE ARTSEY_BIG_LAYER_BASE_RIGHT
#define ARTSEY_BIG_LAYER_NUM ARTSEY_BIG_LAYER_NUM_RIGHT
#define ARTSEY_BIG_LAYER_SYM ARTSEY_BIG_LAYER_SYM_RIGHT
#define ARTSEY_BIG_LAYER_PAR ARTSEY_BIG_LAYER_PAR_RIGHT
#define ARTSEY_BIG_LAYER_NAV ARTSEY_BIG_LAYER_NAV_RIGHT
#define ARTSEY_BIG_LAYER_CUS ARTSEY_BIG_LAYER_CUS_RIGHT
#define ARTSEY_BIG_LAYER_BIG_SYM ARTSEY_BIG_LAYER_BIG_SYM_RIGHT
#define ARTSEY_BIG_LAYER_BIG_FUN ARTSEY_BIG_LAYER_BIG_FUN_RIGHT
#endif
#endif