## Building
1. Go into zmk/ directory
2. Activate the venv `source ./.venv/bin/activate`
3. `cd app`
4. Run

```bash
west build -b rpi_pico -- -DSHIELD=grazkb -DZMK_EXTRA_MODULES=/Users/graziano/code/zmk-config-grazkb/
```
