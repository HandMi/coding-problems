cc_library(
    name = "CF20C",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF20C_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF20C",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF20C_bin",
    deps = [
        "//Codeforces/CF20C",
    ],
)
