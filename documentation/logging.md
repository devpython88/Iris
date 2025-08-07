## iris/iris_logging.h > LogService

Iris provides a Logging system with the format like this
`<time> >> <level> >> <text>`

All functions in `LogService` are static so no constructor needed:

`log(std::string level, std::string text, Args... args)`: Prints a log with the level and formatted text, The args is what replaces placeholders such as `%d`, `%s`

`info(std::string text, Args... args)`: info log
`error(std::string text, Args... args)`: error log
`warning(std::string text, Args... args)`: warning log
