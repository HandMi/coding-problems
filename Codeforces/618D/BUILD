cc_library(
    name = "618D",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "618D_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//618D",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "618D_exe",
    deps = [
        "//618D",
    ],
)