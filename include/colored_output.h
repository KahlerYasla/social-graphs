#ifndef COLORED_OUTPUT_H
#define COLORED_OUTPUT_H

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"

#define ANSI_COLOR_RESET "\x1b[0m"

#define LogRed(str) printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, (str))
#define LogGreen(str) printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, (str))
#define LogYellow(str) printf(ANSI_COLOR_YELLOW "%s" ANSI_COLOR_RESET, (str))
#define LogBlue(str) printf(ANSI_COLOR_BLUE "%s" ANSI_COLOR_RESET, (str))
#define LogMagenta(str) printf(ANSI_COLOR_MAGENTA "%s" ANSI_COLOR_RESET, (str))
#define LogCyan(str) printf(ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET, (str))

#endif // COLORED_OUTPUT_H