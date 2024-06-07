## Building
1. Go into zmk/app directory
2. Activate the venv
3. Run `west build  -b rpi_pico -d build/grazkb -- -DSHIELD=grazkb -DZMK_EXTRA_MODULES=/path/to/zmk-config-grazkb/ -DSHIELD="grazkb"`
