cc_library(
    name = "CF1418C",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1418C_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF1418C",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "CF1418C_bin",
    deps = [
        "//Codeforces/CF1418C",
    ],
)