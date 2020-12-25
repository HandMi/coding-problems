cc_library(
    name = "AOC20_10_1",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "AOC20_10_1_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//AdventOfCode/2020/10/1:AOC20_10_1",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "AOC20_10_1_bin",
    deps = [
        "//AdventOfCode/2020/10/1:AOC20_10_1",
    ],
)
