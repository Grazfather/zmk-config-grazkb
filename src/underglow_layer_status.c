#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <zmk/event_manager.h>
#include <zmk/events/layer_state_changed.h>
#include <zmk/keymap.h>
#include <zmk/rgb_underglow.h>

/* Change the underglow hue whenever the active layer changes. */
static const struct zmk_led_hsb layer_colors[] = {
    [0] = {.h = 240, .s = 100, .b = 50}, /* Base      - blue   */
    [1] = {.h = 120, .s = 100, .b = 50}, /* Symbol    - red    */
    [2] = {.h = 0, .s = 100, .b = 50},   /* Layer sel - green  */
    [3] = {.h = 60, .s = 100, .b = 50},  /* QWERTY    - yellow */
    [4] = {.h = 180, .s = 100, .b = 50}, /* Mouse     - purple */
};

static void set_layer_color(void) {
  uint8_t layer = zmk_keymap_highest_layer_active();

  if (layer < ARRAY_SIZE(layer_colors)) {
    zmk_rgb_underglow_set_hsb(layer_colors[layer]);
  }
}

static int underglow_layer_status_listener(const zmk_event_t *eh) {
  set_layer_color();
  return ZMK_EV_EVENT_BUBBLE;
}

ZMK_LISTENER(underglow_layer_status, underglow_layer_status_listener);
ZMK_SUBSCRIPTION(underglow_layer_status, zmk_layer_state_changed);

static void underglow_init_work_cb(struct k_work *work) {
  zmk_rgb_underglow_on();
  set_layer_color();
}

static K_WORK_DELAYABLE_DEFINE(underglow_init_work, underglow_init_work_cb);

static int underglow_layer_status_init(void) {
  k_work_schedule(&underglow_init_work, K_MSEC(100));
  return 0;
}

SYS_INIT(underglow_layer_status_init, APPLICATION, 99);
