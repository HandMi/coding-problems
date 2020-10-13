cc_library(
    name = "CF1244C",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1244C_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF1244C",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "CF1244C_bin",
    deps = [
        "//Codeforces/CF1244C",
    ],
)