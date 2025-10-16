# wrapper timer library around the posix timers

Creating a wrapper timer library around the POSIX timer API is a great way to simplify usage, enforce best practices, and make your code more portable and maintainable.

Below is an explanation and example design of such a wrapper.
## Why Make a Wrapper?

    Hide the complexity of POSIX timer setup (sigevent, itimerspec, etc.)
    Provide easy-to-use functions for creating, starting, stopping, and deleting timers.
    Allow callbacks with user data (using sival_ptr or sival_int).
    Optionally, add error handling, logging, or thread-safe features.

## Design Your API

Decide what your users should be able to do. Typical functions:

    timer_create_wrapper() — create a timer, set callback and interval.
    timer_start_wrapper() — start or arm the timer.
    timer_stop_wrapper() — stop the timer.
    timer_delete_wrapper() — delete the timer.
    Support for both one-shot and periodic timers.

### SIGEV_THREAD-based wrapper (callback runs in a thread)
The examples in this folder