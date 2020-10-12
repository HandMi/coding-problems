cc_library(
    name = "1418C",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "1418C_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/1418C",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "1418C_bin",
    deps = [
        "//Codeforces/1418C",
    ],
)