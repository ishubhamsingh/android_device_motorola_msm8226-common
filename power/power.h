/*
 * Copyright (C) 2015 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

enum {
    PROFILE_POWER_SAVE = 0,
    PROFILE_BALANCED,
    PROFILE_HIGH_PERFORMANCE,
    PROFILE_BIAS_POWER_SAVE,
    PROFILE_MAX
};

typedef struct governor_settings {
    int is_interactive;
    int boost;
    int boostpulse_duration;
    int go_hispeed_load;
    int go_hispeed_load_off;
    int hispeed_freq;
    int hispeed_freq_off;
    int io_is_busy;
    int min_sample_time;
    int sampling_down_factor;
    char *target_loads;
    char *target_loads_off;
    int scaling_max_freq;
    int scaling_min_freq;
    int scaling_min_freq_off;
} power_profile;

static power_profile profiles[PROFILE_MAX] = {
    [PROFILE_POWER_SAVE] = {
        .boost = 0,
        .boostpulse_duration = 0,
        .go_hispeed_load = 90,
        .go_hispeed_load_off = 90,
        .hispeed_freq = 787200,
        .hispeed_freq_off = 787200,
        .io_is_busy = 0,
        .min_sample_time = 60000,
        .sampling_down_factor = 100000,
        .target_loads = "95 1190400:99",
        .target_loads_off = "95 1190400:99",
        .scaling_max_freq = 787200,
        .scaling_min_freq = 300000,
        .scaling_min_freq_off = 300000,
    },
    [PROFILE_BALANCED] = {
        .boost = 0,
        .boostpulse_duration = 60000,
        .go_hispeed_load = 50,
        .go_hispeed_load_off = 90,
        .hispeed_freq = 998400,
        .hispeed_freq_off = 787200,
        .io_is_busy = 1,
        .min_sample_time = 60000,
        .sampling_down_factor = 100000,
        .target_loads = "80 998400:90 1190400:99",
        .target_loads_off = "95 1190400:99",
        .scaling_max_freq = 1190400,
        .scaling_min_freq = 787200,
        .scaling_min_freq_off = 300000,
    },
    [PROFILE_HIGH_PERFORMANCE] = {
        .boost = 1,
        /* The CPU is already boosted, set duration to zero
         * to avoid unneccessary writes to boostpulse */
        .boostpulse_duration = 0,
        .go_hispeed_load = 50,
        .go_hispeed_load_off = 50,
        .hispeed_freq = 998400,
        .hispeed_freq_off = 998400,
        .io_is_busy = 1,
        .min_sample_time = 60000,
        .sampling_down_factor = 100000,
        .target_loads = "80",
        .target_loads_off = "80",
        .scaling_max_freq = 1190400,
        .scaling_min_freq = 787200,
        .scaling_min_freq_off = 300000,
    },
    [PROFILE_BIAS_POWER_SAVE] = {
        .boost = 0,
        .boostpulse_duration = 0,
        .go_hispeed_load = 90,
        .go_hispeed_load_off = 90,
        .hispeed_freq = 787200,
        .hispeed_freq_off = 787200,
        .io_is_busy = 0,
        .min_sample_time = 60000,
        .sampling_down_factor = 100000,
        .target_loads = "95 1190400:99",
        .target_loads_off = "95 1190400:99",
        .scaling_max_freq = 1190400,
        .scaling_min_freq = 787200,
        .scaling_min_freq_off = 300000,
    },
};
