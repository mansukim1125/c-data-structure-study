cc_binary(
    name = "week4_main",
    srcs = ["week4_main.cc"],
    copts = [
        "-Werror",
        "-Wall",
    ],
)

cc_library(
    name = "week4",
    srcs = ["week4.c"],
    hdrs = [
        "week4.h",
    ],
)

cc_test(
    name = "week4_test",
    srcs = [
        "week4_test.c",
    ],
    deps = [
        ":week4",
        "@unity",
    ],
)

