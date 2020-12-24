cc_library(
    name = "NestingDepth",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CJ_NestingDepth_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//CodeJam/NestingDepth",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CJ_NestingDepth_bin",
    deps = [
        "//CodeJam/NestingDepth",
    ],
)
