#include "cargs.h"
int opt_verbose = 0;

void optprint(int argc, const char** argv) {
    printf("Print: %s\n", argv[0]);
}

void optverbose(int argc, const char** argv) {
    opt_verbose = 1;
    printf("Enable verbose mode\n");
}

void normal(int argc, const char** argv) {
    if (opt_verbose) {
        printf("args:\n");
        for (int i = 0; i < argc; i++) {
            printf("- %s\n", argv[i]);
        }
    }

    printf("Work done\n");
}

int main(int argc, const char** argv) {
    struct cargs* args = cargs_init(argc, argv);

    cargs_option(args, "p:print", 1, optprint, 0);
    cargs_option(args, "v:verbose", 0, optverbose, 0); 
    cargs_args(args, normal);
    cargs_run(args);
    cargs_close(args);
}