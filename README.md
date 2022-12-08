# qlocky
Timer that could turn into a task manager in the future.
This application was created as a practice in the Qt Framework.

## How to build
Run the following commands in terminal:
```bash
cmake -DCMAKE_BUILD_TYPE=Release . -B build/
cmake --build build/
```

## TODO's list
- Task list
- Bind a timer to a specific task
- Ability to work in the background with minimizing to the system tray
- Autostart
- Maintaining statistics (the ability to save time captured by the timer)
- Presentation of graphs based on collected statistics
