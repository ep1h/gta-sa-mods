/**
 * @file aimbot.h
 * @brief Provides API for the aimbot component.
 */
#ifndef AIMBOT_H
#define AIMBOT_H

#include <stdbool.h>

/**
 * @brief Initializes the aimbot component.
 *
 * @return True if the component was initialized successfully, false otherwise.
 */
bool aimbot_init(void);

/**
 * @brief Destroys the aimbot component.
 *
 * @return True if the component was destroyed successfully, false otherwise.
 */
bool aimbot_destroy(void);

#endif /* AIMBOT_H */
