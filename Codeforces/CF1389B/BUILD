cc_library(
    name = "CF1389B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1389B_test",
    srcs = glob(["test/*.cpp"]),
    data = glob(["data/*.txt"]),
    deps = [
        "//Codeforces/CF1389B",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "CF1389B_bin",
    deps = [
        "//Codeforces/CF1389B",
    ],
)
