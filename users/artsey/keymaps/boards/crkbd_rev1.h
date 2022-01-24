// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#pragma once

#ifdef ARTSEY_HAND_LEFT
#define BIG_LEADING_NONES
#define BIG_BETWEEN_ROW_ONE_TWO_NONES KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
#define BIG_BETWEEN_ROW_TWO_THREE_NONES KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
#define BIG_BETWEEN_ROW_THREE_THUMBS KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
#define BIG_TRAILING_NONES , KC_NO, KC_NO, KC_NO
#endif

#ifdef ARTSEY_HAND_RIGHT
#define BIG_LEADING_NONES KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
#define BIG_BETWEEN_ROW_ONE_TWO_NONES KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
#define BIG_BETWEEN_ROW_TWO_THREE_NONES KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
#define BIG_BETWEEN_ROW_THREE_THUMBS KC_NO, KC_NO, KC_NO,
#define BIG_TRAILING_NONES
#endif
