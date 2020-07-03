cc_library(
    name = "chapter01",
    srcs = ["chapter01.c"],
    hdrs = ["chapter01.h"],
    deps = [
    ],
)

cc_test(
    name = "chapter01_test",
    srcs = ["chapter01_test.c"],
    deps = [
        "@unity//:unity",
        ":chapter01",
        "//log:log",
    ],
)
