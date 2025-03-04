## Building
1. Go into zmk/ directory
2. Activate the venv `source ./.venv/bin/activate`
3. `cd app`
4. Run

```bash
west build -p -b rpi_pico -- -DSHIELD="grazkb" -DZMK_EXTRA_MODULES=/Users/graziano/code/zmk-config-grazkb/
west build -p -b rpi_pico -- -DSHIELD="display_test" -DZMK_EXTRA_MODULES=/Users/graziano/code/zmk-config-grazkb/
```
